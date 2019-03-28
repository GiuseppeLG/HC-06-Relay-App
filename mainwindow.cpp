#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtBluetooth>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this,SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
   agent -> start();
   socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Find_clicked()
{
    ui-> listWidget->clear();
    agent -> stop();
    agent -> start();
}

void MainWindow::on_Stereo_clicked()
{
 socket -> write("1");
 qDebug() << "OFF Stereo CLICKED";
}


void MainWindow::on_MediaCenter_clicked()
{
 socket -> write("2");
  qDebug() << "OFF MediaCenter CLICKED";
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    ui->listWidget->addItem(device.address().toString());
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    string = item->text();
   // ui -> listWidget ->addItem(string);

    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
   // ui-> listWidget->clear();
    qDebug() << "Try connection";
}

void MainWindow::on_MediaCenter_2_clicked()
{
    socket -> write("p");
     qDebug() << "ON MediaCenter CLICKED";
}

void MainWindow::on_Stereo_2_clicked()
{
    socket -> write("o");
     qDebug() << "ON Stereo CLICKED";
}
