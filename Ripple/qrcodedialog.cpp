#include "qrcodedialog.h"
#include "ui_qrcodedialog.h"
#include "qzxing.h"  // Include the QZXing library header

#include <QPixmap>
#include <QDebug>

QrCodeDialog::QrCodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QrCodeDialog)
{
    ui->setupUi(this);
    qrCodeLabel = new QLabel(this);
    qrCodeLabel->setScaledContents(true);
    ui->verticalLayout->addWidget(qrCodeLabel);  // Assuming verticalLayout is your main layout
}

QrCodeDialog::~QrCodeDialog()
{
    delete ui;
}

QPixmap QrCodeDialog::generateQRCode(const QString& data)
{
    QImage qrImage = QZXing::encodeData(data);
    if (qrImage.isNull()) {
        qDebug() << "Failed to generate QR code.";
        return QPixmap();  // Return an empty QPixmap
    }

    QPixmap pixmap = QPixmap::fromImage(qrImage);
    return pixmap;
}

void QrCodeDialog::setQrCodeImage(const QPixmap &image)
{
    qrCodeLabel->setPixmap(image);
    qrCodeLabel->setFixedSize(image.size());
}
