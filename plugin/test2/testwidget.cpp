#include "testwidget.h"

#include <QLabel>

TestWidget::TestWidget()
{
    QLabel *label = new QLabel("Test2 Plugin", this);

    setFixedSize(100, 50);
    label->setFixedSize(100, 50);

    setStyleSheet("background-color: green;");
}

TestWidget::~TestWidget()
{
}
