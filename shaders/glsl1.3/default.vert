#version 120

attribute vec2 position;
attribute vec2 texcoord;

varying vec2 f_texcoord;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    f_texcoord = texcoord;
}
