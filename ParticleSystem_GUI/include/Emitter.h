#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"
#include <vector>
#include <ngl/AbstractVAO.h>
#include <memory>

class Emitter
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our Emitter class
    /// @param [in] _numParticles the number of particles in the scene
    /// @param [in] _emitterPos the emitter's position, defaulted to 15
    /// @param [in] _spread the spread of the particles, defaulted to 1.5
    /// @param [in] _emitDir the emission direction of the particle
    //----------------------------------------------------------------------------------------------------------------------
    Emitter(size_t _numParticles, ngl::Vec3 _emitterPos = 15, int _spread = 2, ngl::Vec3 _emitDir = ngl::Vec3 (5.0f,5.0f,0.0f));
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for our Emitter class when it falls out of scope
    //----------------------------------------------------------------------------------------------------------------------
    ~Emitter() = default;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will update the scene based on the particles' positions
    /// @param _deltaT our time step
    /// @param _gravity the gravity applied to the selected emitter
    /// @param _numParticles the number of particles emitted form the selected emitter
    /// @param _spread the spread of the particles for the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void update(float _deltaT, int _gravityY, int _numParticles, int _spread);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will draw the particles
    //----------------------------------------------------------------------------------------------------------------------
    void draw() const;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter up in our scene
    /// @param _dy move along y axis
    //----------------------------------------------------------------------------------------------------------------------
    void up(float _dy);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter down in our scene
    /// @param _dy move along y axis
    //----------------------------------------------------------------------------------------------------------------------
    void down(float _dy);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter left in our scene
    /// @param _dx move along x axis
    //----------------------------------------------------------------------------------------------------------------------
    void left(float _dx);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter right in our scene
    /// @param _dx move along x axis
    //----------------------------------------------------------------------------------------------------------------------
    void right(float _dx);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter inwards in our scene
    /// @param _dz move along z axis
    //----------------------------------------------------------------------------------------------------------------------
    void in(float _dz);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will move the emitter downwards in our scene
    /// @param _dz move along z axis
    //----------------------------------------------------------------------------------------------------------------------
    void out(float _dz);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will add particles to the selected emitter
    /// @param _spread the spread of the particles fo rthe selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void addParticles(int _spread);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will remove particles from the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void removeParticles();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will clear all the particles for the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void clearParticles();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will reset the emitter to the default
    /// @param _numParticles the number of particles emitted by selected emitter
    /// @param _spread the spread of the particles for the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void resetEmitter(size_t _numParticles, int _spread);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will toggle on and off a single shot of particles for the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void toggleSingleShot();

private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will reset the particle to its original position
    /// @param io_p particle reference. This value will be both input and output for this function
    /// @param _spread the spread of the particles for the selected emitter
    //----------------------------------------------------------------------------------------------------------------------
    void resetParticle(Particle &io_p, int _spread);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will generate a random vector on a sphere
    /// @param _radius the radius of the sphere we are generating, defaulted to 1.0f
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 randomVectorOnSphere(float _radius = 1.0f);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method that will detect whether the particles collide with the edge of the designated boundary
    /// @param io_p particle reference
    /// @param _deltaT our time step
    /// @param _gravityY the gravity applied to the particle
    //----------------------------------------------------------------------------------------------------------------------
    void collisionDet(Particle &io_p, float _deltaT, int _gravityY);
    //creates a std::vector for our particles within our class
    //automatic object so no dynamic memory allocation
    std::vector<Particle> m_particles;
    //unique pointer of Abstract VAO
    //allocate vao once and every frame we call draw the data for the vao is going to be reset to be the current particle data
    std::unique_ptr<ngl::AbstractVAO> m_vao;
    //postion of the emitter
    ngl::Vec3 m_emitterPos;
    //overall emission direction of the particles
    ngl::Vec3 m_emitDir = ngl::Vec3 (5.0f,5.0f,0.0f);
    //triggering a single shot of particles, default set to false
    bool m_singleShot = false;


};

#endif
