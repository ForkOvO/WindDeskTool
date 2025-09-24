#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 主窗口

#include <QMainWindow>

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // 实现拖动窗口功能
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // 重绘窗口
    void paintEvent(QPaintEvent *event) override;
private:
    void uiInit();  // 初始化界面

private:
    bool m_drag = false;    // 是否拖动窗口
    QPoint m_dragPosition;  // 拖动位置

    QPushButton* m_closeBtn = nullptr;  // 关闭按钮
};
#endif // MAINWINDOW_H
