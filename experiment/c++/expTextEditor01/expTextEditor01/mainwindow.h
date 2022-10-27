#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ViEditView.h"
#include "ViEngine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onModeChanged();

private:
    Ui::MainWindow *ui;

    ViEditView *m_editor = new ViEditView();    //

};
#endif // MAINWINDOW_H
