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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *tab_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QLabel *label_6;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QComboBox *comboBox;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QWidget *page_4;
    QMenuBar *menubar;
    QMenu *menu_Y;
    QMenu *menu_Z;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1127, 627);
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
        tableWidget->setGeometry(QRect(11, 39, 821, 311));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 10, 261, 20));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);\n"
"border-color: rgb(13, 13, 13);"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(11, 359, 821, 201));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(489, -201, 241, 301));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
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
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(11, 9, 821, 20));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        label_6->setFrameShadow(QFrame::Raised);
        stackedWidget_2 = new QStackedWidget(centralwidget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(840, 260, 281, 291));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        comboBox_2 = new QComboBox(page_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(122, 123, 87, 21));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(61, 129, 53, 16));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(61, 49, 53, 63));
        doubleSpinBox = new QDoubleSpinBox(page_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(122, 83, 66, 21));
        comboBox = new QComboBox(page_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(122, 43, 121, 21));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(41, 169, 75, 17));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(2, 9, 271, 20));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 210, 121, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/21161/Downloads/b6e8520c5c986ce240d59824a0e9c89b.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(21, 89, 95, 16));
        comboBox_3 = new QComboBox(page_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(122, 163, 111, 21));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 210, 121, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/21161/Downloads/bf9e346b5483aba4aebe5b8b5f13d53a.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_2->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1127, 26));
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

        tabWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\243\200\346\237\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\351\242\204\350\247\210", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\345\255\220\346\226\207\344\273\266\345\244\271", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#f8f8f8;\">Check the file you want to delete</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\347\274\223  \345\255\230\357\274\232</p><p><br/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\226\271  \346\263\225\357\274\232</p><p><br/></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\211\253\346\217\217\347\273\223\346\236\234\357\274\232</p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600; color:#fdfdfd;\">\346\211\253\346\217\217</span></p></body></html>", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\211\253\346\217\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Similarity\357\274\232", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", " \345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        menu_Y->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&Y)", nullptr));
        menu_Z->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&Z)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
