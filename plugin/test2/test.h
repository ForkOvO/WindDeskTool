#ifndef TEST_H
#define TEST_H

#include "interface.h"
#include <QWidget>

// 测试插件

class Test : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "PluginInterface_iid")
    Q_INTERFACES(PluginInterface)

public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    PluginInfo info() const override;  // 插件信息

private:
    PluginInfo m_info;   // 插件信息
};

#endif // TEST_H
