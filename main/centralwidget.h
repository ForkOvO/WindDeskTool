#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

// 中心窗口

#include <QWidget>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent);
    ~CentralWidget();
};

#endif // CENTRALWIDGET_H