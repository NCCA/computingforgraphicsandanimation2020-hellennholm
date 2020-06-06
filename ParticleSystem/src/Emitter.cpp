#include "Emitter.h"
#include <iostream>
#include <ngl/Random.h>
#include <ngl/NGLStream.h>
#include <ngl/SimpleVAO.h>
#include <ngl/VAOFactory.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Transformation.h>
#include <ngl/ShaderLib.h>
#include <ngl/Util.h>

Emitter::Emitter(size_t _numParticles, ngl::Vec3 _pos)
{
    m_pos = _pos;
    //std::cout << m_pos << '\n';
    //resize particles structure to be the same as the number of particles
    m_particles.resize(_numParticles);
    //range based for loop to loop over every particle and assign a position, direction and maxLife
    for (auto &p : m_particles)
    {
        resetParticle(p);
    }
}

void Emitter::loadMatrixToShader(ngl::Transformation &_tx)
{
    ngl::Transformation tx;
    auto shader = ngl::ShaderLib::instance();
    shader->use("ParticleShader");
    auto MVP = m_project * m_view * tx.getPosition();
    shader->setUniform("MVP", MVP);
}

//this function makes it easier to change how the particle behaves and settign defaults
void Emitter::resetParticle(Particle& io_p)
{
    auto shader = ngl::ShaderLib::instance();
    ngl::VAOPrimitives::instance()->createSphere("sphere",1.5f,20.0f);
    shader->setUniform("particleColour", 1.0f,0.0f,0.0f);
    ngl::Transformation tx;
    auto rng = ngl::Random::instance();
    io_p.pos = rng->getRandomVec3();
    io_p.dir = rng->getRandomVec3();
    //io_p.pos += io_p.dir;
    tx.setPosition(io_p.pos);
    //std::cout << io_p.pos << '\n';
    //tx.setScale(1.0f,1.0f,1.0f);
    //clamp our values so that our particles never go down past 0 on the y axis
    //io_p.dir.m_y = std::abs(io_p.dir.m_y)+0.1f;
    io_p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
    io_p.life = 0;

    loadMatrixToShader(tx);
    ngl::VAOPrimitives::instance()->draw("sphere");

}

//update the particle's position and status
void Emitter::update()
{
    ngl::Transformation tx;
    //auto shader = ngl::ShaderLib::instance();
    //for loop updating the position of the particle based on the direction
    for (auto &p : m_particles)
    {
        p.pos += p.dir;
        tx.setPosition(p.pos);
        std::cout << p.pos << '\n';

        //reset the particle if it reaches the end of its life
        if (++p.life >= p.maxLife)
        {
            resetParticle(p);
        }
    }
}

void Emitter::draw()
{
    update();
}

void Emitter::up(float _dy)
{
    m_pos.m_y += _dy;
}
void Emitter::down(float _dy)
{
    m_pos.m_y -= _dy;
}
void Emitter::left(float _dx)
{
    m_pos.m_x -= _dx;
}
void Emitter::right(float _dx)
{
    m_pos.m_y += _dx;
}
void Emitter::in(float _dz)
{
    m_pos.m_y -= _dz;
}
void Emitter::out(float _dz)
{
    m_pos.m_y += _dz;
}
