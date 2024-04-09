/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QWidget *Widget;
    QComboBox *bDeviceList;
    QPushButton *bRefresh;
    QLabel *Label_2;
    QWidget *Widget_2;
    QLineEdit *tApkFile;
    QPushButton *bBrowse;
    QPushButton *bInstall;
    QLabel *lbLog;
    QPushButton *bPush;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(360, 360);
        MainWindow->setMinimumSize(QSize(360, 360));
        MainWindow->setMaximumSize(QSize(360, 360));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(MainWindow);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 20, 311, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName("Label");

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        Widget = new QWidget(formLayoutWidget);
        Widget->setObjectName("Widget");
        Widget->setMinimumSize(QSize(0, 23));
        bDeviceList = new QComboBox(Widget);
        bDeviceList->setObjectName("bDeviceList");
        bDeviceList->setGeometry(QRect(0, 0, 180, 22));
        bRefresh = new QPushButton(Widget);
        bRefresh->setObjectName("bRefresh");
        bRefresh->setGeometry(QRect(190, 0, 60, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, Widget);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName("Label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        Widget_2 = new QWidget(formLayoutWidget);
        Widget_2->setObjectName("Widget_2");
        Widget_2->setMinimumSize(QSize(0, 23));
        tApkFile = new QLineEdit(Widget_2);
        tApkFile->setObjectName("tApkFile");
        tApkFile->setGeometry(QRect(0, 0, 181, 21));
        bBrowse = new QPushButton(Widget_2);
        bBrowse->setObjectName("bBrowse");
        bBrowse->setGeometry(QRect(190, 0, 60, 23));

        formLayout->setWidget(1, QFormLayout::FieldRole, Widget_2);

        bInstall = new QPushButton(MainWindow);
        bInstall->setObjectName("bInstall");
        bInstall->setGeometry(QRect(70, 110, 91, 31));
        lbLog = new QLabel(MainWindow);
        lbLog->setObjectName("lbLog");
        lbLog->setGeometry(QRect(20, 150, 311, 191));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbLog->sizePolicy().hasHeightForWidth());
        lbLog->setSizePolicy(sizePolicy);
        lbLog->setStyleSheet(QString::fromUtf8(""));
        lbLog->setFrameShape(QFrame::Shape::Box);
        lbLog->setFrameShadow(QFrame::Shadow::Plain);
        lbLog->setLineWidth(1);
        lbLog->setTextFormat(Qt::TextFormat::PlainText);
        lbLog->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        lbLog->setWordWrap(true);
        bPush = new QPushButton(MainWindow);
        bPush->setObjectName("bPush");
        bPush->setGeometry(QRect(180, 110, 91, 31));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\211\345\215\223\345\212\251\346\211\213", nullptr));
        MainWindow->setProperty("hello", QVariant(QCoreApplication::translate("MainWindow", "test", nullptr)));
        Label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        bRefresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        Label_2->setText(QCoreApplication::translate("MainWindow", "\345\256\211\350\243\205\346\226\207\344\273\266", nullptr));
        bBrowse->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        bInstall->setText(QCoreApplication::translate("MainWindow", "\345\256\211\350\243\205", nullptr));
        lbLog->setText(QString());
        lbLog->setProperty("hello", QVariant(QCoreApplication::translate("MainWindow", "1234", nullptr)));
        bPush->setText(QCoreApplication::translate("MainWindow", "\346\216\250\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
