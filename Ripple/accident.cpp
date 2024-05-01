#include "accident.h"
#include "ui_accident.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QSqlError>
#include <QTextTable>
#include <QTextCursor>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QSqlRecord>
#include <QHeaderView>





accident::accident(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::accident),
    tableAccident(nullptr)
{

    ui->setupUi(this);


}
accident::accident(QTableWidget* tablewidget, QWidget* parent) :
    QDialog(parent), ui(new Ui::accident), tableAccident(tablewidget) {
    ui->setupUi(this);
}


void accident::setTableWidget(QTableWidget* tableWidget)

{
    tableAccident = tableWidget;
}

accident::~accident()
{
    delete ui;
}

accident::accident()
{
    acc_id = -1;
    type = "";
    damage = 0;
    date = QDate::currentDate();
    location = "";
    client_id = -1;


}

accident::accident(QString type, int damage, QDate date, QString location, int client_id)
{

    this->type = type;
    this->damage = damage;
    this->date = date;
    this->location = location;
    this->client_id = client_id;
}

bool accident::create(QString type, int damage, QDate date, int location, int client_id)
{
    QSqlQuery query;

    query.prepare("INSERT INTO ACCIDENTS (TYPE,DAMAGE,ACCIDENT_DATE,LOCATION,CLIENT_ID) VALUES (:type, :damage,:date,:location,:client_id)");

    query.bindValue(":type", type);
    query.bindValue(":damage", damage);
    query.bindValue(":date", date);
    query.bindValue(":location", location);
    query.bindValue(":client_id", client_id);

    if (query.exec())
    {

        qDebug() << "Accident saved successfully." << "Data:" <<
            "\ntype :" << type <<
            "\ndamage :" << damage <<
            "\ndate :" << date.toString("yyyy-MM-dd") <<
            "\nlocation :" << location <<
            "\nclient_id :" << client_id;

        return true;
    }
    else
    {
        qDebug() << "Error Creating Accident query:" << query.lastError().text();
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
        return false;
    }
}

/*
 QSqlQueryModel* accident::read()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM ACCIDENTS");

  return  model;
}*/

void accident::accidentRead()
{
    if (tableAccident == nullptr) {
        qDebug() << "Error: tableClien is null";
        return;
    }

    tableAccident->clearContents();
    tableAccident->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM ACCIDENTS");
    if (qry.exec())
    {
        while (qry.next())
        {
            int row = tableAccident->rowCount();
            tableAccident->insertRow(row);

            tableAccident->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableAccident->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableAccident->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableAccident->setItem(row, 3, new QTableWidgetItem(qry.value(3).toString()));
            tableAccident->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableAccident->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableAccident->setItem(row, 6, new QTableWidgetItem(qry.value(6).toDate().toString()));
        }
        tableAccident->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


bool accident::Delete(int id) {
    QSqlQuery qry;
    qry.prepare("DELETE FROM ACCIDENTS WHERE ACCIDENT_ID = :acc_id");
    qry.bindValue(":acc_id", id);

    if (qry.exec()) {
        if (qry.numRowsAffected() > 0) {
            qDebug() << "Accident found and deleted.";
            return true;
        }
        else {
            qDebug() << "Accident not found.";
            return false;
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return false;
    }
}

void accident::update(int acc_id, QString type, int damage, QDate date, QString location, int client_id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ACCIDENTS WHERE ACCIDENT_ID = :acc_id");
    query.bindValue(":acc_id", acc_id);

    if (query.exec()) {
        qDebug() << "test";
        if (query.next()) {
            query.prepare("UPDATE ACCIDENTS SET TYPE=:type,DAMAGE=:damage,ACCIDENT_DATE=:date,LOCATION=:location,CLIENT_ID=:client_id WHERE ACCIDENT_ID=:acc_id");
            query.bindValue(":acc_id", acc_id);
            query.bindValue(":type", type);
            query.bindValue(":damage", damage);
            query.bindValue(":date", date);
            query.bindValue(":location", location);
            query.bindValue(":client_id", client_id);

            if (query.exec())
            {
                qDebug() << "accident Updated successfuly ." << "Data :" <<
                    "\nacc_id :" << acc_id <<
                    "\ntype :" << type <<
                    "\ndamage :" << damage <<
                    "\ndate :" << date.toString("yyyy-MM-dd") <<
                    "\nlocation :" << location <<
                    "\nclient_id :" << client_id;

            }
            else {
                qDebug() << "Error executing update query :" << query.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());

            }
        }
        else {
            QMessageBox::critical(nullptr, tr("Error"), tr("accident not found"));
        }

    }
    else {
        qDebug() << "Error executing select query:" << query.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());
    }
    /*  qDebug() << "Contract Updated successfuly ." << "Data :" <<
                "\nacc_id :" << acc_id <<
                  "\ntype :" <<type <<
               "\ndamage :" <<damage<<
                "\ndate :" <<date.toString("yyyy-MM-dd") <<
                "\nlocation :" <<location<<
                  "\nclient_id :" <<client_id;
      QSqlQuery query ;
      query.prepare("UPDATE ACCIDENTS SET TYPE=:type, DAMAGE =:damage,ACCIDENT_DATE= :accident_date,LOCATION= :location, CLIENT_ID= :client_id WHERE ACCIDENT_ID= :id");
      query.bindValue(":id",acc_id);
      query.bindValue(":type",type);
      query.bindValue(":damage",damage);
      query.bindValue(":accident_date",date.toString("yyyy-MM-dd"));
      query.bindValue(":location",location);
      query.bindValue(":client_id",client_id);
      query.exec();*/
}
void accident::sortAccidentByDamage(bool ascendingOrder)
{
    QString sortOrder = ascendingOrder ? "ASC" : "DESC";

    QSqlQuery qry;
    qry.prepare("SELECT * FROM accidents ORDER BY damage " + sortOrder);
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching sorted data...";

    // Clear the existing table contents
    tableAccident->clearContents();
    tableAccident->setRowCount(0);

    int row = 0;
    while (qry.next()) {
        int col = 0;
        tableAccident->insertRow(row);

        // Set data items for each column
        QTableWidgetItem* accidentIdItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* clientIdItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* typeItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* damageItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* DateItem = new QTableWidgetItem(qry.value(col++).toDate().toString());
        QTableWidgetItem* locationItem = new QTableWidgetItem(qry.value(col++).toString());

        // Set items to the table
        tableAccident->setItem(row, 0, accidentIdItem);
        tableAccident->setItem(row, 1, clientIdItem);
        tableAccident->setItem(row, 2, typeItem);
        tableAccident->setItem(row, 3, damageItem);
        tableAccident->setItem(row, 4, DateItem);
        tableAccident->setItem(row, 5, locationItem);

        ++row;
    }
    tableAccident->repaint();

    qDebug() << "Accident data sorted by damage in" << sortOrder << "order.";
}
void accident::AccidenttoPdf(const QString& filePath)
{
    qDebug() << "Exporting accident data to PDF:" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "File path is empty.";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM accidents");
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QTextDocument doc;
    QTextCursor cursor(&doc);

    cursor.insertHtml("<h1 style='text-align: center; color: #333333;'>Accidents List</h1><br>");

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

    QTextCharFormat altRowFormat;
    altRowFormat.setBackground(Qt::lightGray);

    int numCols = qry.record().count();


    QTextTable* table = cursor.insertTable(1, numCols, tableFormat);
    QTextCursor cellCursor = table->cellAt(0, 0).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("ID");

    cellCursor = table->cellAt(0, 1).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Client ID");

    cellCursor = table->cellAt(0, 2).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Type");

    cellCursor = table->cellAt(0, 3).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Damage");

    cellCursor = table->cellAt(0, 4).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Date");

    cellCursor = table->cellAt(0, 5).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Location");


    int row = 1;
    while (qry.next()) {
        table->appendRows(1);
        for (int col = 0; col < numCols; ++col) {
            QTextCursor cellCursor = table->cellAt(row, col).firstCursorPosition();
            QTextCharFormat dataFormat;
            dataFormat.setFontPointSize(10);
            if (row % 2 == 1) {
                dataFormat.setBackground(Qt::lightGray);
            }
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
    QMessageBox::information(nullptr, "Export Successful", "accident Data has been successfully exported to PDF.\nFile saved to: " + filePath);
}

void accident::searchAccident(const QString& search)
{
    if (tableAccident == nullptr) {
        qDebug() << "Error: tableAccident is null";
        return;
    }

    tableAccident->clearContents();
    tableAccident->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM accidents WHERE LOWER(LOCATION) LIKE LOWER(:search) ");
    qry.bindValue(":search", "%" + search + "%");

    if (qry.exec())
    {
        tableAccident->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        while (qry.next())
        {
            int row = tableAccident->rowCount();
            tableAccident->insertRow(row);

            tableAccident->setFont(QFont("Helvetica", 10));

            tableAccident->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableAccident->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableAccident->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableAccident->setItem(row, 3, new QTableWidgetItem(qry.value(3).toString()));
            tableAccident->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableAccident->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableAccident->setItem(row, 6, new QTableWidgetItem(qry.value(6).toDate().toString()));

        }

        tableAccident->resizeColumnsToContents();
        tableAccident->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableAccident->repaint();

        if (tableAccident->rowCount() == 0) {
            qDebug() << "No matching records found for search:" << search;
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();

    }
}
void accident::accidentstatsByDamage()
{
    QSqlQuery qry;
    qry.prepare("SELECT DAMAGE_GROUP, COUNT(*) AS ACCIDENT_COUNT \
                 FROM ( \
                     SELECT CASE \
                             WHEN DAMAGE BETWEEN 0 AND 3000 THEN '0-3000' \
                             WHEN DAMAGE BETWEEN 3001 AND 5000 THEN '3001-5000' \
                             ELSE '5001+' \
                         END AS DAMAGE_GROUP \
                     FROM ACCIDENTS \
                 ) DamageGroups \
                 GROUP BY DAMAGE_GROUP \
                 ORDER BY DAMAGE_GROUP");

    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QBarSeries *barSeries = new QBarSeries();

    while (qry.next()) {
        QString damageGroup = qry.value("DAMAGE_GROUP").toString();
        int accidentCount = qry.value("ACCIDENT_COUNT").toInt();

        // Create a bar set representing each damage category and its accident count
        QBarSet *barSet = new QBarSet(damageGroup);
        *barSet << accidentCount;
        barSeries->append(barSet);
    }

    QChart *chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Accidents by Damage Group");

    QStringList categories; // X-axis categories

    // Adding categories based on damage groups
    categories << "0-3000" << "3001-5000" << "5001+";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setMinimumSize(800, 600);
    chartView->show();
}
QSqlQuery accident::rechercherall()
{
    QSqlQuery query;
    query.prepare("SELECT * from accidents  ");

    return query;
}
void accident::logAccidentAction(const QString& action)
{
    QFile file("../historique.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QTextStream out(&file);
        out << "Action: " << action << "\n";
        out << "Time: " << QDate::currentDate().toString() << "\n\n";
        file.close();
    }
    else
    {
        qDebug() << "Erreur d'ouverture du fichier historique.txt";
    }
}


