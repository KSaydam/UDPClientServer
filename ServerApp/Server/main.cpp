#include <QtWidgets/QApplication>
#include "mainwindow.h"

QMutex mutex;

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

	Q_UNUSED(context);
	QMutexLocker locker(&mutex);
 
 }

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow m;
	m.show();

	qInstallMessageHandler(customMessageHandler);
	//Start the main loop
	return a.exec();
}
