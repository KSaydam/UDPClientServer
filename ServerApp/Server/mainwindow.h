#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <UDPListener.h>
#include "UDPSocketProtocol.h"

#include "ui_mainwindow.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
    void readImage(char* pcIamge);
    void connectObjects();
    void initDockWidgets();
    void generateDockWidgets();
    void serverGUIShow();
    QMainWindow* m_pCentralMainwindow;
    Ui::MainWindow* ui;

public slots:
    void updateImage();

private:
    
    UDPListener* listener;
    UDPSocketProtocol* m_pUDPSocket;


};
#endif // MAINWINDOW_H
