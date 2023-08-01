#include<QFuture>
#include <QtConcurrent>
#include "psxmsfsclient.h"
#include "ui_psxmsfsclient.h"
#include "PSXMSFS.h"

//#define NB_LOGS 20


PSXMSFSCLIENT::PSXMSFSCLIENT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PSXMSFSCLIENT)
{
    ui->setupUi(this);
}

PSXMSFSCLIENT::~PSXMSFSCLIENT()
{
    emit on_stop();
    ui->TE->clear();
    delete ui;

}


void PSXMSFSCLIENT::on_B_Connect_clicked()
{


    FLAGS *flags = NULL;


    connect(&Log,&logging::on_log,this,&PSXMSFSCLIENT::newLog);
    connect(this,&PSXMSFSCLIENT::on_stop,&Log,&logging::stop);

    ui->B_Connect->setDisabled(true);

    QFuture<void> t2 = QtConcurrent::run(&logging::start,&this->Log);

    if(initialize(NULL,NULL,0,NULL,0)!=0){
         ui->B_Connect->setDisabled(true);
        emit on_stop();
        ui->TE->clear();
        ui->TE->append(QString("Could not initialize connections and will exit."));
        ui->TE->append(QString("Please exit and check your PSXMSFS.ini file"));

    }

    else {

        flags=connectPSXMSFS();

        if(flags){


            ui->L_main->setText(QString(flags->server.PSXMainServer)+":"+QString::number(flags->server.PSXPort));
            ui->L_Boost->setText(QString(flags->server.PSXBoostServer)+":"+QString::number(flags->server.PSXBoostPort));
            ui->L_MSFS->setText(QString(flags->server.MSFSServer));
            ui->B_Connect->setDisabled(true);

            // Various flags
            ui->CB_TCAS->setChecked(flags->flags.TCAS_INJECT);
            ui->CB_TCAS->setEnabled(false);

            ui->label_4->setDisabled(true);
            ui->label_5->setDisabled(true);
            ui->label_6->setDisabled(true);
            ui->label_3->setDisabled(true);

            ui->CB_ELEV->setChecked(flags->flags.ELEV_INJECT);
            ui->CB_ELEV->setEnabled(false);

            ui->CB_CRASH->setChecked(flags->flags.INHIB_CRASH_DETECT);
            ui->CB_CRASH->setEnabled(false);

            ui->CB_IVAO->setChecked(flags->flags.ONLINE);
            ui->CB_IVAO->setEnabled(false);

            ui->CB_SLAVE->setChecked(flags->flags.SLAVE);
            ui->CB_SLAVE->setEnabled(false);

            switch(flags->flags.LOG_VERBOSITY){
                case 1:
                    ui->L_VERB->setText(QString("DEBUG"));
                    break;
                case 2:
                     ui->L_VERB->setText(QString("VERBOSE"));
                    break;
                case 3:
                     ui->L_VERB->setText(QString("INFO"));
                     break;
                case 4:
                     ui->L_VERB->setText(QString("ERROR"));
                     break;
                default:
                     ui->L_VERB->setText(QString::number(flags->flags.LOG_VERBOSITY));

            }


            QFuture<DWORD> t1 = QtConcurrent::run(main_launch);

        }
        else {
            emit on_stop();
            ui->TE->clear();
            ui->TE->append(QString("Could not create the necessary connections."));
            ui->TE->append(QString("Please check the PSXMSFS.ini file and restart."));

    }

}

}
void PSXMSFSCLIENT::on_B_quit_clicked()
{
    emit on_stop();
    ui->TE->clear();
    cleanup();
    QApplication::quit();
}

void PSXMSFSCLIENT::newLog(QString log)
{
        ui->TE->append(log) ;
}

