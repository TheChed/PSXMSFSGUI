#ifndef LOGGING_H
#define LOGGING_H

#include <QObject>
#include <Qthread>
#include <QtConcurrent>

#define NB_LOGS 20

class logging : public QObject
{
    Q_OBJECT
public:
    explicit logging(QObject *parent = nullptr);
    void start(void);

signals:

    void on_log(QString log);

public slots:

  void  stop();

private:
    bool mStop;

};

#endif // LOGGING_H
