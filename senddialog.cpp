#include "senddialog.h"
#include "ui_senddialog.h"

sendDialog::sendDialog(const QString &file_path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendDialog)
{
    ui->setupUi(this);

    // 创建工作线程
    task = new sendTask(NULL);
    task->create(file_path.toUtf8());

    // 启动定时器
    timer_id = startTimer(500);
}

sendDialog::~sendDialog()
{
    delete ui;
}


void sendDialog::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer_id) {
        int status = task->get_status();
        int progress = task->get_progress();
        ui->progressBar->setValue(progress);

        if (status == 1) {
            task->destroy();
            delete task;
            killTimer(timer_id);
            accept();
        }
    }
}
