#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("NetAssistant"));
    setFixedHeight(445);
    setFixedWidth(685);
    status_Label = new QLabel();
    status_Label->setMinimumSize(260, 20); // 设置标签最小大小
    status_Label->setFrameShape(QFrame::WinPanel);
    status_Label->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(status_Label);
    status_Label->setText(tr("TCP Server is not active"));
    status_Label->setAlignment(Qt::AlignHCenter);

    receive_Label = new QLabel();
    receive_Label->setMinimumSize(100, 20); // 设置标签最小大小
    receive_Label->setFrameShape(QFrame::WinPanel);
    receive_Label->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(receive_Label);
    receive_Label->setAlignment(Qt::AlignHCenter);

    send_Label = new QLabel();
    send_Label->setMinimumSize(100, 20); // 设置标签最小大小
    send_Label->setFrameShape(QFrame::WinPanel);
    send_Label->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(send_Label);
    send_Label->setAlignment(Qt::AlignHCenter);

    clear_Count_Btn = new QPushButton(tr("Clear Count"));
    ui->statusBar->addWidget(clear_Count_Btn);
    connect(clear_Count_Btn, SIGNAL(clicked()), this, SLOT(clear_statusbar()));

    time_Label = new QLabel();
    time_Label->setMinimumSize(87, 20); // 设置标签最小大小
    time_Label->setMaximumWidth(90);
    time_Label->setFrameShape(QFrame::WinPanel);
    time_Label->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(time_Label);
    time_Label->setText(QDate::currentDate().toString("yy-MM-dd"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clear_statusbar()
{
    update_statusbar(QString(), 0, 0);
}

void MainWindow::update_statusbar(QString status, QVariant in_num, QVariant out_num)
{
    if (!status.isNull())
    {
        status_Label->setText(status);
    }

    if (!in_num.isNull())
    {
        if ( in_num.toInt() == 0 )
            ReceiveNum = 0;
        else
            ReceiveNum += in_num.toInt();
        receive_Label->setText("R:" + QString::number(ReceiveNum));
    }

    if (!out_num.isNull())
    {
        if ( out_num.toInt() == 0 )
            SendNum = 0;
        else
            SendNum += out_num.toInt();
        send_Label->setText("S:" + QString::number(SendNum));
    }
}

void MainWindow::on_Clear_Display_PushButton_clicked()
{
    ui->Receive_window_TextEdit->clear();
}

void MainWindow::on_Clear_Transmit_PushButton_clicked()
{
    ui->transmit_window_TextEdit->clear();
}

void MainWindow::net_connect()
{
    switch (ui->Protocol_ComboBox->currentIndex())
    {
        case 0:
            // TCP Server
            TCP_server_connect();
            break;
        case 1:
            // TCP Client
            TCP_client_connect();
            break;
        case 2:
            // UDP
            UDP_connect();
            break;
        default:
            break;
    }
}
// public functions

// TCP Server connections
void MainWindow::TCP_server_connect()
{
    qDebug("%s", __func__ );
}

// TCP Server connections
void MainWindow::TCP_client_connect()
{
    qDebug("%s", __func__ );
}

// TCP Server connections
void MainWindow::UDP_connect()
{
    qDebug("%s", __func__ );
}

void MainWindow::on_Connect_Btn_clicked()
{
    switch (ui->Protocol_ComboBox->currentIndex())
    {
        case 0:
            // TCP Server
            TCP_server_connect();
            break;
        case 1:
            // TCP Client
            TCP_client_connect();
            break;
        case 2:
            // UDP
            UDP_connect();
            break;
        default:
            break;
    }
}
