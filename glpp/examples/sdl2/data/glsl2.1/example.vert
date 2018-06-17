#version 120

attribute vec3 position;
attribute vec3 colour;
attribute vec2 texcoord;

varying vec3 f_colour;
varying vec2 f_texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    f_colour = colour;
    f_texcoord = texcoord;
}
