#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void clear_statusbar(void);
    void TCP_server_connect();
    void TCP_client_connect();
    void UDP_connect();

private slots:
    void on_Clear_Display_PushButton_clicked();
    void on_Clear_Transmit_PushButton_clicked();
    void on_Protocol_ComboBox_currentTextChanged();

    void net_connect();
    void on_Connect_Btn_clicked();

private:
    Ui::MainWindow *ui;

    QLabel *status_Label;
    QLabel *receive_Label;
    QLabel *send_Label;

    QPushButton *clear_Count_Btn;
    QLabel *time_Label;

    quint64 ReceiveNum;
    quint64 SendNum;

    QString remote_IP;
    int remote_port;
    int local_port;

    int protocol_mode;
    void update_statusbar(QString status, QVariant in_num, QVariant out_num);
};

#endif // MAINWINDOW_H
