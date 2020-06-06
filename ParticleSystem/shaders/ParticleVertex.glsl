#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colour;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(pos,1);
}
