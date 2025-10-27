#ifndef TESTWIDGET_H
#define TESTWIDGET_H

// 测试插件的Widget

#include <QWidget>

class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget();
    ~TestWidget();
};

#endif // TESTWIDGET_H