#include "test.h"
#include "testwidget.h"

Test::Test(QObject *parent)
{
    m_info.name = "Test Plugin2";
    m_info.widget = new TestWidget();
}

Test::~Test()
{
}

PluginInfo Test::info() const
{
    return m_info;
}
