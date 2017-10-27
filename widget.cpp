#include "widget.h"
#include <QFileDialog>
#include "senddialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    path_name->setReadOnly(true);
    connect(scanButton, SIGNAL(clicked()), this, SLOT(click_scanButton()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(click_sendButton()));

}

Widget::~Widget()
{
}

void Widget::click_scanButton()
{
    QString file_path = QFileDialog::getOpenFileName(this, "please choose file");
    if (file_path.length() > 0) {
        path_name->setText(file_path);
    }
}

void Widget::click_sendButton()
{
    QString file_path = path_name->text();
    if (file_path.length() > 0) {
        sendDialog send_dialog(file_path, this);
        send_dialog.exec();
    }

}
