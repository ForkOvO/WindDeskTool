#include "mainwindow.h"
#include "centralwidget.h"

#include <QMouseEvent>
#include <QPushButton>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("WindDeskTool");

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
    // 设置窗口
    resize(1000, 800);
    setWindowFlags(Qt::FramelessWindowHint);

    // 中心窗口
    m_centralWidget = new CentralWidget(this);
    setCentralWidget(m_centralWidget);

    // 关闭按钮
    m_closeBtn = new QPushButton(this);
    m_closeBtn->setGeometry(width() - 50, 0, 50, 50);
    connect(m_closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    m_closeBtn->show();
}
