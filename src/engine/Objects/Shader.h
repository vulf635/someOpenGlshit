#ifndef SHADER_H
#define SHADER_H
#include <string>


class Shader {
    public:
        unsigned int ID;

        Shader();
        Shader& Use();

        void Compile(const char* vertexSource, const char* fragmentSource);
        void SetFloat(const char* name, float value, bool useShader = false);
        void SetInteger(const char* name, int value, bool useShader);
    private:
        void checkCompileErrors(unsigned int object, std::string type);

};



#endif //SHADER_H
