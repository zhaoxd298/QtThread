#include "sendtask.h"
#include <stdio.h>
#include <QDebug>

sendTask::sendTask(QObject *parent) :
    QThread(parent)
{
}


int sendTask::get_status()
{
    return status;
}

int sendTask::get_progress()
{
    if (file_size <= 0) {
        return 0;
    } else {
        return send_size * 100 / file_size;
    }
}

int sendTask::create(const char *file_name)
{
    strcpy(file_path, file_name);
    file_size = 0;
    send_size = 0;
    status = 0;

    start();    // 运行线程
    return 0;
}

int sendTask::destroy()
{
    wait();
    return 0;
}

void sendTask::run()
{
    FILE *fp = fopen(file_path, "rb");
    if (!fp) {
        status = -1;
        return;
    }
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char buf[256];
    while (1) {
        int n = fread(buf, 1, 256, fp);
        if (n <= 0) {
            break;
        }
        qDebug() << "Send size:" << send_size;
        send_size += n;
        QThread::msleep(100);
    }
    fclose(fp);
    status = 1;
    qDebug() << "complete";
}
