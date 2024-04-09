//
// Created by DO on 2024/4/8.
//

#ifndef ANDROIDTOOLKIT_MAINWINDOW_H
#define ANDROIDTOOLKIT_MAINWINDOW_H

#include <QWidget>
#include <QProcess>
#include <QThread>
#include "AdbThread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onProcessStart();
    void onProcess(const QString &q,const CallbackFunc &callback);
    void onProcessComplete();

private:
    Ui::MainWindow *ui;
    QString workDir;
    QString logText;
    AdbThread *thread;

    /**
     * 初始化设置
     */
    void Setup();
    /**
     * 刷新设备列表
     */
    void RefreshDevices();
    /**
     * 推送OBB文件
     * @param q
     */
    void PushOBB(const QString &q);
    /**
     * 安装APK
     * @param q
     */
    void InstallApk(const QString &q);


    /**
     * 执行进程
     * @param cmd
     */
    void OpenProcess(const QStringList &cmd);

    /**
     * 格式化命令
     * @param _param
     * @return
     */

    QStringList FormatCommand(QStringList _param);
};


#endif //ANDROIDTOOLKIT_MAINWINDOW_H
