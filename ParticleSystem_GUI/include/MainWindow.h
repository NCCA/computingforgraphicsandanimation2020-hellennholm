#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "NGLScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void editEmitter1CheckBox_clicked();
    void editEmitter2CheckBox_clicked();
    void editEmitter3CheckBox_clicked();
    void editEmitter4CheckBox_clicked();
    void singleShotCheckBox_clicked();

private:
    Ui::MainWindow *ui;
    //pointer to our scene object
    NGLScene *m_gl;
    //edit the first emitter, default set to false
    bool m_emitter1Edit = false;
    //edit the second emitter, default set to false
    bool m_emitter2Edit = false;
    //edit the third emitter, default set to false
    bool m_emitter3Edit = false;
    //edit the fourth emitter, default set to false
    bool m_emitter4Edit = false;
    //single shot of particles, default set to false
    bool m_singleShot = false;
};
#endif // MAINWINDOW_H
