#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtWidgets>
#include <Client.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    client = new Client();
    client->start();
    client->setReceiver(54000, "127.0.0.1");
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(when_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::when_pushButton_clicked()
{
    //Chose file from file dialog
    QString fileName = QFileDialog::getOpenFileName(this, "Select an Image", "C://");
    QByteArray byArr = fileName.toLocal8Bit();
    char* data = byArr.data();

    FILE* fp = fopen(data, "rb");
    if (fp == NULL)
    {
        qDebug("Unable to open the image");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp); //counting the size of the file
    client->sendData(data, size);   //Send it to the receiver
    fclose(fp);
}


