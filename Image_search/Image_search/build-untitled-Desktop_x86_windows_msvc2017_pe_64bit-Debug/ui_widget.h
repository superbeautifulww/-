/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *mainLINEedit;
    QPushButton *delete_2;
    QPushButton *clear;
    QPushButton *dot;
    QPushButton *equal;
    QPushButton *sin;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *add;
    QPushButton *cos;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *sub;
    QPushButton *tan;
    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *mul;
    QPushButton *sqrt;
    QPushButton *zero;
    QPushButton *left;
    QPushButton *right;
    QPushButton *div;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(274, 294);
        Widget->setMinimumSize(QSize(274, 294));
        Widget->setMaximumSize(QSize(274, 294));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 252, 277));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mainLINEedit = new QLineEdit(layoutWidget);
        mainLINEedit->setObjectName(QString::fromUtf8("mainLINEedit"));
        mainLINEedit->setMinimumSize(QSize(250, 40));
        mainLINEedit->setMaximumSize(QSize(250, 40));

        gridLayout->addWidget(mainLINEedit, 0, 0, 1, 5);

        delete_2 = new QPushButton(layoutWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setMinimumSize(QSize(60, 40));
        delete_2->setMaximumSize(QSize(60, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        delete_2->setFont(font);

        gridLayout->addWidget(delete_2, 1, 0, 1, 1);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setMinimumSize(QSize(40, 40));
        clear->setMaximumSize(QSize(40, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        clear->setFont(font1);

        gridLayout->addWidget(clear, 1, 1, 1, 1);

        dot = new QPushButton(layoutWidget);
        dot->setObjectName(QString::fromUtf8("dot"));
        dot->setMinimumSize(QSize(40, 40));
        dot->setMaximumSize(QSize(40, 40));
        dot->setFont(font1);

        gridLayout->addWidget(dot, 1, 2, 1, 1);

        equal = new QPushButton(layoutWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setMinimumSize(QSize(85, 40));
        equal->setMaximumSize(QSize(85, 40));
        equal->setFont(font1);

        gridLayout->addWidget(equal, 1, 3, 1, 2);

        sin = new QPushButton(layoutWidget);
        sin->setObjectName(QString::fromUtf8("sin"));
        sin->setMinimumSize(QSize(60, 40));
        sin->setMaximumSize(QSize(60, 40));
        sin->setFont(font1);

        gridLayout->addWidget(sin, 2, 0, 1, 1);

        seven = new QPushButton(layoutWidget);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setMinimumSize(QSize(40, 40));
        seven->setMaximumSize(QSize(40, 40));
        seven->setFont(font1);

        gridLayout->addWidget(seven, 2, 1, 1, 1);

        eight = new QPushButton(layoutWidget);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setMinimumSize(QSize(40, 40));
        eight->setMaximumSize(QSize(40, 40));
        eight->setFont(font1);

        gridLayout->addWidget(eight, 2, 2, 1, 1);

        nine = new QPushButton(layoutWidget);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setMinimumSize(QSize(40, 40));
        nine->setMaximumSize(QSize(40, 40));
        nine->setFont(font1);

        gridLayout->addWidget(nine, 2, 3, 1, 1);

        add = new QPushButton(layoutWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setMinimumSize(QSize(40, 40));
        add->setMaximumSize(QSize(40, 40));
        add->setFont(font1);

        gridLayout->addWidget(add, 2, 4, 1, 1);

        cos = new QPushButton(layoutWidget);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setMinimumSize(QSize(60, 40));
        cos->setMaximumSize(QSize(60, 40));
        cos->setFont(font1);

        gridLayout->addWidget(cos, 3, 0, 1, 1);

        four = new QPushButton(layoutWidget);
        four->setObjectName(QString::fromUtf8("four"));
        four->setMinimumSize(QSize(40, 40));
        four->setMaximumSize(QSize(40, 40));
        four->setFont(font1);

        gridLayout->addWidget(four, 3, 1, 1, 1);

        five = new QPushButton(layoutWidget);
        five->setObjectName(QString::fromUtf8("five"));
        five->setMinimumSize(QSize(40, 40));
        five->setMaximumSize(QSize(40, 40));
        five->setFont(font1);

        gridLayout->addWidget(five, 3, 2, 1, 1);

        six = new QPushButton(layoutWidget);
        six->setObjectName(QString::fromUtf8("six"));
        six->setMinimumSize(QSize(40, 40));
        six->setMaximumSize(QSize(40, 40));
        six->setFont(font1);

        gridLayout->addWidget(six, 3, 3, 1, 1);

        sub = new QPushButton(layoutWidget);
        sub->setObjectName(QString::fromUtf8("sub"));
        sub->setMinimumSize(QSize(40, 40));
        sub->setMaximumSize(QSize(40, 40));
        sub->setFont(font1);

        gridLayout->addWidget(sub, 3, 4, 1, 1);

        tan = new QPushButton(layoutWidget);
        tan->setObjectName(QString::fromUtf8("tan"));
        tan->setMinimumSize(QSize(60, 40));
        tan->setMaximumSize(QSize(60, 40));
        tan->setFont(font1);

        gridLayout->addWidget(tan, 4, 0, 1, 1);

        one = new QPushButton(layoutWidget);
        one->setObjectName(QString::fromUtf8("one"));
        one->setMinimumSize(QSize(40, 40));
        one->setMaximumSize(QSize(40, 40));
        one->setFont(font1);

        gridLayout->addWidget(one, 4, 1, 1, 1);

        two = new QPushButton(layoutWidget);
        two->setObjectName(QString::fromUtf8("two"));
        two->setMinimumSize(QSize(40, 40));
        two->setMaximumSize(QSize(40, 40));
        two->setFont(font1);

        gridLayout->addWidget(two, 4, 2, 1, 1);

        three = new QPushButton(layoutWidget);
        three->setObjectName(QString::fromUtf8("three"));
        three->setMinimumSize(QSize(40, 40));
        three->setMaximumSize(QSize(40, 40));
        three->setFont(font1);

        gridLayout->addWidget(three, 4, 3, 1, 1);

        mul = new QPushButton(layoutWidget);
        mul->setObjectName(QString::fromUtf8("mul"));
        mul->setMinimumSize(QSize(40, 40));
        mul->setMaximumSize(QSize(40, 40));
        mul->setFont(font1);

        gridLayout->addWidget(mul, 4, 4, 1, 1);

        sqrt = new QPushButton(layoutWidget);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));
        sqrt->setMinimumSize(QSize(60, 40));
        sqrt->setMaximumSize(QSize(60, 40));
        sqrt->setFont(font1);

        gridLayout->addWidget(sqrt, 5, 0, 1, 1);

        zero = new QPushButton(layoutWidget);
        zero->setObjectName(QString::fromUtf8("zero"));
        zero->setMinimumSize(QSize(40, 40));
        zero->setMaximumSize(QSize(40, 40));
        zero->setFont(font1);

        gridLayout->addWidget(zero, 5, 1, 1, 1);

        left = new QPushButton(layoutWidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setMinimumSize(QSize(40, 40));
        left->setMaximumSize(QSize(40, 40));
        left->setFont(font1);

        gridLayout->addWidget(left, 5, 2, 1, 1);

        right = new QPushButton(layoutWidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setMinimumSize(QSize(40, 40));
        right->setMaximumSize(QSize(40, 40));
        right->setFont(font1);

        gridLayout->addWidget(right, 5, 3, 1, 1);

        div = new QPushButton(layoutWidget);
        div->setObjectName(QString::fromUtf8("div"));
        div->setMinimumSize(QSize(40, 40));
        div->setMaximumSize(QSize(40, 40));
        div->setFont(font1);

        gridLayout->addWidget(div, 5, 4, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        delete_2->setText(QApplication::translate("Widget", "\342\206\222", nullptr));
        clear->setText(QApplication::translate("Widget", "C", nullptr));
        dot->setText(QApplication::translate("Widget", ".", nullptr));
        equal->setText(QApplication::translate("Widget", "=", nullptr));
        sin->setText(QApplication::translate("Widget", "sin", nullptr));
        seven->setText(QApplication::translate("Widget", "7", nullptr));
        eight->setText(QApplication::translate("Widget", "8", nullptr));
        nine->setText(QApplication::translate("Widget", "9", nullptr));
        add->setText(QApplication::translate("Widget", "+", nullptr));
        cos->setText(QApplication::translate("Widget", "cos", nullptr));
        four->setText(QApplication::translate("Widget", "4", nullptr));
        five->setText(QApplication::translate("Widget", "5", nullptr));
        six->setText(QApplication::translate("Widget", "6", nullptr));
        sub->setText(QApplication::translate("Widget", "-", nullptr));
        tan->setText(QApplication::translate("Widget", "tan", nullptr));
        one->setText(QApplication::translate("Widget", "1", nullptr));
        two->setText(QApplication::translate("Widget", "2", nullptr));
        three->setText(QApplication::translate("Widget", "3", nullptr));
        mul->setText(QApplication::translate("Widget", "*", nullptr));
        sqrt->setText(QApplication::translate("Widget", "sqrt", nullptr));
        zero->setText(QApplication::translate("Widget", "0", nullptr));
        left->setText(QApplication::translate("Widget", "\357\274\210", nullptr));
        right->setText(QApplication::translate("Widget", "\357\274\211", nullptr));
        div->setText(QApplication::translate("Widget", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
