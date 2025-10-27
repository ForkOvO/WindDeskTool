#include "centralwidget.h"
#include "pluginmanager.h"

#include <QHBoxLayout>
#include <QListWidget>
#include <QStackedWidget>

CentralWidget::CentralWidget(QWidget *parent)
{
    // 初始化部件
    m_pluginManager = new PluginManager(this);
    m_pluginListWidget = new QListWidget();
    m_pluginStackedWidget = new QStackedWidget();

    connect(m_pluginListWidget, &QListWidget::currentRowChanged, m_pluginStackedWidget, &QStackedWidget::setCurrentIndex);

    // 初始化布局
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_pluginListWidget);
    layout->addWidget(m_pluginStackedWidget);

    // 加载插件信息
    QVector<PluginInfo> plugins = m_pluginManager->pluginInfos();
    for (const PluginInfo& plugin : plugins)
    {
        m_pluginListWidget->addItem(plugin.name);
        m_pluginStackedWidget->addWidget(plugin.widget);
    }
}

CentralWidget::~CentralWidget()
{
}
