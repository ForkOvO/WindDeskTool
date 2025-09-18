#include "mainwindow.h"
#include "interface.h"

#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("WindDeskTool");
    resize(1000, 800);

    // 加载插件
    QPluginLoader loader("plugins/libtest.dll");
    QObject *plugin = loader.instance();
    if (plugin) {
        PluginInterface *pluginInterface = qobject_cast<PluginInterface *>(plugin);
        if (pluginInterface) {
            qDebug() << "Plugin loaded:" << pluginInterface->name();
            pluginInterface->setParent(this); // 将插件的父对象设置为MainWindow，确保其生命周期与MainWindow一致
        }
    } else {
        qDebug() << "Failed to load plugin:" << loader.errorString();
    }
}

MainWindow::~MainWindow()
{
}
