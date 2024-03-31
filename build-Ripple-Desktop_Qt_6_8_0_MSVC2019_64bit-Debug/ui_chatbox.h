/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QWidget *chatbox;
    QTextEdit *conversation;
    QLineEdit *messageBar;
    QPushButton *sendButton;
    QLabel *chat;
    QPushButton *voiceButton;
    QLabel *title;
    QLabel *poweredBy;

    void setupUi(QWidget *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName("window");
        window->resize(967, 524);
        chatbox = new QWidget(window);
        chatbox->setObjectName("chatbox");
        chatbox->setGeometry(QRect(-10, 0, 981, 531));
        chatbox->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #333333; /* Dark background color */\n"
"	color: #FFFFFF; /* White text color */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    border: 1px solid #A7C34E; /* Green border color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 15px;\n"
"    background-color: #222222; /* Dark background color */\n"
"    color: #FFFFFF; /* White text color */\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #A7C34E; /* Green border color */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #444444; /* Darker background color for disabled state */\n"
"    color: #A0A0A0; /* Light gray text color */\n"
"}\n"
"\n"
"QLineEdit:read-only {\n"
"    background-color: #444444; /* Darker background color for read-only state */\n"
"    color: #A0A0A0; /* Light gray text color */\n"
"}\n"
"\n"
"QLineEdit::hover {\n"
"    border: 1px solid #A7C34E; /* Green border color */\n"
"}\n"
"\n"
"QLineEdit::selected {\n"
"    background-color: #A7C34E; /* Green background color for "
                        "selected text */\n"
"    color: #FFFFFF; /* White text color */\n"
"}\n"
"\n"
"QTextEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #A7C34E, stop:1 #A7C34E); /* Green gradient border */\n"
"    border-radius: 12px;\n"
"    background-color: #222222; /* Dark background color */\n"
"    color: #FFFFFF; /* White text color */\n"
"}\n"
"\n"
"QPushButton {\n"
"    border: 1px solid #A7C34E; /* Green border color */\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
"    background: #A7C34E; /* Dark background color */\n"
"    color: #A7C34E; /* Green text color */\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A7C34E; /* Green background color on hover */\n"
"	color: #FFFFFF; /* White text color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #A7C34E; /* Green background color when pressed */\n"
"    border: 2px solid #A7C34E; /* Green border color when pressed */\n"
"    padding: 4px 14px 6px 16px;\n"
"}\n"
""
                        "\n"
"QPushButton:disabled {\n"
"    background: #444444; /* Darker background color for disabled state */\n"
"    color: #A0A0A0; /* Light gray text color */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background: #A7C34E; /* Green background color when checked */\n"
"    color: #FFFFFF; /* White text color when checked */\n"
"}\n"
""));
        conversation = new QTextEdit(chatbox);
        conversation->setObjectName("conversation");
        conversation->setEnabled(true);
        conversation->setGeometry(QRect(63, 102, 851, 281));
        conversation->setStyleSheet(QString::fromUtf8(""));
        conversation->setReadOnly(true);
        messageBar = new QLineEdit(chatbox);
        messageBar->setObjectName("messageBar");
        messageBar->setGeometry(QRect(120, 430, 681, 41));
        sendButton = new QPushButton(chatbox);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(890, 440, 31, 31));
        sendButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon);
        chat = new QLabel(chatbox);
        chat->setObjectName("chat");
        chat->setGeometry(QRect(61, 118, 851, 281));
        chat->setAutoFillBackground(false);
        chat->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        chat->setScaledContents(true);
        voiceButton = new QPushButton(chatbox);
        voiceButton->setObjectName("voiceButton");
        voiceButton->setGeometry(QRect(830, 440, 31, 31));
        voiceButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Resources/Icons/microphone.png"), QSize(), QIcon::Normal, QIcon::Off);
        voiceButton->setIcon(icon1);
        voiceButton->setCheckable(true);
        voiceButton->setChecked(false);
        title = new QLabel(chatbox);
        title->setObjectName("title");
        title->setGeometry(QRect(60, 40, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(18);
        font.setBold(true);
        title->setFont(font);
        poweredBy = new QLabel(chatbox);
        poweredBy->setObjectName("poweredBy");
        poweredBy->setGeometry(QRect(770, 70, 181, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans SemiBold")});
        font1.setBold(true);
        poweredBy->setFont(font1);

        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QWidget *window)
    {
        window->setWindowTitle(QCoreApplication::translate("window", "Form", nullptr));
        messageBar->setPlaceholderText(QCoreApplication::translate("window", "Your message...", nullptr));
        sendButton->setText(QString());
        chat->setText(QString());
        voiceButton->setText(QString());
        title->setText(QCoreApplication::translate("window", "ChatBot", nullptr));
        poweredBy->setText(QCoreApplication::translate("window", "Powered by Google Gemini", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
