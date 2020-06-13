#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <ngl/Vec3.h>

//making this a struct means that everything is public
struct Particle
{
    ngl::Vec3 pos;
    ngl::Vec3 dir;
    ngl::Vec3 colour;
    //these two are never going to be negative so we make them unsigned ints
    unsigned int life = 0;
    unsigned int maxLife = 0;
};

#endif
