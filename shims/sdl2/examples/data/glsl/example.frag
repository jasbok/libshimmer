#version 330 core

in vec3 f_colour;
in vec2 f_texcoord;

out vec4 FragColor;

uniform sampler2D texture_a;
uniform sampler2D texture_b;
uniform float blend_factor;

void main()
{
    FragColor = mix(texture(texture_a, f_texcoord),
                    texture(texture_b, f_texcoord),
                    1.0f - blend_factor)
                + vec4(f_colour, 1.0f);
}
