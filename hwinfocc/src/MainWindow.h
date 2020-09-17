#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <DMainWindow>

DWIDGET_USE_NAMESPACE
class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    MainWindow();
};

#endif // MAINWINDOW_H
