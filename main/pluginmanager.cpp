#include "pluginmanager.h"
#include "publicinfomanager.h"

#include <QPluginLoader>
#include <QDir>

PluginManager::PluginManager(QObject *parent)
{
    // 扫描插件目录 并将插件名称添加到列表中
    QString pluginDirPath = PublicInfoManager::instance()->pluginDirPath();
    QDir pluginsDir(pluginDirPath);
    if (pluginsDir.exists())
    {
        QVector<QString> m_pluginDllList; // 插件列表
        for (const QString &pluginName : pluginsDir.entryList(QDir::Files))
        {
            if (pluginName.endsWith(".dll"))
            {
                m_pluginDllList << pluginName;
            }
        }

        // 加载插件信息
        for (const QString &pluginDll : m_pluginDllList)
        {
            QPluginLoader loader(pluginDirPath + "/" + pluginDll);
            QObject *plugin = loader.instance();
            if (plugin)
            {
                PluginInterface *pluginInterface = qobject_cast<PluginInterface *>(plugin);
                if (pluginInterface)
                {
                    PluginInfo info = pluginInterface->info();
                    m_pluginInfos << info;
                }
            }
            else
            {
                qDebug() << "Failed to load plugin:" << loader.errorString();
            }
        }
    }
}

PluginManager::~PluginManager()
{
}
