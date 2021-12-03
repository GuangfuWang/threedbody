#version 430 core

uniform ModelMatrix;
uniform ViewMatrix;
uniform ProjectionMatrix;

in vec3 vertex_position;
in vec3 vertex_color;

out vec3 naive_color;

void main(){
    gl_Position = vec4(vertex_position, 1.0);
    naive_color = vertex_color;
}