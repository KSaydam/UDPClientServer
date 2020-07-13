#include "mainwindow.h"
#include <QLabel>

extern QByteArray datagram;
extern bool IsImageTransferCompleted;

static int s_tabCount = 1;

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	listener = new UDPListener(54000); //Create a listener thread for port
	listener->start();

	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateImage()));
	timer->start(1000);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::updateImage()
{
	if (IsImageTransferCompleted)
	{
		QString tabName = "Tab" + QString::number(s_tabCount);
		QPixmap pixelMap(datagram.data()); 
		QLabel* label = new QLabel();
		label->setPixmap(pixelMap);

		ui->tabWidget->addTab(label, tabName);
		IsImageTransferCompleted = false;
		s_tabCount++;
	}
}


void MainWindow::initDockWidgets()
{
	m_pCentralMainwindow = new QMainWindow;
}

void MainWindow::generateDockWidgets()
{
	this->setCentralWidget(m_pCentralMainwindow);
		
}

void MainWindow::serverGUIShow()
{
	//m_pSocketProtocol = new UDPSocketProtocol(this);
	//m_pSocketProtocol->show();
}




