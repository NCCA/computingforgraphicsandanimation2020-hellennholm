# CFGAA Assignment Helena Lennholm

Project Proposal - Version 1
Fluid Dynamics
A fluid solver where multiple fluids with varying properties can interact with each other. The user would define the number of interacting fluids (1-4) (more than 2 might be too much). They would also define their individual density, viscosity and colour as well as the gravity applied to the scene. They then run the program and it calculates how these fluids would interact with one another.

Based off of the physics used for the python project from first year.

Project Proposal - Final Version
Fluid Dynamics
A fluid solver where multiple fluids with varying properties can interact with each other. The user can define the number of fluids (1-4), the gravity applied to each, the number of particles emitted from each emitter, the size of the particles for each fluid, the spread of the particles and their colour. The user can also add, remove and clear particles from the scene as well as being able to toggle on and off a single shot off particles as well as reset the emitter. Each of these options would be visible in the UI and can be edited for individual emitters or for several emitters at the same time. The fluids also interact with a pre-defined volume, giving a necessity to implement collision detection for the particles.

Research:

I started by using the tutorials provided in class to build the initial particle system. I wanted to implement the same physics that I implemented in a previous project based off of Antonia Strantzi's thesis on 'Fluid Simulation Using Smoothed Particle Hydrodynamics (SPH)' however this ended up being too complex, so I used it as a basis for my research instead. I also looked at William T. Reeves' paper on 'Particle Systems - A Technique for Modelling a Class of Fuzzy Objects'. Although both of these papers calculate the number of particles to be used, Strantzi by using the equation [1]:  

𝑛 = 𝑉/4𝜋𝑝𝑎𝑟𝑡𝑖𝑐𝑙𝑒_𝑠𝑖𝑧𝑒3

And Reeves by using the equations [3]:

NPartsf = MeanPartsr + Rand( ) x VarPartsr
NPartsf = (MeanParts, a r + Rand( ) x VarParts,ar) x ScreenArea

I decided to keep the number of particles as an input from the user. The initial code assigns each emitter 1000 particles after which this number can be changed by the user through the use of a slider.

I also looked at the "two fundamental equations that describe a fluid's motion" (Strantzi 2016) which are known as the Navier-Stokes equations, named after Claude-Louis Navier and George Gabriel Stokes. They " are used to describe a fluid's velocity field over time." (Strantzi 2016). These equations are[1]:

∇∙𝐮=0
𝜕𝐮/𝜕𝑥 = - 𝐮∙∇𝐮 - (1/ρ)∇𝑝+v∇𝐮+𝐅

with:

−𝐮 ∙ ∇𝐮 : the "self-advection term" (Strantzi 2016)
-1/ρ∇𝑝 : the "pressure term" (Strantzi 2016)
v∇2𝐮 : the "viscosity term" (Strantzi 2016)
𝐅 : all the external forces applied to the fluid (Strantzi 2016)

I did not create a fluid system which was physically accurate enough to make full use of these equations however they did feed into how I calculated and updated the position of the particles within my code. I did so by having my variable for the direction vector be the equivalent of the velocity vector of the particles and as such used these equations:

For F = ma with a=g (g is the gravity vector)
I did the derivative of acceleration to find the velocity:
v = at + v0 (a is acceleration, t is time and v0 is the initial velocity)
I used the second derivative of acceleration to then find the position of the particle at t:
pos = (1/2)at*t = v0t

These equations gave this code:
p.dir += gravity * _deltaT * 0.5f;
p.pos += 0.5f * gravity * (_deltaT * _deltaT) + p.dir * _deltaT;

p.dir having initially been defined as:
io_p.dir = m_emitDir + randomVectorOnSphere() * _spread;
io_p.dir.m_y = std::abs(io_p.dir.m_y);

Implementation:
Spheres:

Once the updated position worked and I had particles, in the form of points, that were moving in a physically accurate way I started looking at making those particles spheres so that they could interact with each other as well as with the lighting applied to the scene. I started by using a piece of pseudo code provided by the Jon Macey:

Transformation tx
for eachParticle :
tx.setPosition(ParticlePosition)
MVP = m_project * m_view * tx.getPosition
setUniform(“MVP”,MVP)
prim->draw(“sphere”)

The first question was where to place this code. I moved it about quite a bit trying to get the 'prim->draw("sphere")' to pick up the updated position. I placed parts of it in my 'Emitter::draw()' method, parts of it in my 'Emitter::resetParticle()' method and parts of it in my 'Emitter::update()' method. Trying to implement spheres as particles ended up being the most time-consuming element that I wanted to add to the code. To try and debug my code and see where the correct place to put the code necessary to draw the spheres was, I replaced the sphere with different shapes from 'VAOPrimitives.h', so as to see what parts of the code were drawing what and how.
I created a 'loadMatrixToShader' method, based off code provided in class, which set my MVP, to minimize repetition of code. I then, in 'resetParticle', used this code:

    void Emitter::resetParticle(Particle& io_p)
    {
        auto shader = ngl::ShaderLib::instance();
        shader->setUniform("ParticleColour", 1.0f, 0.0f, 0.0f');
        ngl::Transformation tx;
        auto rng = ngl::Random::instance();
        io_p.pos = rng->getRandomVec3();
        tx.setPosition(io_p.pos);
        io_p.dir = rng->getRandomVec3();
        io_p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
        io_p.life = 0;
        loadMatrixToShader(tx);
        ngl::VAOPrimitives::instance()->draw("bunny");    
    }
This gave me a bunny which flashed continuously whenever resetParticle was called, meaning that it was being reset the origin as it was meant to. 

In 'update()', for every particle I also did:

    p.pos += p.dir;
    loadMatrixToShader(tx);
    shader->setUniform("particleColour", 1.0f, 0.0f,1.0f);
    tx.setPostion(p.pos);
    ngl::VAOPrimitives::instance()->draw("teapot");

And I called 'update()' in my 'draw()' method. This gave me a teapot which was stationary at the origin and a bunny that was stationary at the origin but that flashed. After getting back and forth feedback about what the issue could be and how to potentially fix it, I tried using the piece of code seen below:

    void Emitter::loadMatrixToShader(ngl::Transformation &_tx)
    {

        ngl::Transformation tx;
        auto shader = ngl::ShaderLib::instance();
        shader->use("ParticleShader");
        auto MVP = m_project * m_view * tx.getPosition();
        std::cout << MVP << " MVP" << '\n';
        shader->setUniform("MVP", MVP);
        
    }

    void Emitter::resetParticle(Particle& io_p)
    {

        ngl::Transformation tx;
        auto rng = ngl::Random::instance();
        io_p.pos = rng->getRandomVec3();
        io_p.dir = rng->getRandomVec3();
        io_p.maxLife = static_cast<int>(rng->randomPositiveNumber(100));
        io_p.life = 0;
        tx.setPosition(io_p.pos);
        std::cout << io_p.pos << " test2" << '\n';
        //loadMatrixToShader(tx);
        // ngl::VAOPrimitives::instance()->draw("sphere");

    }

    ngl::Vec3 Emitter::update()
    {

        ngl::Transformation tx;
        for (auto &p : m_particles)
        {
            p.pos += p.dir;
            tx.setPosition(p.pos);
            std::cout << p.pos << " test4" << '\n';
            if (++p.life >= p.maxLife)
            {
                resetParticle(p);
            }
            return p.pos;
        }
        
    }

    void Emitter::draw()
    {

        //auto rng = ngl::Random::instance();
        auto shader = ngl::ShaderLib::instance();    
        shader->use("ParticleShader");    
        ngl::Transformation tx;    
        for (auto &p : m_particles)
        {
            p.pos = update();
            tx.reset();
            tx.setPosition(p.pos);
            tx.setScale(1.0,1.0,0.9);
            loadMatrixToShader(tx);
            std::cout << tx.getPosition() << " tx" << '\n';
            ngl::VAOPrimitives::instance()->draw("sphere");
        }

    }

Again, to try and figure out why this code was not displaying moving spheres but only a static one at the origin I tried debugging it by printing the positions of the spheres as they got update. Through this I could see that the position was being reset to 0 in 'resetParticle' (std::cout << io_p.pos << " test2" << '\n';) and the position being printed by: 'std::cout << p.pos << " test4" << '\n';' and 'std::cout << tx.getPosition() << " tx" << '\n';' were the same however these updated positions were not being passed on to the 'draw->("sphere")' function and I simply could not figure out why. As the deadline drew closer, I had to make a decision to leave this specific aspect of my code out as I could not get it to work properly. I moved onto other elements I wanted to implement and decided to come back to this specific issue is I had the time. I came back to it briefly towards the end of the project, when I had a program, I was happy with but got no further in figuring out what was going wrong. All I know is that the data form 'tx.setPositon(p.pos)' was not being passed through to the sphere, however I do not know why.

Collisions:

My next step was implementing collisions which was not too complex. I used Strantzi's equation as a basis for the code used:

𝐮𝑖 = −𝑠𝐮𝑖, 𝑠 ≥ 0 "an energy loss parameter" (Strantzi 2016)

I simply reversed the particle's direction and added this loss parameter, which acts in the same way as friction would. Getting the value of ‘s’ correct was crucial in alleviating the bounce of the particles when they collided with the ground. If the value was too small the particles stuck to the ground and, due to the piece of code which reset the particles if their height was 0, they would instantly be reset. If this value was too high, then the particles bounced back without losing enough energy and as such no longer acted like fluid particles. I ended up settling on a value of 0.6 which meant that the particles would lose 40% of their energy every time they collided with the ground.  I did not implement this extra parameter when the particles collided with the walls of my pre-defined volume as it mean that in that case the particles would lose too much energy and be reset too quickly. I also placed the ground plane that the particles collided with at 0.1 rather than 0 so that they would not be reset as soon as they hit the ground.

Multiple Emitters:

Once I had one emitter that had particles that collided with the ground, I moved onto creating multiple emitters. This was a simple step, the additional code for this was the following for each individual emitter:
    
    m_emitter_number = std::make_unique<Emitter> (m_numParticles, emitter position, m_spread, emission angle);
    
I created four emitters whose visibility was toggled on and off with the keyboard keys 1-4. The key press would call a method which toggled the visibility of the emitter from true to false and vice-versa. If the visibility was true the emitter would be assigned a particle size and colour, and drawn in 'paintGL()'.  I now had four working emitters, the next step was to let the user edit them freely and for this I needed a user interface.

UI:

The UI I wanted to created had a few layers of complexity to it as I want the user to be able to select the emitter they wanted to edit, without the changes affecting the rest of the emitters. The changes I wanted the user to be able to implement were the following:

For each emitter - drop down menu:
    Gravity - slider
    Number of Particles - slider
    Particle Size - slider
    Particle Spread - slider
    Single Shot (on/off) - check box
    Add Particles - button
    Remove Particles - button
    Clear Particles - button
    Reset Emitter - button
    Colour - colour wheel
    
I started by implementing each individual element for the first emitter. Based off the code provided in class I added the 'Add Particles', 'Remove Particles', 'Clear Particles' and 'Reset Emitter' button. The next step was to add the sliders. When adding the sliders for gravity, the number of particles, their size and their spread I had to change these variables from variables defined in the Emitter class to variables defined in the NGLScene class, meaning that they had to be passed through correctly into the emitter. My main issue came when I wanted to add colour to the list of options. I quickly realised that I would not be able to implement a colour wheel as I could not find any good sources pertaining to its creation online so instead, so as to not waste time, I implemented a slider for each rgb value. I then had to translate those values, which were 0 - 255 , due to the fact that the slider in Qt Designer only takes integers. Whereas the colours passed through to 'shader->setUniform()' have values between 0 and 1. This meant that I had to firstly convert the integer to a float and then divide it by 255 to get a rgb value between 0 and 1. I could then pass this through to my setUniform method. Finally, I implemented my single shot option which was a check box. This called the single shot method from the Emitter class. In my MainWindow class the signal I had to pass through was to detect when the check box was clicked. This called method which toggled single shot to true if it was clicked and to false if it wasn't.
After having all these options set out, I went about setting them up for each emitter as such I created a check box for each emitter which worked in the same way as the single shot check box. Initially I wanted all the options to be in a drop-down menu for each emitter however I could not find a way to do this in Qt Designer and so decided to use check boxes for each emitter. If the check box was toggled on the emitter would become editable. I then proceeded to have an 'if' statement for each method in NGLScene that was linked to a slot in my MainWindow class, which looped through, checking first if the emitter's editability was true, and hence toggled on, and then performed the action the button or slider was designated to perform. This allows the user to select the emitter they want to edit without the changes affecting the other emitters. It also allows the user to edit 1-4 emitters at the same time and assign the new values to all the selected emitters. The implementation for the UI works well however there is a lot of repetition of code which could be improved to be more streamlined and clearer. 
A final issue I had with my UI was that after following the tutorials provided in class I found that my window was no longer picking up key presses, however I still needed these to toggle on and off the visibility of the emitters as I wanted the user to still be able to view one emitter at a time in a quick and efficient manner. The way I fixed this, after getting feedback, was by making my 'keyPressEvent' method in my NGLScene class public as well as adding this method to my MainWindow class so that key presses could be used again. This way I could allow the user to move the emitters, again individually or together depending on which ones' editability was toggled on as well as have the user choose which emitters, they wanted visible.

Ongoing Issues and Further Additions to the Code:

There are still several issues with my code which I have been unable to fix as well as several more elements I would have liked to add had I had more time. The first is the lack of spheres which I covered earlier and which I still do not know how to fix but which, had I had more time, I would have kept working on as I believe it would have added a lot to code specifically its visual impact. The next issue, which again affects the visual impact of the program is that the emitter does not create a constant stream of particles, it creates particles in bursts as it resets particles which, either reach the end of their life or go below 0 along y. This is due to an if statement in the Emitter class update function which I tried to change so that the particles were being reset under different circumstances however this did not work. The original fix I had for this was to add a few particles for each particle every time update was called and then resize the m_particles vector to the new amount of particles, however when I added the UI I realised that this meant that my add, remove and clearParticles methods no longer worked as m_particles was being constantly resized. I still have not found a work around for this which is a shame, the only way to get a more constant stream of particles is to let the program run for a bit until the number of particles being reset at a time becomes more constant rather than in burst. Another issue that arose when I implemented the UI was that to update the number of particles emitted, the user had to call reset rather than this being done in real-time. This again had to do with the update of the number of particles in the Emitter class, when m_particles was resized at the top of the update method this worked however, again, it affected the add, remove and clear methods. So, to get around this, rather than the user calling reset, it is call automatically when the number of particles changes. I would have liked this to be done in real-time, and is something that, had I had more time, I would have done my best to fix. 
Again, due to time constraints, there are certain elements that I would have liked to add but were unable to as well as make the code more efficient and more maintainable through less repetition of code. I would have liked to have the particles act in a more physically accurate way, as is shown in Strantzi's paper. For this I would have implemented more real-world forces such as density, viscosity, mass and pressure among others. I would have also like to fix the collisions as currently the ground collisions work well but a lot of particles are lost when they go below 0. Some also get caught on the wrong side of the of the boundary to the volume due to the way I have implemented collision detection.
However overall, despite flaws, once I implemented the UI it all seemed to come together to form a project that I am relatively happy with as this program meets the basic criteria I set for myself however, as seen above, there are several elements which I was unable to Implement, despite wanting to.

References:

[1] Antonia Strantzi, 2016. Fluid Simulation Using Smoothed Particle Hydrodynamics (SPH). [online]. Bournemouth University. Available from: https://nccastaff.bournemouth.ac.uk/jmacey/MastersProjects/MSc16/15/thesis.pdf [Accessed 14 Jun 2020].

[2] dmckee---ex-moderator kitten., 2011. python - Sampling uniformly distributed random points inside a spherical volume [online]. Stack Overflow. Available from: https://stackoverflow.com/questions/5408276/sampling-uniformly-distributed-random-points-inside-a-spherical-volume [Accessed 15 Jun 2020].

[3] Reeves, W. T., 1983. Particle Systems - A Technique for Modeling a Class of Fuzzy Objects. ACM Transactions on Graphics, 2 (2), 18. Available from: https://brightspace.bournemouth.ac.uk/content/enforced/67461-TBC/Reeves-1983-PSA.pdf [Accessed 14 Jun 2020] 










