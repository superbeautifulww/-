/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *choose_picture;
    QLabel *picture_show;
    QLabel *res_show;
    QLabel *start_histogram_show;
    QLabel *res_histogram_show;
    QPushButton *normalization_button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        choose_picture = new QPushButton(Widget);
        choose_picture->setObjectName("choose_picture");
        choose_picture->setGeometry(QRect(30, 10, 80, 24));
        picture_show = new QLabel(Widget);
        picture_show->setObjectName("picture_show");
        picture_show->setGeometry(QRect(30, 60, 256, 180));
        picture_show->setMinimumSize(QSize(256, 180));
        picture_show->setMaximumSize(QSize(256, 180));
        res_show = new QLabel(Widget);
        res_show->setObjectName("res_show");
        res_show->setGeometry(QRect(340, 70, 256, 180));
        res_show->setMinimumSize(QSize(256, 180));
        res_show->setMaximumSize(QSize(256, 180));
        start_histogram_show = new QLabel(Widget);
        start_histogram_show->setObjectName("start_histogram_show");
        start_histogram_show->setGeometry(QRect(30, 250, 256, 180));
        start_histogram_show->setMinimumSize(QSize(256, 180));
        start_histogram_show->setMaximumSize(QSize(256, 180));
        res_histogram_show = new QLabel(Widget);
        res_histogram_show->setObjectName("res_histogram_show");
        res_histogram_show->setGeometry(QRect(380, 270, 256, 180));
        res_histogram_show->setMinimumSize(QSize(256, 180));
        res_histogram_show->setMaximumSize(QSize(256, 180));
        normalization_button = new QPushButton(Widget);
        normalization_button->setObjectName("normalization_button");
        normalization_button->setGeometry(QRect(200, 10, 80, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        choose_picture->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        picture_show->setText(QString());
        res_show->setText(QString());
        start_histogram_show->setText(QString());
        res_histogram_show->setText(QString());
        normalization_button->setText(QCoreApplication::translate("Widget", "\347\233\264\346\226\271\345\233\276\345\275\222\344\270\200\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
