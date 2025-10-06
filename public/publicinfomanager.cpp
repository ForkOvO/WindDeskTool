#include "publicinfomanager.h"

#include <QCoreApplication>

std::atomic<PublicInfoManager*> PublicInfoManager::m_instance = nullptr;
std::mutex PublicInfoManager::m_mutex;

PublicInfoManager* PublicInfoManager::instance()
{
    PublicInfoManager* instance = m_instance.load(); // 读取当前实例指针
    if (!instance)
    {
        std::lock_guard<std::mutex> lock(m_mutex); // 加锁
        instance = m_instance.load(); // 再次读取当前实例指针
        if (!instance) // 双重检查
        {
            instance = new PublicInfoManager(); // 创建新实例
            m_instance.store(instance); // 存储新实例指针
        }
    }
    return instance;
}

PublicInfoManager::PublicInfoManager()
{
    m_exePath = QCoreApplication::applicationFilePath();
}