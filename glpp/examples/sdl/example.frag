#version 120

varying vec3 f_colour;
varying vec2 f_texcoord;

uniform sampler2D tex_2d;

void main()
{
    gl_FragColor = texture2D(tex_2d, f_texcoord) * vec4(f_colour, 1.0);
}
