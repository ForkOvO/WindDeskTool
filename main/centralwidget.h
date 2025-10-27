#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

// 中心窗口

#include <QWidget>

class PluginManager;
class QListWidget;
class QStackedWidget;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent);
    ~CentralWidget();

private:
    PluginManager* m_pluginManager = nullptr; // 插件管理器
    QListWidget* m_pluginListWidget = nullptr; // 插件列表控件
    QStackedWidget* m_pluginStackedWidget = nullptr; // 插件栈控件
};

#endif // CENTRALWIDGET_H