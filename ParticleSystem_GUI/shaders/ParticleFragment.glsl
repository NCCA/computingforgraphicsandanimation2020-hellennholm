#version 410 core

layout (location = 0) out vec4 fragColour;

uniform vec3 particleColour;

void main()
{
    //fragColour is a vec4 so we use just its rgb values passed on from particleColour
    fragColour.rgb = particleColour;
}
