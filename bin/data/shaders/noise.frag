// fragment shader

#version 150

uniform float shaderColor1;
uniform float shaderColor2;
uniform float shaderColor3;
out vec4 outputColor;

void main() {
    

    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.

    float windowWidth = 1024.0;
    float windowHeight = 768.0;

    float r = gl_FragCoord.x / windowWidth / shaderColor1;
    float g = gl_FragCoord.y / windowHeight / shaderColor2;
    float b = ((0.5 * gl_FragCoord.x) + (0.5 * gl_FragCoord.y)) / windowHeight / shaderColor3;
    float a = 1.0;
    outputColor = vec4(r, g, b, a);
//    outputColor = globalColor;
}