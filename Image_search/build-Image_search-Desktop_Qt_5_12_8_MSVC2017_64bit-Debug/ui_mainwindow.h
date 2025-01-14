/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Projrct;
    QAction *actionOpen_Project;
    QAction *actionSave;
    QAction *actionAdd;
    QAction *actionFilter;
    QAction *actionSearch;
    QAction *actionStart_Scan;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QSpinBox *spinBox;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QMenuBar *menubar;
    QMenu *menu_Y;
    QMenu *menu_Z;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1130, 631);
        MainWindow->setMinimumSize(QSize(1130, 631));
        MainWindow->setMaximumSize(QSize(1130, 631));
        actionNew_Projrct = new QAction(MainWindow);
        actionNew_Projrct->setObjectName(QString::fromUtf8("actionNew_Projrct"));
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionFilter = new QAction(MainWindow);
        actionFilter->setObjectName(QString::fromUtf8("actionFilter"));
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        actionStart_Scan = new QAction(MainWindow);
        actionStart_Scan->setObjectName(QString::fromUtf8("actionStart_Scan"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(11, 39, 821, 331));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 10, 261, 20));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);\n"
"border-color: rgb(13, 13, 13);"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(842, 36, 256, 141));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(851, 189, 111, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(981, 189, 111, 28));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(861, 229, 151, 19));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1000, 380, 111, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../../../../21161/Downloads/b6e8520c5c986ce240d59824a0e9c89b.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(951, 304, 141, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 310, 53, 16));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(850, 380, 111, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../../../../../21161/Downloads/bf9e346b5483aba4aebe5b8b5f13d53a.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(880, 340, 95, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(953, 271, 111, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(871, 271, 75, 16));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1070, 272, 31, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 390, 321, 201));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(980, 340, 71, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(470, 390, 321, 201));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 390, 41, 51));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(410, 390, 72, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1130, 26));
        menu_Y = new QMenu(menubar);
        menu_Y->setObjectName(QString::fromUtf8("menu_Y"));
        menu_Z = new QMenu(menubar);
        menu_Z->setObjectName(QString::fromUtf8("menu_Z"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Y->menuAction());
        menubar->addAction(menu_Z->menuAction());
        menu_Y->addAction(actionNew_Projrct);
        menu_Y->addAction(actionOpen_Project);
        menu_Y->addAction(actionSave);
        menu_Y->addAction(actionAdd);
        menu_Y->addAction(actionFilter);
        menu_Y->addAction(actionSearch);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Projrct->setText(QApplication::translate("MainWindow", "New ", nullptr));
        actionOpen_Project->setText(QApplication::translate("MainWindow", "Open ", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
        actionFilter->setText(QApplication::translate("MainWindow", "Filter", nullptr));
        actionSearch->setText(QApplication::translate("MainWindow", "Search", nullptr));
        actionStart_Scan->setText(QApplication::translate("MainWindow", "Start Scan", nullptr));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#f9f9f9;\"> \346\226\207\344\273\266\345\244\271</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\345\255\220\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\211\253\346\217\217", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Average Hash", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Color Distribution", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Perceptual Hash", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Different Hash", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\226\271  \346\263\225\357\274\232</p><p><br/></p></body></html>", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", " \345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Similarity\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\216\237\345\233\276\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\351\242\204\350\247\210</p><p>\345\216\237\345\233\276\357\274\232</p></body></html>", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\351\242\204\350\247\210</p><p>\347\233\270\344\274\274\345\233\276\357\274\232</p></body></html>", nullptr));
        menu_Y->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&Y)", nullptr));
        menu_Z->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&Z)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
