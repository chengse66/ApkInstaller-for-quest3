//
// Created by DO on 2024/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Setup();
}

MainWindow::~MainWindow() {
    thread->terminate();
    delete thread;
    delete ui;
}

void MainWindow::Setup() {
    thread = new AdbThread();
    connect(thread, &AdbThread::onStart, this, &MainWindow::onProcessStart);
    connect(thread, &AdbThread::onProgress, this, &MainWindow::onProcess);
    connect(thread, &AdbThread::onComplete, this, &MainWindow::onProcessComplete);
    connect(thread, &AdbThread::finished, thread, &QObject::deleteLater);
    thread->start();

    connect(ui->bRefresh, &QPushButton::clicked, this, [&] {
        RefreshDevices();
    });

    QString lastDir = QApplication::applicationDirPath();
    connect(ui->bBrowse, &QPushButton::clicked, this, [lastDir, this]() mutable {
        auto result = QFileDialog::getOpenFileName(nullptr, "打开APK文件", lastDir, "安卓文件(*.apk)");
        if (!result.isEmpty()) {
            lastDir = QFileInfo(result).absoluteDir().absolutePath();
            ui->tApkFile->setText(result);
        }
    });

    connect(ui->bInstall, &QPushButton::clicked, this, [this]() mutable {
        auto fileName = ui->tApkFile->text();
        if (!fileName.isEmpty()) {
            //install
            InstallApk(QFileInfo(fileName).absoluteFilePath());
        }
    });

    connect(ui->bPush,&QPushButton::clicked,this,[this,lastDir]{
        auto folder=QFileDialog::getExistingDirectory(nullptr,"选择一个目录",lastDir,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
        if(!folder.isEmpty()){
            PushOBB(folder);
        }
    });
    RefreshDevices();
}

void MainWindow::RefreshDevices() {
    ui->bRefresh->setEnabled(false);
    ui->bDeviceList->clear();
    Callback cb;
    cb.callback = [this](const QString &q) {
        QRegularExpression regex("(?<ID>\\w+)\\tdevice");
        auto match = regex.match(q);
        if (match.hasMatch()) {
            ui->bDeviceList->addItem(match.captured("ID"));
        }
        ui->bRefresh->setEnabled(true);
    };

    QStringList cmd;
    cmd.append("devices");
    cb.execute = [this, cmd]() mutable {
        OpenProcess(cmd);
    };
    thread->append(cb);
}

QStringList MainWindow::FormatCommand(QStringList _param) {
    QStringList cmd;
    if (ui->bDeviceList->count() > 0) {
        cmd.append("-s");
        cmd.append(ui->bDeviceList->currentText());
    }
    cmd.append(_param);
    return cmd;
}

void MainWindow::OpenProcess(const QStringList &cmd) {
    QProcess process;
    QStringList resultList;
    QString result;
    process.setWorkingDirectory(this->workDir);
    process.start("adb.exe", cmd);
    connect(&process, &QProcess::readyReadStandardOutput, [&] {
        while (process.canReadLine()) {
            auto bytes = process.readLine();
            thread->execute(QString::fromUtf8(bytes));
        }
    });
    if (process.waitForFinished(-1)) {}
    process.close();
    process.deleteLater();
}

void MainWindow::onProcessStart() {
    logText.clear();
    logText.append("-------------start----------\r\n");
    ui->lbLog->setText(logText);
}

void MainWindow::onProcessComplete() {
    logText.append("-------------end----------\r\n");
    ui->lbLog->setText(logText);
}

void MainWindow::onProcess(const QString &q, const CallbackFunc &callback) {
    logText.append(q);
    ui->lbLog->setText(logText);
    callback(q);
}

void MainWindow::InstallApk(const QString &q) {
    qDebug() << "Install " << q;
    //遍历目录下的所有问题
    QFileInfo file = QFileInfo(q);
    if (file.exists()) {
        //INSTALL APK,
        QStringList cmd_install= FormatCommand(QStringList()<<"install"<<"-r"<<file.absoluteFilePath());
        qDebug()<<cmd_install.join(" ");
        Callback c;
        c.callback=[](const QString &callback){
            qDebug()<<callback;
        };
        c.execute=[this,cmd_install](){
            OpenProcess(cmd_install);
        };
        thread->append(c);
    }
}

void MainWindow::PushOBB(const QString &q) {
    QDir folder=QDir(q);
    if(folder.exists()){
        auto copyDir=folder.absolutePath();
        QStringList cmd_copy=FormatCommand(QStringList()<<"push"<<copyDir<<"/sdcard/Android/obb/"+folder.dirName()+"/");
        qDebug()<<cmd_copy.join(" ");
        Callback c;
        c.callback=[](const QString &callback){
            qDebug()<<callback;
        };
        c.execute=[this,cmd_copy](){
            OpenProcess(cmd_copy);
        };
        thread->append(c);
    }
}
