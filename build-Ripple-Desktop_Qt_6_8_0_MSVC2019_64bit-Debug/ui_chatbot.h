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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatbot
{
public:
    QWidget *chatbox;
    QLabel *title;
    QLabel *poweredBy;
    QScrollArea *chat;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *chatContainer;
    QFrame *messageBar;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QLabel *RecordingIndicator;
    QPushButton *voiceButton;
    QListWidget *histroy;

    void setupUi(QDialog *chatbot)
    {
        if (chatbot->objectName().isEmpty())
            chatbot->setObjectName("chatbot");
        chatbot->resize(1200, 600);
        chatbox = new QWidget(chatbot);
        chatbox->setObjectName("chatbox");
        chatbox->setGeometry(QRect(-100, 0, 1301, 601));
        chatbox->setStyleSheet(QString::fromUtf8("QWidget{\n"
"        background-color: #222222;\n"
"        color: #FFFFFF;\n"
"	\n"
"}\n"
"QFrame{\n"
"   border: 1px solid #A7C34E;\n"
"    border-radius: 5px;\n"
"    background-color: #222222;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color:transparent;\n"
"border:none;\n"
"}\n"
"\n"
"QLineEdit {\n"
"        border:none;\n"
"    padding: 5px 15px;\n"
"    background-color: #222222;\n"
"    color: #FFFFFF;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/*Scroll bar*/\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #333333;\n"
"    width: 14px;\n"
"    margin: 15px 0 15px 0;\n"
"    border-radius: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #A7C34E, stop:1 #9AB447);\n"
"    min-height: 30px;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #A7"
                        "C34E, stop:1 #5D762E);\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #A7C34E, stop:1 #3A511F);\n"
"}\n"
"\n"
"/* BTN TOP - SCROLLBAR */\n"
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #9AB447, stop:1 #A7C34E);\n"
"    height: 15px;\n"
"    border-top-left-radius: 7px;\n"
"    border-top-right-radius: 7px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #5D762E, stop:1 #A7C34E);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #3A511F, stop:1 #A7C34E);\n"
"}\n"
"\n"
""
                        "/* BTN BOTTOM - SCROLLBAR */\n"
"QScrollBar::add-line:vertical {\n"
"    border: none;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #9AB447, stop:1 #A7C34E);\n"
"    height: 15px;\n"
"    border-bottom-left-radius: 7px;\n"
"    border-bottom-right-radius: 7px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #5D762E, stop:1 #A7C34E);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                      stop:0 #3A511F, stop:1 #A7C34E);\n"
"}\n"
"QPushButton {\n"
"    border: 1px solid #A7C34E;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
"    background: #A7C34E;\n"
"    color: #A7C34E;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
""
                        "    background-color: #A7C34E;\n"
"        color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #A7C34E;\n"
"    border: 2px solid #A7C34E;\n"
"    padding: 4px 14px 6px 16px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background: #444444;\n"
"    color: #A0A0A0;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background: #A7C34E;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        title = new QLabel(chatbox);
        title->setObjectName("title");
        title->setGeometry(QRect(150, -10, 281, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(20);
        font.setBold(true);
        title->setFont(font);
        poweredBy = new QLabel(chatbox);
        poweredBy->setObjectName("poweredBy");
        poweredBy->setGeometry(QRect(120, 570, 221, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans SemiBold")});
        font1.setBold(true);
        poweredBy->setFont(font1);
        chat = new QScrollArea(chatbox);
        chat->setObjectName("chat");
        chat->setGeometry(QRect(400, 40, 871, 481));
        chat->setStyleSheet(QString::fromUtf8("	border:none;"));
        chat->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        chat->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 871, 481));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        chatContainer = new QWidget(scrollAreaWidgetContents);
        chatContainer->setObjectName("chatContainer");

        verticalLayout->addWidget(chatContainer);

        chat->setWidget(scrollAreaWidgetContents);
        messageBar = new QFrame(chatbox);
        messageBar->setObjectName("messageBar");
        messageBar->setGeometry(QRect(437, 526, 831, 61));
        messageBar->setFrameShape(QFrame::Shape::StyledPanel);
        messageBar->setFrameShadow(QFrame::Shadow::Raised);
        messageInput = new QLineEdit(messageBar);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(10, 10, 641, 41));
        sendButton = new QPushButton(messageBar);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(770, 10, 50, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon);
        RecordingIndicator = new QLabel(messageBar);
        RecordingIndicator->setObjectName("RecordingIndicator");
        RecordingIndicator->setGeometry(QRect(660, -10, 81, 81));
        RecordingIndicator->setScaledContents(true);
        voiceButton = new QPushButton(messageBar);
        voiceButton->setObjectName("voiceButton");
        voiceButton->setGeometry(QRect(680, 10, 41, 41));
        voiceButton->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Resources/Icons/Untitled-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        voiceButton->setIcon(icon1);
        voiceButton->setIconSize(QSize(40, 40));
        voiceButton->setCheckable(true);
        voiceButton->setChecked(false);
        histroy = new QListWidget(chatbox);
        histroy->setObjectName("histroy");
        histroy->setGeometry(QRect(100, 1, 271, 601));
        histroy->setStyleSheet(QString::fromUtf8(" background-color:#333333;\n"
"    color: #FFFFFF; /* White text color */\n"
"        border:none;\n"
"border-radius:10px;\n"
""));
        histroy->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        histroy->raise();
        chat->raise();
        title->raise();
        poweredBy->raise();
        messageBar->raise();

        retranslateUi(chatbot);

        QMetaObject::connectSlotsByName(chatbot);
    } // setupUi

    void retranslateUi(QDialog *chatbot)
    {
        chatbot->setWindowTitle(QCoreApplication::translate("chatbot", "Chat bot for employees", nullptr));
        title->setText(QCoreApplication::translate("chatbot", "RippleAssist", nullptr));
        poweredBy->setText(QCoreApplication::translate("chatbot", "Powered by Google Gemini \302\251", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("chatbot", "Your message...", nullptr));
        sendButton->setText(QString());
        RecordingIndicator->setText(QString());
        voiceButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chatbot: public Ui_chatbot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOT_H
