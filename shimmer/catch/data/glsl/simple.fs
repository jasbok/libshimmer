#version 130

varying vec2 fs_texcoord;
uniform sampler2D sampler;
uniform float[15] floats;

void main()
{
    gl_FragColor = texture2D(sampler, fs_texcoord);
}
