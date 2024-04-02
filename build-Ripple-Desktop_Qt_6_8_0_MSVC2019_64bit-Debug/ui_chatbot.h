/********************************************************************************
** Form generated from reading UI file 'chatbot.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOT_H
#define UI_CHATBOT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatbot
{
public:
    QWidget *chatbox;
    QTextEdit *conversation;
    QLineEdit *messageBar;
    QPushButton *sendButton;
    QPushButton *voiceButton;
    QLabel *title;
    QLabel *poweredBy;
    QListWidget *chat;

    void setupUi(QDialog *chatbot)
    {
        if (chatbot->objectName().isEmpty())
            chatbot->setObjectName("chatbot");
        chatbot->resize(1000, 500);
        chatbox = new QWidget(chatbot);
        chatbox->setObjectName("chatbox");
        chatbox->setGeometry(QRect(0, 0, 1000, 500));
        chatbox->setStyleSheet(QString::fromUtf8("QWidget{\n"
"        background-color: #333333; /* Dark background color */\n"
"        color: #FFFFFF; /* White text color */\n"
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
"    background-color: #A7C34E; /* Green backgro"
                        "und color for selected text */\n"
"    color: #FFFFFF; /* White text color */\n"
"}\n"
"QListWidget{\n"
"background-color:transparent;\n"
"border:none;\n"
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
"        color: #FFFFFF; /* White text color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #A7C34E; /* Green background color when pressed */\n"
"    border: 2px soli"
                        "d #A7C34E; /* Green border color when pressed */\n"
"    padding: 4px 14px 6px 16px;\n"
"}\n"
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
        conversation->setGeometry(QRect(23, 102, 951, 281));
        conversation->setReadOnly(true);
        messageBar = new QLineEdit(chatbox);
        messageBar->setObjectName("messageBar");
        messageBar->setGeometry(QRect(110, 390, 681, 41));
        sendButton = new QPushButton(chatbox);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(900, 390, 50, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon);
        voiceButton = new QPushButton(chatbox);
        voiceButton->setObjectName("voiceButton");
        voiceButton->setGeometry(QRect(820, 390, 50, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Resources/Icons/microphone.png"), QSize(), QIcon::Normal, QIcon::Off);
        voiceButton->setIcon(icon1);
        voiceButton->setCheckable(true);
        voiceButton->setChecked(false);
        title = new QLabel(chatbox);
        title->setObjectName("title");
        title->setGeometry(QRect(410, 20, 311, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(30);
        font.setBold(true);
        title->setFont(font);
        poweredBy = new QLabel(chatbox);
        poweredBy->setObjectName("poweredBy");
        poweredBy->setGeometry(QRect(820, 70, 181, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans SemiBold")});
        font1.setBold(true);
        poweredBy->setFont(font1);
        chat = new QListWidget(chatbox);
        chat->setObjectName("chat");
        chat->setGeometry(QRect(10, 111, 951, 261));

        retranslateUi(chatbot);

        QMetaObject::connectSlotsByName(chatbot);
    } // setupUi

    void retranslateUi(QDialog *chatbot)
    {
        chatbot->setWindowTitle(QCoreApplication::translate("chatbot", "Chat bot for employees", nullptr));
        messageBar->setPlaceholderText(QCoreApplication::translate("chatbot", "Your message...", nullptr));
        sendButton->setText(QString());
        voiceButton->setText(QString());
        title->setText(QCoreApplication::translate("chatbot", "ChatBot", nullptr));
        poweredBy->setText(QCoreApplication::translate("chatbot", "Powered by Google Gemini", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatbot: public Ui_chatbot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOT_H
