#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Client.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    Client* client;

    ~MainWindow();

private slots:
    void when_pushButton_clicked();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
