#version 330 core

in vec3 f_colour;
in vec2 f_texcoord;

out vec4 FragColor;

uniform sampler2D application;

void main()
{
    FragColor = texture(application, f_texcoord) + vec4(1.0, 0.0, 0.0, 0.0);
}
