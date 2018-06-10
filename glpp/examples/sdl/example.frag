#version 120

varying vec3 f_colour;
varying vec2 f_texcoord;

void main()
{
    //gl_FragColor = texture2D(application, f_texcoord); // + vec4(1.0, 0.0, 0.0, 0.0);

    gl_FragColor = vec4(f_colour, 1.0);
}
