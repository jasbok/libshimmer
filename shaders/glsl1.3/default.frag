#version 120

varying vec3 f_colour;
varying vec2 f_texcoord;

uniform sampler2D application;

void main()
{
    gl_FragColor = texture2D( application, f_texcoord ) * vec4( f_colour, 1.0 );
}
