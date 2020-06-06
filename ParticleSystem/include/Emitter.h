#ifndef EMITTER_H_
#define EMITTER_H_

#include <vector>
#include "Particle.h"
#include <ngl/AbstractVAO.h>
#include <memory>
#include <ngl/Mat4.h>
#include <ngl/Transformation.h>

class Emitter
{
public :
    Emitter(size_t _numParticles, ngl::Vec3 _pos=0);
    ~Emitter() = default;
    void update();
    void draw();
    void up(float _dy);
    void down(float _dy);
    void left(float _dx);
    void right(float _dx);
    void in(float _dz);
    void out(float _dz);

private :
    //use io_p because this value is both an input and an output from this function
    void resetParticle(Particle & io_p);
    std::vector<Particle> m_particles;
    //load matrix to our shader
    void loadMatrixToShader(ngl::Transformation &_tx );
    //allocate vao once and reset the data for every frame we call draw to get the current particle data
    //std::unique_ptr<ngl::AbstractVAO> m_vao;
    //position of the emitter
    ngl::Vec3 m_pos;
    //direction of the emitter
    ngl::Vec3 m_dir;
    //viewing matrix
    ngl::Mat4 m_view;
    //projection matrix
    ngl::Mat4 m_project;
};

#endif
