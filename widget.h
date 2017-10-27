#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget, public Ui::Widget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void click_scanButton();
    void click_sendButton();
};

#endif // WIDGET_H
