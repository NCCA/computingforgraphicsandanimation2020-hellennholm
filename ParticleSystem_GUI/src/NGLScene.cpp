#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include <ngl/ShaderLib.h>
#include <ngl/Util.h>
#include <ngl/Random.h>
#include <ngl/VAOPrimitives.h>
#include <QEvent>

NGLScene::NGLScene(size_t _numParticles, QWidget *_parent) : QOpenGLWidget(_parent)
{
  //reset the random seed every time the program is run so that the values are not the same every time
  ngl::Random::instance()->setSeed();
}


NGLScene::~NGLScene()
{
  //when the program is closed
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}

void NGLScene::resizeGL(int _w , int _h)
{
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
  //set our projection matrix
  m_project = ngl::perspective(45.0f, static_cast<float>(_w)/_h, 0.1f, 300.0f);
}

void NGLScene::toggleEmitter1()
{
    //toggle on the first emitter to true
    m_emitter1Visibility ^= true;
}

void NGLScene::toggleEmitter2()
{
    //toggle on the second emitter to true
    m_emitter2Visibility ^= true;
}

void NGLScene::toggleEmitter3()
{
    //toggle on the third emitter to true
    m_emitter3Visibility ^= true;
}

void NGLScene::toggleEmitter4()
{
    //toggle on the fourth emitter to true
    m_emitter4Visibility ^= true;
}

void NGLScene::initializeGL()
{
  // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
  // be done once we have a valid GL context but before we call any GL commands. If we dont do
  // this everything will crash
  ngl::NGLInit::instance();
  //Background Colour
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);
  //load an instance of the ngl ShaderLib
  auto shader = ngl::ShaderLib::instance();
  //load in our fragment and vertex shaders
  shader->loadShader("ParticleShader",
                     "shaders/ParticleVertex.glsl",
                     "shaders/ParticleFragment.glsl");
  //activate the ParticleShader
  shader->use("ParticleShader");
  //set camera view
  m_view = ngl::lookAt({0,25,100}, ngl::Vec3::zero(), ngl::Vec3::up());
  //create this as the identity marix
  shader->setUniform("MVP", m_project * m_view);
  //instanciate the particle system with a specific amount of particles, taken from the command line (default is 2000)
  //a position for the emitter
  //and the spread
  //create emitter_1
  m_emitter_1 = std::make_unique<Emitter> (m_numParticles1, ngl::Vec3 (-30.0f, 15.0f, 30.0f), m_spread1, ngl::Vec3 (5.0f,5.0f,-5.0f));
  //create emitter_2
  m_emitter_2 = std::make_unique<Emitter> (m_numParticles2, ngl::Vec3 (30.0f, 15.0f, -30.0f), m_spread2, ngl::Vec3 (-5.0f,5.0f,5.0f));
  //create emitter_3
  m_emitter_3 = std::make_unique<Emitter> (m_numParticles3, ngl::Vec3 (-30.0f, 15.0f, -30.0f), m_spread3, ngl::Vec3 (5.0f,5.0f,5.0f));
  //create emitter_4
  m_emitter_4 = std::make_unique<Emitter> (m_numParticles4, ngl::Vec3 (30.0f, 15.0f, 30.0f), m_spread4, ngl::Vec3 (-5.0f,5.0f,-5.0f));
  //invoke the method directly from the instance
  //ngl::Vec3::sup() is the direction of the normals which here is a generic up vector
  ngl::VAOPrimitives::instance()->createTrianglePlane("ground", 200, 200, 1, 1, ngl::Vec3::up());
  //activate the CheckerShader
  shader->use(ngl::nglCheckerShader);
  //set light position
  shader->setUniform("lightPos", 0.0f, 50.0f, 0.0f);
  //set light colour, named lightDiffuse - This takes and alpha parameter, set to 1.0f here
  shader->setUniform("lightDiffuse", 1.0f, 1.0f, 1.0f, 1.0f);
  //set our check size, bigger the number the smaller the checks' size
  shader->setUniform("checkSize", 30.0f);
  //our check shader is on
  shader->setUniform("checkOn", true);
  //set the two colours for our checks - has an alpha parameter
  shader->setUniform("colour1", 0.7f, 0.7f, 0.7f, 1.0f);
  shader->setUniform("colour2", 0.6f, 0.6f, 0.6f, 1.0f);
  //set our normal matrix
  shader->setUniform("normalMatrix", ngl::Mat3());
  //trigger a timer
  startTimer(0);
  //set our previous time based on current time, which we get from now()
  m_previousTime = std::chrono::high_resolution_clock::now();
}



void NGLScene::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_win.width,m_win.height);
  //set the shader every frame
  auto shader = ngl::ShaderLib::instance();

  ngl::Mat4 xrot;
  ngl::Mat4 yrot;
  //two spins that come directly from the mouse
  xrot.rotateX(m_win.spinXFace);
  yrot.rotateY(m_win.spinYFace);
  //calculate global mouse translation
  m_globalMouseTX = yrot * xrot;
  //assign values to our global mouse translation matrix
  m_globalMouseTX.m_m[3][0] = m_modelPos.m_x;
  m_globalMouseTX.m_m[3][1] = m_modelPos.m_y;
  m_globalMouseTX.m_m[3][2] = m_modelPos.m_z;
  //set our particle shader for ouur particles
  shader->use("ParticleShader");
  //transformation that we use in the shader
  shader->setUniform("MVP", m_project * m_view * m_globalMouseTX);
  //if first emitter is toggled draw it
  if (m_emitter1Visibility)
  {
      //set point size for emitter 1 particles
      glPointSize(m_particleSize1);
      //set the particles' colour for emitter1
      shader->setUniform("particleColour", m_red1, m_green1, m_blue1);
      //call the draw method of the emitter
      m_emitter_1->draw();
  }
  //if second emitter is toggled draw it
  if (m_emitter2Visibility)
  {
      //set point size for emitter 2 particles
      glPointSize(m_particleSize2);
      //set the particles' colour for emitter2
      shader->setUniform("particleColour", m_red2, m_green2, m_blue2);
      //call the draw method of the emitter
      m_emitter_2->draw();
  }
  //if third emitter is toggled draw it
  if (m_emitter3Visibility)
  {
      //set point size for emitter 3 particles
      glPointSize(m_particleSize3);
      //set the particles' colour for emitter3
      shader->setUniform("particleColour", m_red3, m_green3, m_blue3);
      //call the draw method of the emitter
      m_emitter_3->draw();
  }
  //if fourth emitter is toggled draw it
  if (m_emitter4Visibility)
  {
      //set point size for emitter 4 particles
      glPointSize(m_particleSize4);
      //set the particles' colour for emitter4
      shader->setUniform("particleColour", m_red4, m_green4, m_blue4);
      //call the draw method of the emitter
      m_emitter_4->draw();
  }
  //set our check shader for our ground plane
  shader->use(ngl::nglCheckerShader);
  //every frame we need to reset our MVP for both the particles and the ground
  shader->setUniform("MVP", m_project * m_view * m_globalMouseTX);
  //draw the ground plane
  ngl::VAOPrimitives::instance()->draw("ground");
}

void NGLScene::timerEvent(QTimerEvent *)
{
    //set our current time
    auto currentTime = std::chrono::high_resolution_clock::now();
    //calculate the time difference between our currentTime and our previousTime - delta in floating point value
    auto delta = std::chrono::duration<float, std::chrono::seconds::period> (currentTime - m_previousTime).count();
    //for each emitter call the update method from the emitter class
    m_emitter_1->update(delta, m_gravity1, m_numParticles1, m_spread1);
    m_emitter_2->update(delta, m_gravity2, m_numParticles2, m_spread2);
    m_emitter_3->update(delta, m_gravity3, m_numParticles3, m_spread3);
    m_emitter_4->update(delta, m_gravity4, m_numParticles4, m_spread4);
    //call the draw function for NGL
    update();
    //record what the previous time was for the next calculation
    m_previousTime = currentTime;
}

//----------------------------------------------------------------------------------------------------------------------
//UI Elements

void NGLScene::editEmitter1()
{
    m_emitter1Edit ^= true;
}

void NGLScene::editEmitter2()
{
    m_emitter2Edit ^= true;
}

void NGLScene::editEmitter3()
{
    m_emitter3Edit ^= true;
}

void NGLScene::editEmitter4()
{
    m_emitter4Edit ^= true;
}

void NGLScene::setGravity(int _gravityY)
{
    //if statements depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //get updated gravity value
        m_gravity1 = _gravityY;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if (m_emitter2Edit)
    {
        m_gravity2 = _gravityY;
        update();
    }
    //edit emitter 3
    if (m_emitter3Edit)
    {
        m_gravity3 = _gravityY;
        update();
    }
    //edit emitter 4
    if (m_emitter4Edit)
    {
        m_gravity4 = _gravityY;
        update();
    }
}

void NGLScene::setNumParticles(int _numParticles)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //get updated number of particles
        m_numParticles1 = _numParticles;
        //reset the emitter with the updated number of particles
        m_emitter_1->resetEmitter(m_numParticles1, m_spread1);
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if (m_emitter2Edit)
    {
        m_numParticles2 = _numParticles;
        m_emitter_2->resetEmitter(m_numParticles2, m_spread2);
        update();
    }
    //edit emitter 3
    if (m_emitter3Edit)
    {
        m_numParticles3 = _numParticles;
        m_emitter_3->resetEmitter(m_numParticles3, m_spread3);
        update();
    }
    //edit emitter 4
    if (m_emitter4Edit)
    {
        m_numParticles4 = _numParticles;
        m_emitter_4->resetEmitter(m_numParticles4, m_spread4);
        update();
    }
}

void NGLScene::setParticleSize(int _particleSize)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //get updated particle size
        m_particleSize1 = _particleSize;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if (m_emitter2Edit)
    {
        m_particleSize2 = _particleSize;
        update();
    }
    //edit emitter 3
    if (m_emitter3Edit)
    {
        m_particleSize3 = _particleSize;
        update();
    }
    //edit emitter 4
    if (m_emitter4Edit)
    {
        m_particleSize4 = _particleSize;
        update();
    }
}

void NGLScene::setSpread(int _spread)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //get updated particle size
        m_spread1 = _spread;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if (m_emitter2Edit)
    {
        m_spread2 = _spread;
        update();
    }
    //edit emitter 3
    if (m_emitter3Edit)
    {
        m_spread3 = _spread;
        update();
    }
    //edit emitter 4
    if (m_emitter4Edit)
    {
        m_spread4 = _spread;
        update();
    }
}

void NGLScene::toggleSingleShot()
{
    //wire this into toggleSingleShot method in the Emitter class
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //single shot for emitter 1
        m_emitter_1->toggleSingleShot();
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_emitter_2->toggleSingleShot();
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_emitter_3->toggleSingleShot();
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_emitter_4->toggleSingleShot();
        update();
    }
}

void NGLScene::addParticles()
{
    //wire this into the add particles method in Emitter class
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //add particles to emitter 1
        m_emitter_1->addParticles(m_spread1);
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_emitter_2->addParticles(m_spread2);
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_emitter_3->addParticles(m_spread3);
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_emitter_4->addParticles(m_spread4);
        update();
    }
}

void NGLScene::removeParticles()
{
    //wire this into the remove particles method in Emitter class
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if (m_emitter1Edit)
    {
        //remove particles from emitter 1
        m_emitter_1->removeParticles();
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_emitter_2->removeParticles();
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_emitter_3->removeParticles();
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_emitter_4->removeParticles();
        update();
    }
}

void NGLScene::clearParticles()
{
    //wire this into the clear particles method in Emitter class
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //clear particles from emitter 1
        m_emitter_1->clearParticles();
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_emitter_2->clearParticles();
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_emitter_3->clearParticles();
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_emitter_4->clearParticles();
        update();
    }
}

void NGLScene::resetEmitter()
{
    //wire this into the reset particles method in Emitter class
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //reset emitter 1
        m_emitter_1->resetEmitter(m_numParticles1, m_spread1);
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_emitter_2->resetEmitter(m_numParticles2, m_spread2);
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_emitter_3->resetEmitter(m_numParticles3, m_spread3);
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_emitter_4->resetEmitter(m_numParticles4, m_spread4);
        update();
    }
}

void NGLScene::redValue(int _red)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //cast the integer we get from the slider to a float
        m_red1 = static_cast<float>(_red);
        //devide this float by 255 so that we get a float value between 0 and 1 to use as our rgb value
        m_red1 = m_red1/255.0f;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_red2 = static_cast<float>(_red);
        m_red2 = m_red2/255.0f;
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_red3 = static_cast<float>(_red);
        m_red3 = m_red3/255.0f;
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_red4 = static_cast<float>(_red);
        m_red4 = m_red4/255.0f;
        update();
    }
}

void NGLScene::greenValue(int _green)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //cast the integer we get from the slider to a float
        m_green1 = static_cast<float>(_green);
        //devide this float by 255 so that we get a float value between 0 and 1 to use as our rgb value
        m_green1 = m_green1/255.0f;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_green2 = static_cast<float>(_green);
        m_green2 = m_green2/255.0f;
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_green3 = static_cast<float>(_green);
        m_green3 = m_green3/255.0f;
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_green4 = static_cast<float>(_green);
        m_green4 = m_green4/255.0f;
        update();
    }
}

void NGLScene::blueValue(int _blue)
{
    //if loop depending on chosen emitters to edit
    //edit emitter 1
    if(m_emitter1Edit)
    {
        //cast the integer we get from the slider to a float
        m_blue1 = static_cast<float>(_blue);
        //devide this float by 255 so that we get a float value between 0 and 1 to use as our rgb value
        m_blue1 = m_blue1/255.0f;
        //tell the UI that it needs to be updated
        update();
    }
    //edit emitter 2
    if(m_emitter2Edit)
    {
        m_blue2 = static_cast<float>(_blue);
        m_blue2 = m_blue2/255.0f;
        update();
    }
    //edit emitter 3
    if(m_emitter3Edit)
    {
        m_blue3 = static_cast<float>(_blue);
        m_blue3 = m_blue3/255.0f;
        update();
    }
    //edit emitter 4
    if(m_emitter4Edit)
    {
        m_blue4 = static_cast<float>(_blue);
        m_blue4 = m_blue4/255.0f;
        update();
    }
}

//----------------------------------------------------------------------------------------------------------------------
//Mouse Controls

void NGLScene::keyPressEvent(QKeyEvent *_event)
{

  //set constant value for the movement of the emitter
  constexpr float move = 0.5f;
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
      // escape key to quit
      case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
      case Qt::Key_Space :
          m_win.spinXFace=0;
          m_win.spinYFace=0;
          m_modelPos.set(ngl::Vec3::zero());

      break;
      //using up,down,left,right,I and O keys on keyboard to move the emitters around
      case Qt::Key_Left:
          //move emitter 1 to the left
          if(m_emitter1Edit)
          {
            m_emitter_1->left(move);
          }
          //move emitter 2 to the left
          if(m_emitter2Edit)
          {
            m_emitter_2->left(move);
          }
          //move emitter 3 to the left
          if(m_emitter3Edit)
          {
            m_emitter_3->left(move);
          }
          //move emitter 4 to the left
          if(m_emitter4Edit)
          {
            m_emitter_4->left(move);
          }
      break;
      case Qt::Key_Right:
          //move emitter 1 to the right
          if(m_emitter1Edit)
          {
            m_emitter_1->right(move);
          }
          //move emitter 2 to the right
          if(m_emitter2Edit)
          {
            m_emitter_2->right(move);
          }
          //move emitter 3 to the right
          if(m_emitter3Edit)
          {
            m_emitter_3->right(move);
          }
          //move emitter 4 to the right
          if(m_emitter4Edit)
          {
            m_emitter_4->right(move);
          }
      break;
      case Qt::Key_Up:
          //move emitter 1 up
          if(m_emitter1Edit)
          {
            m_emitter_1->up(move);
          }
          //move emitter 2 up
          if(m_emitter2Edit)
          {
            m_emitter_2->up(move);
          }
          //move emitter 3 up
          if(m_emitter3Edit)
          {
            m_emitter_3->up(move);
          }
          //move emitter 4 up
          if(m_emitter4Edit)
          {
            m_emitter_4->up(move);
          }
      break;
      case Qt::Key_Down:
          //move emitter 1 down
          if(m_emitter1Edit)
          {
            m_emitter_1->down(move);
          }
          //move emitter 2 down
          if(m_emitter2Edit)
          {
            m_emitter_2->down(move);
          }
          //move emitter 3 down
          if(m_emitter3Edit)
          {
            m_emitter_3->down(move);
          }
          //move emitter 4 down
          if(m_emitter4Edit)
          {
            m_emitter_4->down(move);
          }
      break;
      case Qt::Key_I:
          //move emitter 1 in
          if(m_emitter1Edit)
          {
            m_emitter_1->in(move);
          }
          //move emitter 2 in
          if(m_emitter2Edit)
          {
            m_emitter_2->in(move);
          }
          //move emitter 3 in
          if(m_emitter3Edit)
          {
            m_emitter_3->in(move);
          }
          //move emitter 4 in
          if(m_emitter4Edit)
          {
            m_emitter_4->in(move);
          }
      break;
      case Qt::Key_O:
          //move emitter 1 out
          if(m_emitter1Edit)
          {
            m_emitter_1->out(move);
          }
          //move emitter 2 out
          if(m_emitter2Edit)
          {
            m_emitter_2->out(move);
          }
          //move emitter 3 out
          if(m_emitter3Edit)
          {
            m_emitter_3->out(move);
          }
          //move emitter 4 out
          if(m_emitter4Edit)
          {
            m_emitter_4->out(move);
          }
      break;
      //toggle visibilty of all four emitters on or off
      case Qt::Key_1: toggleEmitter1(); std::cout << "emitter 1 on \n "; break;
      case Qt::Key_2: toggleEmitter2(); std::cout << "emitter 2 on \n "; break;
      case Qt::Key_3: toggleEmitter3(); std::cout << "emitter 3 on \n "; break;
      case Qt::Key_4: toggleEmitter4(); std::cout << "emitter 4 on \n "; break;
      default : break;
  }
  // finally update the GLWindow and re-draw
  update();
}

