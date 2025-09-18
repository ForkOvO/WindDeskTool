#ifndef TEST_H
#define TEST_H

#include "interface.h"
#include <QWidget>

class Test : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "PluginInterface_iid")
    Q_INTERFACES(PluginInterface)

public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    QString name() const override;  // 插件名称
};

#endif // TEST_H
