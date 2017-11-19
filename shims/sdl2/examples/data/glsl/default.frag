#version 330 core

in vec3 f_colour;
in vec2 f_texcoord;

out vec4 FragColor;

uniform sampler2D tex;

void main()
{
    FragColor = texture(tex, f_texcoord);
}
