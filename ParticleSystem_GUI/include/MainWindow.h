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
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our Main Window class
    /// @param [in] parent the parent window to the class
    //----------------------------------------------------------------------------------------------------------------------
    MainWindow(QWidget *parent = nullptr);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for our MainWindow class
    //----------------------------------------------------------------------------------------------------------------------
    ~MainWindow();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event);

private slots:
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called to check whether the check box to edit emitter 1 is checked or not
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter1CheckBox_clicked();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called to check whether the check box to edit emitter 2 is checked or not
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter2CheckBox_clicked();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called to check whether the check box to edit emitter 3 is checked or not
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter3CheckBox_clicked();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called to check whether the check box to edit emitter 4 is checked or not
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter4CheckBox_clicked();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called to check whether the check box to toggle on and off the single shot is checked or not
    //--------------------------------------------------------------------------------------------------------------------------
    void singleShotCheckBox_clicked();

private:
    //pointer to our ui
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
