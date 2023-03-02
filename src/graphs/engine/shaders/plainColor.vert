uniform highp mat4 MVP;

attribute highp vec3 vertexPosition_mdl;

void main() {
    gl_Position = MVP * vec4(vertexPosition_mdl, 1.0);
}
