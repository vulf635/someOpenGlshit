#ifndef RESOURSEMANAGER_H
#define RESOURSEMANAGER_H
#include "Texture2d.h"
#include <String>
#include <map>
#include "Shader.h"

class ResourceManager {
public:
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2d> Textures;


    static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, std::string name);
    static Texture2d LoadTexture(const std::string& file, const std::string& name);

    static Shader& GetShader(const std::string& name);
    static Texture2d& GetTexture(const std::string& name);
    static void Clear();

};



#endif //RESOURSEMANAGER_H
