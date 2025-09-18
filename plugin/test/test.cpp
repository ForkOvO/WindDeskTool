#include "test.h"

#include <QLabel>

Test::Test(QObject *parent)
{
    QLabel *label = new QLabel("Test Plugin", this);

    setFixedSize(100, 50);
    label->setFixedSize(100, 50);

    setStyleSheet("background-color: red;");
}

Test::~Test()
{
}

QString Test::name() const
{
    return "Test Plugin";
}
