#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //insert our NGLScene into the UI
    m_gl = new NGLScene(10);
    //the layout for our window
    ui->gridLayout->addWidget(m_gl, 0, 1, 2, 1);

    //connect together signals and slots
    //toggle edit emitter 1 on or off (check box)
    connect(ui->editEmitter1CheckBox, SIGNAL(clicked()), m_gl, SLOT(editEmitter1()));
    //toggle edit emitter 2 on or off (check box)
    connect(ui->editEmitter2CheckBox, SIGNAL(clicked()), m_gl, SLOT(editEmitter2()));
    //toggle edit emitter 3 on or off (check box)
    connect(ui->editEmitter3CheckBox, SIGNAL(clicked()), m_gl, SLOT(editEmitter3()));
    //toggle edit emitter 2 on or off (check box)
    connect(ui->editEmitter4CheckBox, SIGNAL(clicked()), m_gl, SLOT(editEmitter4()));
    //set gravity (slider)
    connect(ui->gravitySlider, SIGNAL(valueChanged(int)), m_gl, SLOT(setGravity(int)));
    //set number of particles (slider)
    connect(ui->numParticlesSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(setNumParticles(int)));
    //set particle size (slider)
    connect(ui->particleSizeSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(setParticleSize(int)));
    //set particle spread (slider)
    connect(ui->particleSpreadSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(setSpread(int)));
    //toggle single shot (check box)
    connect(ui->singleShotCheckBox, SIGNAL(clicked()), m_gl, SLOT(toggleSingleShot()));
    //add particles (button)
    connect(ui->addParticlesButton, SIGNAL (clicked()), m_gl, SLOT(addParticles()));
    //remove particles (button)
    connect(ui->removeParticlesButton, SIGNAL (clicked()), m_gl, SLOT(removeParticles()));
    //clear particles (button)
    connect(ui->clearParticlesButton, SIGNAL (clicked()), m_gl, SLOT(clearParticles()));
    //reset emitter (button)
    connect(ui->resetEmitterButton, SIGNAL (clicked()), m_gl, SLOT(resetEmitter()));
    //set red value for selected emitter (slider)
    connect(ui->redSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(redValue(int)));
    //set green value for selected emitter (slider)
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(greenValue(int)));
    //set blue value for selected emitter (slider)
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), m_gl, SLOT(blueValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editEmitter1CheckBox_clicked()
{
    if(ui->editEmitter1CheckBox->isChecked())
    {
        //emitter 1 can be edited
        m_emitter1Edit ^= true;
    }
    else
    {
        //emitter 1 can't be edited
        m_emitter1Edit ^= false;
    }
}

void MainWindow::editEmitter2CheckBox_clicked()
{
    if(ui->editEmitter2CheckBox->isChecked())
    {
        //emitter 2 can be edited
        m_emitter2Edit ^= true;
    }
    else
    {
        //emitter 2 can't be edited
        m_emitter2Edit ^= false;
    }
}

void MainWindow::editEmitter3CheckBox_clicked()
{
    if(ui->editEmitter3CheckBox->isChecked())
    {
        //emitter 3 can be edited
        m_emitter3Edit ^= true;
    }
    else
    {
        //emitter 3 can't be edited
        m_emitter3Edit ^= false;
    }
}

void MainWindow::editEmitter4CheckBox_clicked()
{
    if(ui->editEmitter4CheckBox->isChecked())
    {
        //emitter 4 can be edited
        m_emitter4Edit ^= true;
    }
    else
    {
        //emitter 4 can be edited
        m_emitter4Edit ^= false;
    }
}

void MainWindow::singleShotCheckBox_clicked()
{
    if(ui->singleShotCheckBox->isChecked())
    {
        //single shot is activated
        m_singleShot ^= true;
    }
    else
    {
        //single shot is deactivated
        m_singleShot ^= false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *_event)
{
    //key press events are happening in our NGLScene
    m_gl->keyPressEvent(_event);
}
