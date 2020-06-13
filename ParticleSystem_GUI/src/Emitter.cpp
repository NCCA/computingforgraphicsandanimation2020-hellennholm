#include "Emitter.h"

#include <iostream>
#include <ngl/Random.h>
#include <ngl/NGLStream.h>
#include <ngl/SimpleVAO.h>
#include <ngl/VAOFactory.h>

Emitter::Emitter(size_t _numParticles, ngl::Vec3 _emitterPos, float _spread, ngl::Vec3 _emitDir)
{
    //emitter's position
    m_emitterPos = _emitterPos;
    //the spread
    m_spread = _spread;
    //the emission direction of the particles
    m_emitDir = _emitDir;
    //resize the particle system to be the same size as the number of particles in the scene
    m_particles.resize(_numParticles);
    //range based for loop to loop over every particle
    //&p gives us a reference to the actual value rather than a copy of this value
    for (auto &p : m_particles)
    {
        //reset the particle to its default
        resetParticle(p, _spread);
    }
    //create our vao
    //use GL_POINTS becaus ethat is how we want to draw our particles
    m_vao = ngl::VAOFactory::createVAO(ngl::simpleVAO, GL_POINTS);
}

void Emitter::resetEmitter(size_t _numParticles, int _spread)
{
    //resize the particle system to be the same size as the number of particles in the scene
    m_particles.resize(_numParticles);
    //range based for loop to loop over every particle
    //&p gives us a reference to the actual value rather than a copy of this value
    for (auto &p : m_particles)
    {
        //reset the particle to its default
        resetParticle(p, _spread);
    }
}

void Emitter::toggleSingleShot()
{
    //toggle on second emitter to true
    m_singleShot ^= true;
}

void Emitter::resetParticle(Particle &io_p, int _spread)
{
    //std::cout << "_spread" << '\n';
    //grab an instance of ngl/Random.h
    auto rng = ngl::Random::instance();
    //set initial positon of particle to be the same as the emitter's position
    io_p.pos = m_emitterPos;
    //set the direction of the particle
    io_p.dir = m_emitDir + randomVectorOnSphere() * _spread;
    //clamp position along y to positive
    io_p.dir.m_y = std::abs(io_p.dir.m_y);
    //set maxLife to a random positive number between 0 and 100
    //randomPositveNumber will give a float so we need to cast it to an int
    io_p.maxLife = static_cast<int>(rng->randomPositiveNumber(50000))+500;
    //default life to 0
    io_p.life = 0;
}

void Emitter::collisionDet(Particle &io_p, float _deltaT, int _gravityY)
{
    //the gravity applied to the scene
    ngl::Vec3 gravity(0, -_gravityY, 0);
    //if the particle hits the ground plane
    if (io_p.pos.m_y <= 0.2f)
    {
        //inverse its direction
        io_p.dir.m_y = -io_p.dir.m_y * 0.6f;
        //update its position
        io_p.pos.m_y += 0.5f * gravity.m_y * (_deltaT * _deltaT) + io_p.dir.m_y * _deltaT;
        //if the particle hits the edge of the volume along x
        if (io_p.pos.m_x <= -30.0f || io_p.pos.m_x >= 30.0f)
        {
            //inverse its direction and remove a little of its height to simulate friction
            io_p.dir.m_x = -io_p.dir.m_x;
            //if the particle hits the edge of the volume along z
            if (io_p.pos.m_z <= -30.0f || io_p.pos.m_z >= 30.0f)
            {
                //inverse its direction and remove a little of its height to simulate friction
                io_p.dir.m_z = -io_p.dir.m_z;
            }
        }
    }
}

void Emitter::update(float _deltaT, int _gravityY, int _numParticles, int _spread)
{
    //resize the particle system to be the same size as the number of particles in the scene
    //m_particles.resize(_numParticles); //MAYBE REMOVE
    //the gravity applied to the scene
    ngl::Vec3 gravity(0.0f, -_gravityY, 0.0f);
    for (auto &p : m_particles)
    {
        //p.dir is our velocity at the previous frame
        p.dir += gravity * _deltaT * 0.5f;
        //we find our position by doing the second derivative of the acceleration, here gravity = acceleration
        p.pos += 0.5f * gravity * (_deltaT * _deltaT) + p.dir * _deltaT;
        //if single shot is off
        if (! m_singleShot)
        {
            collisionDet(p, _deltaT, _gravityY);
            //if the particle's life exceeds its maxLife reset it to its default;
            if (++p.life >= p.maxLife || p.pos.m_y < 0.0f)
            {
                resetParticle(p, _spread);
            }
        }

    }
    //if we are in single shot mode
    if (m_singleShot)
    {
        for (auto &p : m_particles)
        {
            collisionDet(p, _deltaT, _gravityY);
        }
        m_particles.erase(
                    std::remove_if(std::begin(m_particles), std::end(m_particles), //set a range
                                   [](const Particle &p) {return (p.life >= p.maxLife || p.pos.m_y < 0.0f); }), //give a condition
                    std::end(m_particles)); //end of the list to work through
    }
}

void Emitter::draw() const
{
    //this says if there are no particles don't bother trying to draw
    if (m_particles.size() == 0)
    {
        return;
    }
    //the vao must be bound
    m_vao->bind();
    //set the data for this vao by passing to it the data structure we want to use - in this case the whole of the std vector for Particles
    //VertexData class takes a pointer to where that data is and its size
    m_vao->setData(ngl::SimpleVAO::VertexData(m_particles.size()*sizeof(Particle), m_particles[0].pos.m_x));
    //tell openGL how this data is formatted
    m_vao->setVertexAttributePointer(0, 3, GL_FLOAT, sizeof(Particle), 0);
    //offset is 6 because the colour is 6 floats in
    m_vao->setVertexAttributePointer(1, 3, GL_FLOAT, sizeof(Particle), 6);
    //tell the vao how many elements there are to draw
    m_vao->setNumIndices(m_particles.size());
    //call draw()
    m_vao->draw();
    //for every bind there must be an unbind
    m_vao->unbind();
}

void Emitter::up(float _dy)
{
    m_emitterPos.m_y += _dy;
}

void Emitter::down(float _dy)
{
    m_emitterPos.m_y -= _dy;
}

void Emitter::left(float _dx)
{
    m_emitterPos.m_x -= _dx;
}

void Emitter::right(float _dx)
{
    m_emitterPos.m_x += _dx;
}

void Emitter::in(float _dz)
{
    m_emitterPos.m_z -= _dz;
}

void Emitter::out(float _dz)
{
    m_emitterPos.m_z += _dz;
}

void Emitter::addParticles(int _spread)
{
    //std::cout << _spread << '\n';
    //create a new particle
    Particle p;
    //give the particles default values
    resetParticle(p, _spread);
    //add to the current std::vector this new particle
    m_particles.push_back(p);
}

void Emitter::removeParticles()
{
    //so long as there are particles in the scene we can remove them using pop_back which will remove the most recent particle
    if (m_particles.size() != 0)
    {
        m_particles.pop_back();
    }
}

void Emitter::clearParticles()
{
    //clear the particles
    m_particles.clear();
}

ngl::Vec3 Emitter::randomVectorOnSphere(float _radius)
{
    //load in Random.h instance
    auto rng = ngl::Random::instance();
    //phi will have a value between 0 and 2 pi
    float phi = rng->randomPositiveNumber(static_cast<float>(M_PI * 2.0f));
    //generate cosine of our angle which is a random number between -1 and 1
    float costheta = rng->randomNumber();
    //positive value between 0 and 1
    float u = rng->randomPositiveNumber();
    //gives us our angle
    float theta = acos(costheta);
    //gives us r (the first parameter for our polar coordinate) as a function of the radius the cube root of u
    float r = _radius * std::cbrt(u);
    //return cartesian coordinates based off our polar coordinates
    return ngl::Vec3 (r * sin(theta) * cos(phi),
                      r * sin(theta) * sin(phi),
                      r * cos(theta));
}





