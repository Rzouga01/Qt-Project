#include "contract.h"
#include "ui_contract.h"
#include <QtDebug>
#include <QDate>
#include <QMessageBox>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QTextTable>
#include <QTextCursor>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QSqlRecord>
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
//#include "xlsxdocument.h"
contract::contract(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::contract),
	tableContract(nullptr),
	stackedContract(nullptr)
{
	ui->setupUi(this);
	EFFECTIVE_DATE = QDate::currentDate();
	EXPIRATION_DATE = QDate::currentDate();
}

contract::contract(QTableWidget* tableWidget, QStackedWidget* stackedWidget, QWidget* parent)
	: QDialog(parent), ui(new Ui::contract), tableContract(tableWidget), stackedContract(stackedWidget)
{
	ui->setupUi(this);
	EFFECTIVE_DATE = QDate::currentDate();
	EXPIRATION_DATE = QDate::currentDate();
}


void contract::setStackedWidget(QStackedWidget* stackedWidget) {
	stackedContract = stackedWidget;
}

void contract::setTableWidget(QTableWidget* tableWidget)
{
	tableContract = tableWidget;
}

contract::~contract()
{
	delete ui;
}


//Constructeur paramété
contract::contract(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
	this->USER_ID = USER_ID;
	this->CLIENT_ID = CLIENT_ID;
	this->PREMIUM_AMOUNT = PREMIUM_AMOUNT;
	this->EFFECTIVE_DATE = EFFECTIVE_DATE;
	this->EXPIRATION_DATE = EXPIRATION_DATE;
	this->PAYMENT_STATUS = PAYMENT_STATUS;
	this->TYPE = TYPE;
}
contract::contract() {
	CONTRACT_ID = -1;
	USER_ID = 0;
	CLIENT_ID = 0;
	PREMIUM_AMOUNT = 0;
	EFFECTIVE_DATE = QDate::currentDate();
	EXPIRATION_DATE = QDate::currentDate();
	PAYMENT_STATUS = 0;
	TYPE = "";


}

//fonction ajouter
bool contract::CreateContract(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
	QSqlQuery query;

	query.prepare("INSERT INTO CONTRACTS(USER_ID,CLIENT_ID,PREMIUM_AMOUNT,EFFECTIVE_DATE,EXPIRATION_DATE,PAYMENT_STATUS,TYPE) values( :USER_ID, :CLIENT_ID, :PREMIUM_AMOUNT, :EFFECTIVE_DATE, :EXPIRATION_DATE, :PAYMENT_STATUS, :TYPE)");

	query.bindValue(":USER_ID", USER_ID);
	query.bindValue(":CLIENT_ID", CLIENT_ID);
	query.bindValue(":PREMIUM_AMOUNT", PREMIUM_AMOUNT);
	query.bindValue(":EFFECTIVE_DATE", EFFECTIVE_DATE);
	query.bindValue(":EXPIRATION_DATE", EXPIRATION_DATE);
	query.bindValue(":PAYMENT_STATUS", PAYMENT_STATUS);
	query.bindValue(":TYPE", TYPE);

	if (query.exec()) {
		qDebug() << "Contract saved successfuly ." << "Data :" <<
			"\nuser_id :" << USER_ID <<
			"\nclient_id :" << CLIENT_ID <<
			"\npremium_amount :" << PREMIUM_AMOUNT <<
			"\neffective_date :" << EFFECTIVE_DATE.toString("yyyy-MM-dd") <<
			"\nexpiration_date :" << EXPIRATION_DATE.toString("yyyy-MM-dd") <<
			"\npayment_status :" << PAYMENT_STATUS <<
			"\ntype :" << TYPE;
		return true;
	}
	else {
		qDebug() << "Error Creating Contract query:" << query.lastError().text();
		QMessageBox::critical(this, tr("Error"), query.lastError().text());
		return false;
	}
}


// fonction supprimer
bool contract::DeleteContract(int id) {
	QSqlQuery query;
	query.prepare("SELECT * FROM CONTRACTS WHERE CONTRACT_ID = :id ");
	query.bindValue(":id", id);

	if (query.exec()) {
		if (query.next()) {
			QSqlQuery deleteQuery;
			deleteQuery.prepare("DELETE FROM CONTRACTS WHERE CONTRACT_ID = :id ");
			deleteQuery.bindValue(":id", id);

			if (deleteQuery.exec()) {
				qDebug() << "Contract found. Deleting process ...";
				return true;
			}
			else {
				qDebug() << "Error executing delete query:" << deleteQuery.lastError().text();
				return false;
			}
		}
		else {
			qDebug() << "Contract not found.";
			return false;
		}
	}
	else {
		qDebug() << "Error executing query:" << query.lastError().text();
		return false;
	}
}


//fonction lire
void contract::ReadContract() {
	if (tableContract == nullptr) {
		qDebug() << "Error : tableContract is null";
		return;
	}

	tableContract->clearContents();
	tableContract->setRowCount(0);

	QSqlQuery query;
	query.prepare("SELECT * FROM CONTRACTS");
	if (query.exec()) {
		while (query.next()) {
			int row = tableContract->rowCount();
			tableContract->insertRow(row);

			tableContract->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
			tableContract->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
			tableContract->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
			tableContract->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
			tableContract->setItem(row, 4, new QTableWidgetItem(query.value(4).toDate().toString()));
			tableContract->setItem(row, 5, new QTableWidgetItem(query.value(5).toDate().toString()));
			tableContract->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
			tableContract->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
		}
		tableContract->repaint();
	}
	else {
		qDebug() << "Error executing query:" << query.lastError().text();
	}
}


//fonction modifier
bool contract::UpdateContract(int contractID, int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
	QSqlQuery qry;
	qry.prepare("UPDATE CONTRACTS SET USER_ID = :user_id, CLIENT_ID = :client_id, PREMIUM_AMOUNT = :premium_amount, EFFECTIVE_DATE = :effective_date, EXPIRATION_DATE = :expiration_date, PAYMENT_STATUS = :payment_status, TYPE = :type WHERE CONTRACT_ID = :id");

	qry.bindValue(":user_id", USER_ID);
	qry.bindValue(":client_id", CLIENT_ID);
	qry.bindValue(":premium_amount", PREMIUM_AMOUNT);
	qry.bindValue(":effective_date", QVariant(EFFECTIVE_DATE));
	qry.bindValue(":expiration_date", QVariant(EXPIRATION_DATE));
	qry.bindValue(":payment_status", PAYMENT_STATUS);
	qry.bindValue(":type", TYPE);
	qry.bindValue(":id", contractID);

	if (qry.exec()) {
		qDebug() << "Contract updated successfully." << "Data:" <<
			"\nContract ID:" << contractID <<
			"\nUser ID:" << USER_ID <<
			"\nClient ID:" << CLIENT_ID <<
			"\nPremium Amount:" << PREMIUM_AMOUNT <<
			"\nEffective Date:" << EFFECTIVE_DATE.toString(Qt::ISODate) <<
			"\nExpiration Date:" << EXPIRATION_DATE.toString(Qt::ISODate) <<
			"\nPayment Status:" << PAYMENT_STATUS <<
			"\nType:" << TYPE;
		return true;
	}
	else {
		qDebug() << "Error updating contract:" << qry.lastError().text();
		return false;
	}
}

void contract::searchContract(QString id) {
    QSqlQuery qry;
    QString queryString;

    if (id.isEmpty()) {
        queryString = "SELECT * FROM CONTRACTS";
    }
    else {
        queryString = "SELECT * FROM CONTRACTS WHERE CONTRACT_ID LIKE :id";
    }

    qry.prepare(queryString);
    if (!id.isEmpty()) {
        qry.bindValue(":id", "%" + id + "%");
    }

    if (qry.exec()) {
        tableContract->clearContents();
        tableContract->setRowCount(0);

        int row = 0;
        while (qry.next()) {
            tableContract->insertRow(row);
            int col = 0;

            tableContract->setRowHeight(row, 50);
            tableContract->setFont(QFont("Helvetica", 10));
            tableContract->setColumnWidth(0, 10);//ID
            tableContract->setColumnWidth(1, 150);//USER ID
            tableContract->setColumnWidth(2, 50);//CLIENT ID
            tableContract->setColumnWidth(3, 50);//PREMIUM AMOUNT
            tableContract->setColumnWidth(4, 150);//EFFECTIVE DATE
            tableContract->setColumnWidth(5, 75);//EXPIRATION DATE
            tableContract->setColumnWidth(6, 50);//PAYMENT STATUS
            tableContract->setColumnWidth(7, 50);//TYPE

            // Set data items for each column
            QTableWidgetItem* contractIdItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* userIdItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* clientIdItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* premiumAmountItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* effectiveDateItem = new QTableWidgetItem(qry.value(col++).toDate().toString());
            QTableWidgetItem* expirationDateItem = new QTableWidgetItem(qry.value(col++).toDate().toString());
            QTableWidgetItem* paymentStatusItem = new QTableWidgetItem(qry.value(col++).toString());
            QTableWidgetItem* typeItem = new QTableWidgetItem(qry.value(col++).toString());


            tableContract->setItem(row, 0, contractIdItem);
            tableContract->setItem(row, 1, userIdItem);
            tableContract->setItem(row, 2, clientIdItem);
            tableContract->setItem(row, 3, premiumAmountItem);
            tableContract->setItem(row, 4, effectiveDateItem);
            tableContract->setItem(row, 5, expirationDateItem);
            tableContract->setItem(row, 6, paymentStatusItem);
            tableContract->setItem(row, 7, typeItem);

            ++row;
        }
        tableContract->repaint();

        if (row == 0) {
            qDebug() << "Contract not found.";
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


void contract::sortContractsByPremium(bool ascendingOrder)
{
    QString sortOrder = ascendingOrder ? "ASC" : "DESC";

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CONTRACTS ORDER BY PREMIUM_AMOUNT " + sortOrder);
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching sorted data...";

    // Clear the existing table contents
    tableContract->clearContents();
    tableContract->setRowCount(0);

    int row = 0;
    while (qry.next()) {
        int col = 0;
        tableContract->insertRow(row);

        // Set data items for each column
        QTableWidgetItem* contractIdItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* userIdItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* clientIdItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* premiumAmountItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* effectiveDateItem = new QTableWidgetItem(qry.value(col++).toDate().toString());
        QTableWidgetItem* expirationDateItem = new QTableWidgetItem(qry.value(col++).toDate().toString());
        QTableWidgetItem* paymentStatusItem = new QTableWidgetItem(qry.value(col++).toString());
        QTableWidgetItem* typeItem = new QTableWidgetItem(qry.value(col++).toString());

        // Set items to the table
        tableContract->setItem(row, 0, contractIdItem);
        tableContract->setItem(row, 1, userIdItem);
        tableContract->setItem(row, 2, clientIdItem);
        tableContract->setItem(row, 3, premiumAmountItem);
        tableContract->setItem(row, 4, effectiveDateItem);
        tableContract->setItem(row, 5, expirationDateItem);
        tableContract->setItem(row, 6, paymentStatusItem);
        tableContract->setItem(row, 7, typeItem);

        ++row;
    }
    tableContract->repaint();

    qDebug() << "Contract data sorted by premium amount in" << sortOrder << "order.";
}
void contract::toPdf(const QString& filePath)
{
    qDebug() << "Exporting contract data to PDF:" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "File path is empty.";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CONTRACTS");
    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QTextDocument doc;
    QTextCursor cursor(&doc);

    cursor.insertHtml("<h1 style='text-align: center; color: #333333;'>Contracts List</h1><br>");

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
    cellCursor.insertText("User ID");

    cellCursor = table->cellAt(0, 2).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Client ID");

    cellCursor = table->cellAt(0, 3).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Premium Amount");

    cellCursor = table->cellAt(0, 4).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Effective Date");

    cellCursor = table->cellAt(0, 5).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Expiration Date");

    cellCursor = table->cellAt(0, 6).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Payment Status");

    cellCursor = table->cellAt(0, 7).firstCursorPosition();
    cellCursor.setCharFormat(headerFormat);
    cellCursor.insertText("Type");

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
    QMessageBox::information(nullptr, "Export Successful", "Contract Data has been successfully exported to PDF.\nFile saved to: " + filePath);
}
void contract::statsByPremiumAmount()
{
    QSqlQuery qry;
    qry.prepare("SELECT PREMIUM_AMOUNT_GROUP, COUNT(*) AS CONTRACT_COUNT \
                 FROM ( \
                     SELECT CASE \
                             WHEN PREMIUM_AMOUNT BETWEEN 0 AND 100 THEN '0-100' \
                             WHEN PREMIUM_AMOUNT BETWEEN 101 AND 500 THEN '101-500' \
                             WHEN PREMIUM_AMOUNT BETWEEN 501 AND 1000 THEN '501-1000' \
                             ELSE '1000+' \
                         END AS PREMIUM_AMOUNT_GROUP \
                     FROM CONTRACTS \
                 ) PremiumAmountGroups \
                 GROUP BY PREMIUM_AMOUNT_GROUP \
                 ORDER BY PREMIUM_AMOUNT_GROUP");

    if (!qry.exec()) {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return;
    }

    qDebug() << "Query executed successfully. Fetching data...";

    QBarSeries *barSeries = new QBarSeries();

    while (qry.next()) {
        QString premiumAmountGroup = qry.value(0).toString();
        int contractCount = qry.value(1).toInt();

        // Create a bar set with label text indicating premium amount group and contract count
        QBarSet *barSet = new QBarSet(premiumAmountGroup);
        *barSet << contractCount;
        barSeries->append(barSet);
    }

    QChart *chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Contracts by Premium Amount");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "0-100" << "101-500" << "501-1000" << "1000+"; // Define categories for x-axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(5); // Set number of ticks on y-axis
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(800, 600);
    chartView->show();
}
/*
void contract::exportToExcel(int clientId, const QString& filePath) {
    qDebug() << "Exportation des données des contrats client vers Excel :" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "Le chemin du fichier est vide.";
        return;
    }

    // Ouvrir le fichier Excel
    QXlsx::Document xlsx;

    // Ajouter les en-têtes
    xlsx.write("A1", "CONTRACT ID");
    xlsx.write("B1", "USER ID");
    xlsx.write("C1", "CLIENT ID");
    xlsx.write("D1", "PREMIUM AMOUNT");
    xlsx.write("E1", "EFFECTIVE DATE");
    xlsx.write("F1", "EXPIRATION DATE");
    xlsx.write("G1", "PAYMENT STATUS");
    xlsx.write("H1", "TYPE");

    // Exécuter la requête SQL pour récupérer les contrats du client spécifié
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CONTRATS WHERE ClientID = :clientId");
    qry.bindValue(":clientId", clientId);
    if (!qry.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << qry.lastError().text();
        return;
    }

    // Suivre l'index de ligne pour écrire les données dans Excel
    int rowIndex = 2;

    // Initialiser les variables pour calculer le montant total de la prime
    int totalContracts = 0;
    double totalPremiumAmount = 0.0;

    // Récupérer et écrire les données des contrats dans Excel
    while (qry.next()) {
        xlsx.write(rowIndex, 1, qry.value(0).toInt()); // CONTRACT ID
        xlsx.write(rowIndex, 2, qry.value(1).toInt()); // USER ID
        xlsx.write(rowIndex, 3, qry.value(2).toInt()); // CLIENT ID
        xlsx.write(rowIndex, 4, qry.value(3).toInt()); // PREMIUM AMOUNT
        xlsx.write(rowIndex, 5, qry.value(4).toDate().toString(Qt::ISODate)); // EFFECTIVE DATE
        xlsx.write(rowIndex, 6, qry.value(5).toDate().toString(Qt::ISODate)); // EXPIRATION DATE
        xlsx.write(rowIndex, 7, qry.value(6).toInt()); // PAYMENT STATUS
        xlsx.write(rowIndex, 8, qry.value(7).toString()); // TYPE

        // Incrémenter totalContracts et ajouter à totalPremiumAmount
        totalContracts++;
        totalPremiumAmount += qry.value(3).toDouble(); // Montant de la prime

        // Passer à la ligne suivante
        rowIndex++;
    }

    // Enregistrer le fichier Excel
    xlsx.saveAs(filePath);

    qDebug() << "Fichier Excel créé avec succès :" << filePath;

    // Afficher une boîte de message avec un résumé de l'exportation
    QString message = QString("Les données des contrats clients ont été exportées avec succès vers Excel.\n"
                              "Nombre total de contrats : %1\n"
                              "Montant total  : %2 $").arg(totalContracts).arg(totalPremiumAmount);
    QMessageBox::information(nullptr, "Exportation réussie", message);
}
*/
/*
contract::contract(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::contract)
{
	ui->setupUi(this);
}
*/


