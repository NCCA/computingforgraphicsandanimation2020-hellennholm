#version 410 core

layout (location = 0) out vec4 fragColour;

uniform vec3 particleColour;

void main()
{
    fragColour.rgb = particleColour;
}
