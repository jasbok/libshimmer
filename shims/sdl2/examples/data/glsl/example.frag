#version 330 core

in vec3 f_colour;
in vec2 f_texcoord;

out vec4 FragColor;

uniform sampler2D tex_a;
uniform sampler2D tex_b;
uniform float factor;

void main()
{
    FragColor = mix(texture(tex_a, f_texcoord),
                    texture(tex_b, f_texcoord),
                    factor)
                + vec4(f_colour, 1.0f);
}
