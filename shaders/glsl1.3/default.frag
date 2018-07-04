#version 120

varying vec2 f_texcoord;

uniform sampler2D application;

void main()
{
    gl_FragColor = texture2D( application, f_texcoord );
}
