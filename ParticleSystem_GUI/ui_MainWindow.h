/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QCheckBox *editEmitter1CheckBox;
    QCheckBox *editEmitter2CheckBox;
    QCheckBox *editEmitter3CheckBox;
    QCheckBox *editEmitter4CheckBox;
    QLabel *label_21;
    QSlider *gravitySlider;
    QLabel *label_22;
    QSlider *numParticlesSlider;
    QLabel *label_23;
    QSlider *particleSizeSlider;
    QLabel *label_24;
    QSlider *particleSpreadSlider;
    QCheckBox *singleShotCheckBox;
    QPushButton *addParticlesButton;
    QPushButton *removeParticlesButton;
    QPushButton *clearParticlesButton;
    QPushButton *resetEmitterButton;
    QLabel *label_25;
    QLabel *label;
    QSlider *redSlider;
    QLabel *label_2;
    QSlider *greenSlider;
    QLabel *label_3;
    QSlider *blueSlider;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAnimated(true);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 211, 806));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(scrollAreaWidgetContents_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        editEmitter1CheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        editEmitter1CheckBox->setObjectName(QString::fromUtf8("editEmitter1CheckBox"));
        editEmitter1CheckBox->setChecked(true);

        verticalLayout_2->addWidget(editEmitter1CheckBox);

        editEmitter2CheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        editEmitter2CheckBox->setObjectName(QString::fromUtf8("editEmitter2CheckBox"));

        verticalLayout_2->addWidget(editEmitter2CheckBox);

        editEmitter3CheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        editEmitter3CheckBox->setObjectName(QString::fromUtf8("editEmitter3CheckBox"));

        verticalLayout_2->addWidget(editEmitter3CheckBox);

        editEmitter4CheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        editEmitter4CheckBox->setObjectName(QString::fromUtf8("editEmitter4CheckBox"));

        verticalLayout_2->addWidget(editEmitter4CheckBox);

        label_21 = new QLabel(scrollAreaWidgetContents_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_21);

        gravitySlider = new QSlider(scrollAreaWidgetContents_2);
        gravitySlider->setObjectName(QString::fromUtf8("gravitySlider"));
        gravitySlider->setToolTipDuration(-1);
        gravitySlider->setAutoFillBackground(false);
        gravitySlider->setMaximum(50);
        gravitySlider->setValue(10);
        gravitySlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(gravitySlider);

        label_22 = new QLabel(scrollAreaWidgetContents_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_22);

        numParticlesSlider = new QSlider(scrollAreaWidgetContents_2);
        numParticlesSlider->setObjectName(QString::fromUtf8("numParticlesSlider"));
        numParticlesSlider->setMaximum(100000);
        numParticlesSlider->setValue(1000);
        numParticlesSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(numParticlesSlider);

        label_23 = new QLabel(scrollAreaWidgetContents_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_23);

        particleSizeSlider = new QSlider(scrollAreaWidgetContents_2);
        particleSizeSlider->setObjectName(QString::fromUtf8("particleSizeSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(particleSizeSlider->sizePolicy().hasHeightForWidth());
        particleSizeSlider->setSizePolicy(sizePolicy3);
        particleSizeSlider->setAutoFillBackground(false);
        particleSizeSlider->setMinimum(1);
        particleSizeSlider->setMaximum(50);
        particleSizeSlider->setValue(5);
        particleSizeSlider->setOrientation(Qt::Horizontal);
        particleSizeSlider->setTickPosition(QSlider::NoTicks);

        verticalLayout_2->addWidget(particleSizeSlider);

        label_24 = new QLabel(scrollAreaWidgetContents_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy2.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_24);

        particleSpreadSlider = new QSlider(scrollAreaWidgetContents_2);
        particleSpreadSlider->setObjectName(QString::fromUtf8("particleSpreadSlider"));
        particleSpreadSlider->setMinimum(1);
        particleSpreadSlider->setMaximum(20);
        particleSpreadSlider->setSingleStep(1);
        particleSpreadSlider->setValue(2);
        particleSpreadSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(particleSpreadSlider);

        singleShotCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        singleShotCheckBox->setObjectName(QString::fromUtf8("singleShotCheckBox"));

        verticalLayout_2->addWidget(singleShotCheckBox);

        addParticlesButton = new QPushButton(scrollAreaWidgetContents_2);
        addParticlesButton->setObjectName(QString::fromUtf8("addParticlesButton"));

        verticalLayout_2->addWidget(addParticlesButton);

        removeParticlesButton = new QPushButton(scrollAreaWidgetContents_2);
        removeParticlesButton->setObjectName(QString::fromUtf8("removeParticlesButton"));

        verticalLayout_2->addWidget(removeParticlesButton);

        clearParticlesButton = new QPushButton(scrollAreaWidgetContents_2);
        clearParticlesButton->setObjectName(QString::fromUtf8("clearParticlesButton"));

        verticalLayout_2->addWidget(clearParticlesButton);

        resetEmitterButton = new QPushButton(scrollAreaWidgetContents_2);
        resetEmitterButton->setObjectName(QString::fromUtf8("resetEmitterButton"));

        verticalLayout_2->addWidget(resetEmitterButton);

        label_25 = new QLabel(scrollAreaWidgetContents_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_25);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label);

        redSlider = new QSlider(scrollAreaWidgetContents_2);
        redSlider->setObjectName(QString::fromUtf8("redSlider"));
        redSlider->setMaximum(255);
        redSlider->setValue(0);
        redSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(redSlider);

        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_2);

        greenSlider = new QSlider(scrollAreaWidgetContents_2);
        greenSlider->setObjectName(QString::fromUtf8("greenSlider"));
        greenSlider->setMaximum(255);
        greenSlider->setValue(0);
        greenSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(greenSlider);

        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_3);

        blueSlider = new QSlider(scrollAreaWidgetContents_2);
        blueSlider->setObjectName(QString::fromUtf8("blueSlider"));
        blueSlider->setMaximum(255);
        blueSlider->setValue(0);
        blueSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(blueSlider);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(775, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Particle System", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "EMITTER CONTROLS", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Keys:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "esc - close | space - reset view", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "1 to 4 - toggle emitter visibilty ", nullptr));
#if QT_CONFIG(tooltip)
        editEmitter1CheckBox->setToolTip(QCoreApplication::translate("MainWindow", "check to edit first emmitter", nullptr));
#endif // QT_CONFIG(tooltip)
        editEmitter1CheckBox->setText(QCoreApplication::translate("MainWindow", "Edit Emitter 1", nullptr));
#if QT_CONFIG(tooltip)
        editEmitter2CheckBox->setToolTip(QCoreApplication::translate("MainWindow", "check to edit second emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        editEmitter2CheckBox->setText(QCoreApplication::translate("MainWindow", "Edit Emitter 2", nullptr));
#if QT_CONFIG(tooltip)
        editEmitter3CheckBox->setToolTip(QCoreApplication::translate("MainWindow", "check to edit third emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        editEmitter3CheckBox->setText(QCoreApplication::translate("MainWindow", "Edit Emitter 3", nullptr));
#if QT_CONFIG(tooltip)
        editEmitter4CheckBox->setToolTip(QCoreApplication::translate("MainWindow", "check to edit fourth emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        editEmitter4CheckBox->setText(QCoreApplication::translate("MainWindow", "Edit Emitter 4", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Gravity", nullptr));
#if QT_CONFIG(tooltip)
        gravitySlider->setToolTip(QCoreApplication::translate("MainWindow", "Gravity applied to selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("MainWindow", "Number of Particles", nullptr));
#if QT_CONFIG(tooltip)
        numParticlesSlider->setToolTip(QCoreApplication::translate("MainWindow", "Number of partciles created for slected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("MainWindow", "Particle Size", nullptr));
#if QT_CONFIG(tooltip)
        particleSizeSlider->setToolTip(QCoreApplication::translate("MainWindow", "Size of the particles for selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_24->setText(QCoreApplication::translate("MainWindow", "Particle Spread", nullptr));
#if QT_CONFIG(tooltip)
        particleSpreadSlider->setToolTip(QCoreApplication::translate("MainWindow", "The spread of the particles for the selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        singleShotCheckBox->setToolTip(QCoreApplication::translate("MainWindow", "toggle a single shot of particles on and off", nullptr));
#endif // QT_CONFIG(tooltip)
        singleShotCheckBox->setText(QCoreApplication::translate("MainWindow", "Single Shot", nullptr));
#if QT_CONFIG(tooltip)
        addParticlesButton->setToolTip(QCoreApplication::translate("MainWindow", "Add particles to selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        addParticlesButton->setText(QCoreApplication::translate("MainWindow", "Add Particles", nullptr));
#if QT_CONFIG(tooltip)
        removeParticlesButton->setToolTip(QCoreApplication::translate("MainWindow", "Remove particles from selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        removeParticlesButton->setText(QCoreApplication::translate("MainWindow", "Remove Particles", nullptr));
#if QT_CONFIG(tooltip)
        clearParticlesButton->setToolTip(QCoreApplication::translate("MainWindow", "Clear particles for selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        clearParticlesButton->setText(QCoreApplication::translate("MainWindow", "Clear Particles", nullptr));
#if QT_CONFIG(tooltip)
        resetEmitterButton->setToolTip(QCoreApplication::translate("MainWindow", "Reset the system", nullptr));
#endif // QT_CONFIG(tooltip)
        resetEmitterButton->setText(QCoreApplication::translate("MainWindow", "Reset Emitter", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Colour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
#if QT_CONFIG(tooltip)
        redSlider->setToolTip(QCoreApplication::translate("MainWindow", "red channel values for selected emitter ", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
#if QT_CONFIG(tooltip)
        greenSlider->setToolTip(QCoreApplication::translate("MainWindow", "Green values for selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(tooltip)
        blueSlider->setToolTip(QCoreApplication::translate("MainWindow", "Blue Values for selected emitter", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
