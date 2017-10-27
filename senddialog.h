#ifndef SENDDIALOG_H
#define SENDDIALOG_H

#include <QDialog>
#include "sendtask.h"

namespace Ui {
class sendDialog;
}

class sendDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit sendDialog(const QString &file_path, QWidget *parent = 0);
    ~sendDialog();
    
private:
    Ui::sendDialog *ui;
    sendTask *task; // 工作线程
    virtual void timerEvent(QTimerEvent *event);
    int timer_id;

};

#endif // SENDDIALOG_H
