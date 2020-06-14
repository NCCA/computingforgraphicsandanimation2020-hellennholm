#ifndef NGLSCENE_H_
#define NGLSCENE_H_
#include <ngl/Vec3.h>
#include <memory>
#include <ngl/Mat4.h>
#include <chrono>
#include "WindowParams.h"
#include "Emitter.h"
// this must be included after NGL includes else we get a clash with gl libs
#include <QOpenGLWidget>
#include <QApplication>
//----------------------------------------------------------------------------------------------------------------------
/// @file NGLScene.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/9/13
/// Revision History :
/// This is an initial version used for the new NGL6 / Qt 5 demos
/// @class NGLScene
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------

class NGLScene : public QOpenGLWidget
{
  //declare macro Q_OBJECT which will signal the moc to harvest information from the header
  Q_OBJECT

  public:
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our NGL drawing class
    /// @param [in] parent the parent window to the class
    /// @param [in] number of particles in the scene
    //--------------------------------------------------------------------------------------------------------------------------
    NGLScene(size_t _numParticles, QWidget *_parent = nullptr);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief dtor must close down ngl and release OpenGL resources
    //--------------------------------------------------------------------------------------------------------------------------
    ~NGLScene() override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    //--------------------------------------------------------------------------------------------------------------------------
    void initializeGL() override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    //--------------------------------------------------------------------------------------------------------------------------
    void paintGL() override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we resize the window
    /// @param _w width of our window
    /// @param _h height of the window
    //--------------------------------------------------------------------------------------------------------------------------
    void resizeGL(int _w, int _h) override; 
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //--------------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event) override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when first emitter's visibility is toggled on/off
    //--------------------------------------------------------------------------------------------------------------------------
    void toggleEmitter1();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when second emitter's visibility is toggled on/off
    //--------------------------------------------------------------------------------------------------------------------------
    void toggleEmitter2();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when third emitter's visibility is toggled on/off
    //--------------------------------------------------------------------------------------------------------------------------
    void toggleEmitter3();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when fourth emitter's visibility is toggled on/off
    //--------------------------------------------------------------------------------------------------------------------------
    void toggleEmitter4();

public slots:
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the first emitter is toggled to be edited
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter1();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the second emitter is toggled to be edited
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter2();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the third emitter is toggled to be edited
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter3();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the fourth emitter is toggled to be edited
    //--------------------------------------------------------------------------------------------------------------------------
    void editEmitter4();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the gravity applied to the selected emitter changes
    /// @param _gravity the strength of the gravity along y
    //--------------------------------------------------------------------------------------------------------------------------
    void setGravity(int _gravity);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the number of particles for selected emitted changes
    /// @param _numParticles the number of the particles emitted by selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void setNumParticles(int _numParticles);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the particle size for the selected emitter changes
    /// @param _particleSize the size of the particles for selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void setParticleSize(int _particleSize);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the particle spread of the selected emitter changes
    /// @param _spread the size of the spread for selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void setSpread(int _spread);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when single shot is toggle on and off
    //--------------------------------------------------------------------------------------------------------------------------
    void toggleSingleShot();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when addParticlesButton is pressed. It will add particles to the selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void addParticles();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when removeParticlesButton is pressed. It will remove particles from the selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void removeParticles();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when clearParticlesButton is pressed. It will clear the particles for selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void clearParticles();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when resetEmitterButton is pressed. It will reset the selected emitter
    //--------------------------------------------------------------------------------------------------------------------------
    void resetEmitter();
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the red value is changed
    //--------------------------------------------------------------------------------------------------------------------------
    void redValue(int _red);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the green value is changed
    //--------------------------------------------------------------------------------------------------------------------------
    void greenValue(int _green);
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called when the blue value is changed
    //--------------------------------------------------------------------------------------------------------------------------
    void blueValue(int _blue);

private:
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //--------------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (QMouseEvent * _event ) override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //--------------------------------------------------------------------------------------------------------------------------
    void mousePressEvent ( QMouseEvent *_event) override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //--------------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent ( QMouseEvent *_event ) override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //--------------------------------------------------------------------------------------------------------------------------
    void wheelEvent( QWheelEvent *_event) override;
    //--------------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called after a set amount of time
    /// inheritted from the main window and overridden here
    //--------------------------------------------------------------------------------------------------------------------------
    void timerEvent(QTimerEvent *) override;
    /// @brief windows parameters for mouse control etc.
    WinParams m_win;
    /// position for our model
    ngl::Vec3 m_modelPos;
    //viewing matrix
    ngl::Mat4 m_view;
    //projection matrix
    ngl::Mat4 m_project;
    //global mouse transform
    ngl::Mat4 m_globalMouseTX;
    //unique pointers to emitter class for :
    //emitter 1
    std::unique_ptr<Emitter> m_emitter_1;
    //emitter 2
    std::unique_ptr<Emitter> m_emitter_2;
    //emitter 3
    std::unique_ptr<Emitter> m_emitter_3;
    //emitter 4
    std::unique_ptr<Emitter> m_emitter_4;
    //parameter for the number of particles emitted from emitter 1
    size_t m_numParticles1 = 1000;
    //parameter for the number of particles emitted from emitter 2
    size_t m_numParticles2 = 1000;
    //parameter for the number of particles emitted from emitter 3
    size_t m_numParticles3 = 1000;
    //parameter for the number of particles emitted from emitter 4
    size_t m_numParticles4 = 1000;
    //attribute to record the previous time
    std::chrono::high_resolution_clock::time_point m_previousTime;
    //triggering the visibilty of a first emitter, default set to true
    bool m_emitter1Visibility = true;
    //triggering the visibilty of a second emitter, default set to false
    bool m_emitter2Visibility = false;
    //triggering the visibilty of a third emitter, default set to false
    bool m_emitter3Visibility = false;
    //triggering the visibilty of a fourth emitter, default set to false
    bool m_emitter4Visibility = false;
    //value allowing editabilty of first emitter, default set to false
    bool m_emitter1Edit = true;
    //value allowing editabilty of second emitter, default set to false
    bool m_emitter2Edit = false;
    //value allowing editabilty of third emitter, default set to false
    bool m_emitter3Edit = false;
    //value allowing editabilty of fourth emitter, default set to false
    bool m_emitter4Edit = false;
    //gravity applied to emitter1 (along y)
    int m_gravity1 = 10;
    //gravity applied to emitter2 (along y)
    int m_gravity2 = 10;
    //gravity applied to emitter3 (along y)
    int m_gravity3 = 10;
    //gravity applied to emitter4 (along y)
    int m_gravity4 = 10;
    //particle size for emitter 1
    int m_particleSize1 = 5;
    //particle size for emitter 2
    int m_particleSize2 = 5;
    //particle size for emitter 3
    int m_particleSize3 = 5;
    //particle size for emitter 4
    int m_particleSize4 = 5;
    //particle spread for emitter 1
    int m_spread1 = 2;
    //particle spread for emitter 2
    int m_spread2 = 2;
    //particle spread for emitter 3
    int m_spread3 = 2;
    //particle spread for emitter 4
    int m_spread4 = 2;
    //value between 0 and 255 for the red value for emitter 1
    float m_red1 = 1.0f;
    //value between 0 and 255 for the red value for emitter 2
    float m_red2 = 0.0f;
    //value between 0 and 255 for the red value for emitter 3
    float m_red3 = 0.0f;
    //value between 0 and 255 for the red value for emitter 4
    float m_red4 = 0.0f;
    //value between 0 and 255 for the green value for emitter 1
    float m_green1 = 0.0f;
    //value between 0 and 255 for the green value for emitter 2
    float m_green2 = 1.0f;
    //value between 0 and 255 for the green value for emitter 3
    float m_green3 = 0.0f;
    //value between 0 and 255 for the green value for emitter 4
    float m_green4 = 0.0f;
    //value between 0 and 255 for the blue value for emitter 1
    float m_blue1 = 0.0f;
    //value between 0 and 255 for the blue value for emitter 2
    float m_blue2 = 0.0f;
    //value between 0 and 255 for the blue value for emitter 3
    float m_blue3 = 1.0f;
    //value between 0 and 255 for the blue value for emitter 4
    float m_blue4 = 0.0f;
};

#endif
