#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <ngl/Vec3.h>

//making this a struct means that everything is public
struct Particle
{
    //particle position
    ngl::Vec3 pos;
    //particle direction
    ngl::Vec3 dir;
    //these two are never going to be negative so we make them unsigned ints
    //life of the particle
    unsigned int life = 0;
    //maximum life of the particle
    unsigned int maxLife = 0;
};

#endif
