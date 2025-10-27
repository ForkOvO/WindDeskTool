#ifndef PUBLICINFOMANAGER_H
#define PUBLICINFOMANAGER_H

// 公共信息管理类 单例模式

#include <QObject>
#include <mutex>

class PublicInfoManager : public QObject
{
    Q_OBJECT
public:
    // 单例模式 禁止拷贝构造和赋值
    PublicInfoManager(const PublicInfoManager&) = delete;
    PublicInfoManager& operator=(const PublicInfoManager&) = delete;

    static PublicInfoManager* instance(); // 获取单例对象

    inline QString name() const { return m_name; } // 获取软件名称
    inline QString exePath() const { return m_exePath; } // 获取软件执行路径
    inline QString pluginDirPath() const { return m_exeDirPath + "/plugins"; } // 获取插件路径

private:
    explicit PublicInfoManager();
    static std::atomic<PublicInfoManager*> m_instance; // 单例对象
    static std::mutex m_mutex; // 互斥锁

    QString m_name = "风桌工具"; // 软件名称

    QString m_exePath; // 软件执行路径
    QString m_exeDirPath; // 软件执行目录路径
};

#endif // PUBLICINFOMANAGER_H
