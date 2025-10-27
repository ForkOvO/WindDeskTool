#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

// 插件管理器

#include "interface.h"

#include <QObject>

class PluginManager : public QObject
{
public:
    explicit PluginManager(QObject *parent = nullptr);
    ~PluginManager();

    QVector<PluginInfo> pluginInfos() const { return m_pluginInfos; } // 获取插件信息列表

private:
    QVector<PluginInfo> m_pluginInfos;   // 插件信息列表
};

#endif // PLUGINMANAGER_H