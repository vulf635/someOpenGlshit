#include "Shader.h"
#include "glad/glad.h"


Shader::Shader() : ID(0) {}

Shader& Shader::Use() {
    glUseProgram(ID);
    return *this;
}



void Shader::Compile(const char *vertexSource, const char *fragmentSource) {
    unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vertexSource, nullptr);
    glCompileShader(vShader);

    unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fragmentSource, nullptr);
    glCompileShader(fShader);

    ID = glCreateProgram();
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::checkCompileErrors(unsigned int object, std::string type) {
    //TODO
}


