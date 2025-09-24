#include "mainwindow.h"
#include "interface.h"

#include <QPluginLoader>
#include <QMouseEvent>
#include <QPushButton>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("WindDeskTool");
    resize(1000, 800);

    // 加载插件
    QPluginLoader loader("plugins/libtest.dll");
    QObject *plugin = loader.instance();
    if (plugin)
    {
        PluginInterface *pluginInterface = qobject_cast<PluginInterface *>(plugin);
        if (pluginInterface)
        {
            qDebug() << "Plugin loaded:" << pluginInterface->name();
            pluginInterface->setParent(this); // 将插件的父对象设置为MainWindow，确保其生命周期与MainWindow一致
        }
    }
    else
    {
        qDebug() << "Failed to load plugin:" << loader.errorString();
    }

    uiInit();   // 初始化界面
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_drag = true;
        m_dragPosition = event->globalPosition().toPoint() - pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drag)
    {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_drag = false;
        event->accept();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // 渐变背景
    QLinearGradient gradient(0, height(), width(), 0);
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(85, 170, 255));
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
    QMainWindow::paintEvent(event);
}

void MainWindow::uiInit()
{
    // 设置无边框窗口
    setWindowFlags(Qt::FramelessWindowHint);

    // 关闭按钮
    m_closeBtn = new QPushButton(this);
    m_closeBtn->setGeometry(width() - 50, 0, 50, 50);
    connect(m_closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    m_closeBtn->show();
}
