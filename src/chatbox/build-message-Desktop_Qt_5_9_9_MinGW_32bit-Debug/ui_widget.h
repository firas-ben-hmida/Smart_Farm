/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nickname;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *message;
    QPushButton *send;
    QPushButton *bind;

    void setupUi(QDialog *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(447, 516);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 431, 501));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nickname = new QLineEdit(layoutWidget);
        nickname->setObjectName(QStringLiteral("nickname"));

        horizontalLayout_2->addWidget(nickname);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        message = new QLineEdit(layoutWidget);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout->addWidget(message);

        send = new QPushButton(layoutWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	font: 12pt \"MV Boli\";\n"
"    background-color: #87c834;\n"
"    border: 1px solid #ffffff;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"    padding: 8px 16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #6CAD83;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(send);

        bind = new QPushButton(layoutWidget);
        bind->setObjectName(QStringLiteral("bind"));
        bind->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	font: 12pt \"MV Boli\";\n"
"    background-color: #87c834;\n"
"    border: 1px solid #ffffff;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"    padding: 8px 16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #6CAD83;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(bind);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QDialog *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "Chat", Q_NULLPTR));
        label->setText(QApplication::translate("widget", "Your_Name  :", Q_NULLPTR));
        label_2->setText(QApplication::translate("widget", "Message :", Q_NULLPTR));
        send->setText(QApplication::translate("widget", "Envoyer ", Q_NULLPTR));
        bind->setText(QApplication::translate("widget", "Connecter ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
