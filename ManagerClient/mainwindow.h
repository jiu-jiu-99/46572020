#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <initialpage.h>
#include <queryinvoiceinputdialog.h>
#include <invoicepage.h>
#include <reportpage.h>
#include <QTcpSocket>
#include <SocketConstants.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void queryInputFinish(int);
	void on_ptn_makeInvoice_clicked();

	void on_ptn_makeReport_clicked();

private slots:
	void initialHandle(InitialParameters parameters);
	void newServerMessage();

private:
	Ui::MainWindow *ui; //监视主页面
	InitialPage *initialPage; //初始化页面
	QueryInvoiceInputDialog *queryInvoiceInputDialg; //账单查询页面
	InvoicePage *invoicePage; //账单页面
	ReportPage *reportPage; //报表页面
	QTcpSocket *socket; //套接字

	void sendPacket(QByteArray body);
	void sendJSON(QJsonObject ojson);
	void processPacket(QByteArray body);
};
#endif // MAINWINDOW_H
