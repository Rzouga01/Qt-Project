#ifndef QRCODEDIALOG_H
#define QRCODEDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class QrCodeDialog;
}

class QrCodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QrCodeDialog(QWidget *parent = nullptr);
    ~QrCodeDialog();

    // Function to set the QR code image
    void setQrCodeImage(const QPixmap &image);
    QPixmap generateQRCode(const QString& data);

private:
    Ui::QrCodeDialog *ui;
    QLabel *qrCodeLabel;
};

#endif // QRCODEDIALOG_H
