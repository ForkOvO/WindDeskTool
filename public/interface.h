#ifndef INTERFACE_H
#define INTERFACE_H

// 插件接口

#include <QWidget>

class PluginInterface : public QWidget
{
public:
    virtual ~PluginInterface() {}
    virtual QString name() const = 0;   // 插件名称
};

#define PluginInterface_iid "com.example.PluginInterface"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // INTERFACE_H
