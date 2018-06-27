#version 120

attribute vec2 position;
attribute vec3 colour;
attribute vec2 texcoord;

varying vec3 f_colour;
varying vec2 f_texcoord;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    f_colour = colour;
    f_texcoord = texcoord;
}
