#version 330 core

in vec3 position;
in vec3 colour;
in vec2 texcoord;

out vec3 f_colour;
out vec2 f_texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    f_colour = colour;
    f_texcoord = texcoord;
}
