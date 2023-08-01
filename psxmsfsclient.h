#ifndef PSXMSFSCLIENT_H
#define PSXMSFSCLIENT_H

#include <QMainWindow>
#include "logging.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PSXMSFSCLIENT; }
QT_END_NAMESPACE

class PSXMSFSCLIENT : public QMainWindow
{
    Q_OBJECT

public:
    PSXMSFSCLIENT(QWidget *parent = nullptr);
    ~PSXMSFSCLIENT();

signals:
   void on_stop();

private slots:
    void on_B_Connect_clicked();
    void on_B_quit_clicked();

public slots:
    void newLog(QString log);

private:
    Ui::PSXMSFSCLIENT *ui;
    logging Log;
};

#endif // PSXMSFSCLIENT_H
