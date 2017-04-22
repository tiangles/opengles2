attribute vec3 a_position;
attribute vec3 a_normal;
attribute vec2 a_texCoord0;

uniform mat4 u_projMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;
uniform mat4 u_modelViewMatrix;
uniform mat4 u_modelViewProjMatrix;

varying vec3 v_normal;
varying vec4 v_fragPos;

void main() {
    gl_Position = u_modelViewProjMatrix*vec4(a_position, 1.0);
    gl_TexCoord[0]  = vec4(a_texCoord0, 1.0, 1.0);
}
