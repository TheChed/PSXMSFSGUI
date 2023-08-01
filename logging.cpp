#include "logging.h"
#include "PSXMSFS.h"

logging::logging(QObject *parent)
    : QObject{parent}
{
    mStop = false;
}

void logging::start(void)
{

    mStop = false ;
    debugMessage **D = initDebugBuff();

    static uint64_t printedLogs = 0;
    while (1) {
        if(mStop) return;
        for (size_t i = 0; i < NB_LOGS; i++) {
            if (D[i]->Id > printedLogs) {
                emit on_log(QString(D[i]->message));
                printedLogs++;
            }
        }
    }

}

void logging::stop()
{

    mStop = true;
}
