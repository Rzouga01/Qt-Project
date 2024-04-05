#include "client.h"

#include "ui_client.h"

//DATABASE CONNECTION
#include "sqlConn.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

//GENERAL LIBRARIES
#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <Qpushbutton>

//PDF
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableFormat>
#include <QTextCharFormat>
#include <QTextLength>
#include <QTextFrameFormat>
#include <QPageSize>
#include <QFont>


//STATS
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QBoxLayout>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QToolTip>
#include <QCursor>


//QR CODE
#include "QZXing.h"
#include <QImage>
#include <QPixmap>
#include <QByteArray>
#include <QLabel>
#include "qrcodedialog.h"


//EMAIL
#include <QTcpSocket>
#include <QTextStream>
#include <QDataStream>
#include <QByteArray>
#include <QBuffer>



Client::Client(QWidget* parent) :
    QDialog(parent),
    dob(QDate::currentDate()),
    ui(new Ui::Client),
    tableClient(nullptr),
    stackedClient(nullptr)
{
    ui->setupUi(this);


}

Client::Client(QTableWidget *tableWidget, QStackedWidget* stackedWidget ,QWidget *parent)
    : QDialog(parent), ui(new Ui::Client), tableClient(tableWidget), stackedClient(stackedWidget)

{
    ui->setupUi(this);
}

Client::Client(QTableWidget* tableWidget,QWidget* parent)
    : QDialog(parent), ui(new Ui::Client), tableClient(tableWidget)
{
    ui->setupUi(this);
}

void Client::setStackedWidget(QStackedWidget* stackedWidget)
{
	stackedClient = stackedWidget;
}

void Client::setTableWidget(QTableWidget *tableWidget)

{
    tableClient = tableWidget;
}


Client::~Client()
{
    delete ui;
}



Client::Client(const QString& email, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob)
{
   setEmail(email);
   setFirstName(first_name);
   setLastName(last_name);
   setPhoneNumber(phone_number);
   setAddress(address);
   setDob(dob);

}


bool Client::CreateClient()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO CLIENTS (EMAIL, FIRST_NAME, LAST_NAME, ADDRESS, PHONE_NUMBER, DOB) VALUES (:email, :first_name, :last_name, :address, :phone_number, :dob)");
    qry.bindValue(":email", this->email);
    qry.bindValue(":first_name", this->first_name);
    qry.bindValue(":last_name", this->last_name);
    qry.bindValue(":phone_number", this->phone_number);
    qry.bindValue(":address", this->address);
    qry.bindValue(":dob", this->dob);

    if (qry.exec())
    {
        // Retrieve the ID of the last inserted record

        qDebug() << "Client saved successfully." << "Data:" <<
            "\nEmail :" << this->email <<
            "\nFirst Name :" << this->first_name <<
            "\nLast Name :" << this->last_name <<
            "\nPhone Number :" << this->phone_number <<
            "\nAddress :" << this->address <<
            "\nDate of Birth :" << this->dob.toString();
        return true;
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}

bool Client::CreateClient(QString email,QString first_name,QString last_name,QString phone_number,QString address,QDate dob)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO CLIENTS (EMAIL, FIRST_NAME, LAST_NAME, ADDRESS, PHONE_NUMBER, DOB) VALUES (:email, :first_name, :last_name, :address, :phone_number, :dob)");
    qry.bindValue(":email", email);
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":phone_number", phone_number);
    qry.bindValue(":address", address);
    qry.bindValue(":dob", dob);

    if (qry.exec())
    {

        qDebug() << "Client saved successfully." << "Data:" <<
            "\nEmail :" << email <<
            "\nFirst Name :" << first_name <<
            "\nLast Name :" << last_name <<
            "\nPhone Number :" << phone_number <<
            "\nAddress :" << address <<
            "\nDate of Birth :" << dob.toString();
        return true;
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}




bool Client::DeleteClient(int id)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", id);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("DELETE FROM CLIENTS WHERE CLIENT_ID = :id");
            qry.bindValue(":id", id);
            if (qry.exec())
            {
                qDebug() << "Client found. Deleting...";
                return true;
            }
            else
            {
                qDebug() << "Error executing query:" << qry.lastError().text();
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
                return false;
            }
        }
        else
        {
            qDebug() << "Client not found.";
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}


/*void Client::ReadClient() {
    if (tableClient == nullptr) {
        qDebug() << "Error: tableClient is null";
        return;
    }

    if (stackedClient == nullptr) {
        qDebug() << "Error: stackedClient is null";
        return;
    }

    tableClient->clearContents();
    tableClient->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (qry.exec()) {
        while (qry.next()) {
            int row = tableClient->rowCount();
            tableClient->insertRow(row);

            // Set data items for each column
            for (int col = 0; col < 6; ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(qry.value(col).toString());
                tableClient->setItem(row, col, item);
            }

            // Set date
            QTableWidgetItem* dateItem = new QTableWidgetItem(qry.value(6).toDate().toString());
            tableClient->setItem(row, 6, dateItem);

            // Add delete button
            QPushButton* deleteButton = new QPushButton("Delete");
            connect(deleteButton, &QPushButton::clicked, [this, row]() {
                int clientId = tableClient->item(row, 0)->text().toInt();
                stackedClient->setCurrentIndex(2); // Assuming the index of the delete page is 1
                });
            tableClient->setCellWidget(row, 7, deleteButton); // Assuming delete button is in column 7

            // Add update button
            QPushButton* updateButton = new QPushButton("Update");
            connect(updateButton, &QPushButton::clicked, [this, row]() {
                // Handle the update button click event here
                // You may want to open a dialog for updating client information
                });
            tableClient->setCellWidget(row, 8, updateButton); // Assuming update button is in column 8
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}*/


void Client::ReadClient()
{
    if (tableClient == nullptr) {
        qDebug() << "Error: tableClient is null";
        return;
    }

    tableClient->clearContents();
    tableClient->setRowCount(0); 

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (qry.exec())
    {
        while (qry.next())
        {
            int row = tableClient->rowCount();
            tableClient->insertRow(row);


            tableClient->setRowHeight(row, 50);
            tableClient->setFont(QFont("Helvetica", 10));
            tableClient->setColumnWidth(0, 10);//ID
            tableClient->setColumnWidth(1, 150);//EMAIL
            tableClient->setColumnWidth(2, 100);//FIRST NAME
            tableClient->setColumnWidth(3, 100);//LAST NAME
            tableClient->setColumnWidth(4, 100);//ADDRESS
            tableClient->setColumnWidth(5, 75);//PHONE NUMBER
            tableClient->setColumnWidth(6, 100);//DOB

            tableClient->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableClient->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableClient->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableClient->setItem(row, 3, new QTableWidgetItem(qry.value(3).toString()));
            tableClient->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableClient->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableClient->setItem(row, 6, new QTableWidgetItem(qry.value(6).toDate().toString()));
        }
        tableClient->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


/*void Client::ReadClient()
{
    tableClient->clearContents();
    tableClient->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (qry.exec())
    {
        while (qry.next())
        {
            int row = tableClient->rowCount();
            tableClient->insertRow(row);

            // Set data items for each column
            for (int col = 0; col < 6; ++col)
            {
                QTableWidgetItem* item = new QTableWidgetItem(qry.value(col).toString());
                tableClient->setItem(row, col, item);
            }

            // Set date
            QTableWidgetItem* dateItem = new QTableWidgetItem(qry.value(6).toDate().toString());
            tableClient->setItem(row, 6, dateItem);

            // Add delete button
            QPushButton* deleteButton = new QPushButton("Delete");
            connect(deleteButton, &QPushButton::clicked, [this, row]() {
                int clientId = tableClient->item(row, 0)->text().toInt();
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this client?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if (DeleteClient(clientId))
                    {
                        tableClient->removeRow(row);
                    }
                }
                });
            tableClient->setCellWidget(row, 7, deleteButton); // Assuming delete button is in column 7

            // Add update button
            QPushButton* updateButton = new QPushButton("Update");
            connect(updateButton, &QPushButton::clicked, [this, row]() {
                // Handle the update button click event here
                // You may want to open a dialog for updating client information
                });
            tableClient->setCellWidget(row, 8, updateButton); // Assuming update button is in column 8
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}*/





bool Client::UpdateClient(int clientID, const Client& NewClient)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", clientID);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("UPDATE CLIENTS SET EMAIL = :email, FIRST_NAME = :first_name, LAST_NAME = :last_name, ADDRESS = :address, PHONE_NUMBER = :phone_number, DOB = TO_DATE(:dob, 'YYYY-MM-DD') WHERE CLIENT_ID = :id");
            qry.bindValue(":id", clientID);
            qry.bindValue(":email", NewClient.getEmail());
            qry.bindValue(":first_name", NewClient.getFirstName());
            qry.bindValue(":last_name", NewClient.getLastName());
            qry.bindValue(":phone_number", NewClient.getPhoneNumber());
            qry.bindValue(":address", NewClient.getAddress());
            qry.bindValue(":dob", NewClient.getDob().toString("yyyy-MM-dd")); // Ensure the date format matches 'YYYY-MM-DD'

            if (qry.exec())
            {
                qDebug() << "Client Updated successfully." << "Data:" <<
                    "\nEmail :" << NewClient.getEmail() <<
                    "\nFirst Name :" << NewClient.getFirstName() <<
                    "\nLast Name :" << NewClient.getLastName() <<
                    "\nPhone Number :" << NewClient.getPhoneNumber() <<
                    "\nAddress :" << NewClient.getAddress() <<
                    "\nDate of Birth :" << NewClient.getDob().toString(Qt::ISODate);
                return true;
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
                return false;
            }
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Client not found"));
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}

bool Client::UpdateClient(int clientID, QString email, QString first_name, QString last_name, QString phone_number, QString address, QDate dob)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", clientID);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("UPDATE CLIENTS SET EMAIL = :email, FIRST_NAME = :first_name, LAST_NAME = :last_name, ADDRESS = :address, PHONE_NUMBER = :phone_number, DOB = TO_DATE(:dob, 'YYYY-MM-DD') WHERE CLIENT_ID = :id");
            qry.bindValue(":id", clientID);
            qry.bindValue(":email", email);
            qry.bindValue(":first_name", first_name);
            qry.bindValue(":last_name", last_name);
            qry.bindValue(":phone_number", phone_number);
            qry.bindValue(":address", address);
            qry.bindValue(":dob", dob.toString("yyyy-MM-dd")); // Convert QDate to string in the 'YYYY-MM-DD' format

            if (qry.exec())
            {
                qDebug() << "Client Updated successfully." << "Data:" <<
                    "\nEmail :" << email <<
                    "\nFirst Name :" << first_name <<
                    "\nLast Name :" << last_name <<
                    "\nPhone Number :" << phone_number <<
                    "\nAddress :" << address <<
                    "\nDate of Birth :" << dob.toString("yyyy-MM-dd");
                return true;
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
                return false;
            }
        }
        else
        {
            QMessageBox::critical(nullptr, tr("Error"), tr("Client not found")); // As this is not part of a QDialog, pass nullptr
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
        return false;
    }
}


void Client::toPdf(const QString& filePath)
{
    qDebug() << "Exporting client data to PDF:" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "File path is empty.";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QTextDocument doc;
    QTextCursor cursor(&doc);

    cursor.insertHtml("<h1 style='text-align: center; color: #A7C34E; font-size: 24px;'>Clients List</h1><br>");

    int numCols = qry.record().count();

    if (numCols == 0) {
        qDebug() << "Empty result set. No data to export.";
        return;
    }

    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setHeaderRowCount(1);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 95));
    tableFormat.setCellPadding(8);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);

    QTextCharFormat headerFormat;
    headerFormat.setBackground(QColor("#C0C0C0"));
    headerFormat.setForeground(Qt::black);
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setFontPointSize(12);

    QTextCharFormat dataFormat;
    dataFormat.setFontPointSize(10);
    dataFormat.setForeground(Qt::black); // Set text color to black

    QTextTable* table = cursor.insertTable(1, numCols, tableFormat);
    if (!table) {
        qDebug() << "Error creating table.";
        return;
    }

    // Insert column headers
    for (int col = 0; col < numCols; ++col) {
        QTextCursor cellCursor = table->cellAt(0, col).firstCursorPosition();
        cellCursor.setCharFormat(headerFormat);
        cellCursor.insertText(qry.record().fieldName(col));
    }

    int row = 1; // Start from row 1 to skip the header row
    while (qry.next()) {
        table->appendRows(1); // Append a new row
        for (int col = 0; col < numCols; ++col) {
            QTextCursor cellCursor = table->cellAt(row, col).firstCursorPosition();
            cellCursor.setCharFormat(dataFormat);
            cellCursor.insertText(qry.value(col).toString());
        }
        ++row;
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::Letter));
    pdfWriter.setResolution(150);

    QPainter painter(&pdfWriter);
    painter.begin(&pdfWriter);

    doc.drawContents(&painter);

    painter.end();

    qDebug() << "PDF file successfully created:" << filePath;
    QMessageBox::information(nullptr, "Export Successful", "Client Data has been successfully exported to PDF.\nFile saved to: " + filePath);
}








void Client::sortClientFirstName(bool ascendingOrder)
{
    QString sortOrder = ascendingOrder ? "ASC" : "DESC";

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS ORDER BY FIRST_NAME " + sortOrder);
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching sorted data...";

    // Clear the existing table contents
    tableClient->clearContents();
    tableClient->setRowCount(0);

    int row = 0;
    while (qry.next()) {
        int col = 0;
        tableClient->insertRow(row);

        tableClient->setRowHeight(row, 50);
        tableClient->setFont(QFont("Helvetica", 10));
        tableClient->setColumnWidth(0, 10);//ID
        tableClient->setColumnWidth(1, 150);//EMAIL
        tableClient->setColumnWidth(2, 100);//FIRST NAME
        tableClient->setColumnWidth(3, 100);//LAST NAME
        tableClient->setColumnWidth(4, 100);//ADDRESS
        tableClient->setColumnWidth(5, 75);//PHONE NUMBER
        tableClient->setColumnWidth(6, 100);//DOB


        // Set data items for each column
        QTableWidgetItem* idItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* emailItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* firstNameItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* lastNameItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* phoneNumberItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* addressItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* dobItem = new QTableWidgetItem(qry.value(col++).toDate().toString());

        tableClient->setItem(row, 0, idItem);
        tableClient->setItem(row, 1, emailItem);
        tableClient->setItem(row, 2, firstNameItem);
        tableClient->setItem(row, 3, lastNameItem);
        tableClient->setItem(row, 4, phoneNumberItem);
        tableClient->setItem(row, 5, addressItem);
        tableClient->setItem(row, 6, dobItem);

        ++row;
    }
    tableClient->repaint();

    qDebug() << "Client data sorted by first name in" << sortOrder << "order.";
}





void Client::searchClientID(QString search, QString searchBy) {
    QSqlQuery qry;
    QString queryString = "SELECT ID, EMAIL, FIRST_NAME, LAST_NAME, PHONE_NUMBER, ADDRESS, DOB FROM CLIENTS";


    if (search.isEmpty()) {
        queryString = "SELECT * FROM CLIENTS";
    } else {
        queryString = "SELECT * FROM CLIENTS WHERE UPPER(" + searchBy + ") LIKE UPPER(:id)";
    }

    qry.prepare(queryString);
    if (!search.isEmpty()) {
        qry.bindValue(":id", "%" + search + "%");
    }

    if (qry.exec()) {
        tableClient->clearContents();
        tableClient->setRowCount(0);

        int row = 0;
        while (qry.next()) {
            tableClient->insertRow(row);
            int col = 0;

            // Set data items for each column
            QTableWidgetItem* idItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* emailItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* firstNameItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* lastNameItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* phoneNumberItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* addressItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* dobItem = new QTableWidgetItem(qry.value(col++).toDate().toString());

            tableClient->setRowHeight(row, 50);
            tableClient->setFont(QFont("Helvetica", 10));
            tableClient->setColumnWidth(0, 10);//ID
            tableClient->setColumnWidth(1, 150);//EMAIL
            tableClient->setColumnWidth(2, 100);//FIRST NAME
            tableClient->setColumnWidth(3, 100);//LAST NAME
            tableClient->setColumnWidth(4, 100);//ADDRESS
            tableClient->setColumnWidth(5, 75);//PHONE NUMBER
            tableClient->setColumnWidth(6, 100);//DOB

            tableClient->setItem(row, 0, idItem);
            tableClient->setItem(row, 1, emailItem);
            tableClient->setItem(row, 2, firstNameItem);
            tableClient->setItem(row, 3, lastNameItem);
            tableClient->setItem(row, 4, phoneNumberItem);
            tableClient->setItem(row, 5, addressItem);
            tableClient->setItem(row, 6, dobItem);

            ++row;
        }
        tableClient->repaint();

        if (row == 0) {
            qDebug() << "Client not found.";
            // Display a message or update UI to indicate no results found
        }
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
        // Handle error, display message, or log it
    }
}


void Client::statsByAge()
{
    QSqlQuery qry;
    qry.prepare("SELECT AGE_GROUP, COUNT(*) AS CLIENT_COUNT \
                 FROM ( \
                     SELECT CASE \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 10 AND EXTRACT(YEAR FROM CURRENT_DATE) THEN '0-10' \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 18 AND EXTRACT(YEAR FROM CURRENT_DATE) - 11 THEN '11-18' \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 25 AND EXTRACT(YEAR FROM CURRENT_DATE) - 19 THEN '19-25' \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 35 AND EXTRACT(YEAR FROM CURRENT_DATE) - 26 THEN '26-35' \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 55 AND EXTRACT(YEAR FROM CURRENT_DATE) - 36 THEN '36-55' \
                             WHEN EXTRACT(YEAR FROM DOB) BETWEEN EXTRACT(YEAR FROM CURRENT_DATE) - 70 AND EXTRACT(YEAR FROM CURRENT_DATE) - 56 THEN '56-70' \
                             ELSE '70+' \
                         END AS AGE_GROUP \
                     FROM CLIENTS \
                 ) AgeGroups \
                 GROUP BY AGE_GROUP \
                 ORDER BY AGE_GROUP");

    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QPieSeries *pieSeries = new QPieSeries();

    while (qry.next()) {
        QString ageGroup = qry.value(0).toString();
        int clientCount = qry.value(1).toInt();

        // Create a pie slice with label text indicating age group and client count
        QPieSlice *slice = new QPieSlice(QString("%1: %2").arg(ageGroup).arg(clientCount), clientCount);
        pieSeries->append(slice);
    }

    QChart *chart = new QChart();
    chart->addSeries(pieSeries);
    chart->setTitle("Clients by Age Group");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Handle hover events for slices
    QObject::connect(pieSeries, &QPieSeries::hovered, [chartView](QPieSlice *slice, bool state) {
        if (state) {
            slice->setExploded(true);
            slice->setLabelVisible(true);
        } else {
            slice->setExploded(false);
            slice->setLabelVisible(false);
        }
        chartView->update();
    });
    chartView->setMinimumSize(800, 600);
    chartView->show();

}



void Client::generateQRCode(const QString& data)
{
    QrCodeDialog qrCodeDialog;

    QImage qrImage = QZXing::encodeData(data);
    if (qrImage.isNull()) {
        qDebug() << "Failed to Generate QR code.";
        QMessageBox::critical(this, tr("Error"), tr("Failed to Generate QR Code."), QMessageBox::Ok);
        return;
    }

    qDebug()<<qrImage.size();

    QPixmap pixmap = QPixmap::fromImage(qrImage);

    qrCodeDialog.setQrCodeImage(pixmap);
    qrCodeDialog.exec();

    qDebug() << "QR Code Generated Successfully.";
}

QByteArray Client::getQRCodeData(const QString& data)
{
    QImage qrImage = QZXing::encodeData(data);
    if (qrImage.isNull()) {
        qDebug() << "Failed to Generate QR code.";
        return QByteArray(); // Return an empty QByteArray if QR code generation fails
    }

    // Convert QR code image to QByteArray
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    qrImage.save(&buffer, "PNG");

    return imageData;
}






