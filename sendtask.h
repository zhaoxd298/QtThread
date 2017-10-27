#ifndef SENDTASK_H
#define SENDTASK_H

#include <QThread>
#include <QTimer>

class sendTask : public QThread
{
    Q_OBJECT
public:
    explicit sendTask(QObject *parent = 0);
    int get_status();
    int get_progress();
    int create(const char *file_name);
    int destroy();

private:
    void run(); // 线程入口函数
private:
    char file_path[128];
    int file_size;
    int send_size;
    int status;
signals:
    
public slots:
    
};

#endif // SENDTASK_H
