#include "ResourceManager.h"
#include "stb_image.h"
#



Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, std::string name) {

}


Texture2d ResourceManager::LoadTexture(const std::string &file, const std::string &name) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);

    Texture2d texture;
    texture.Generate(width, height, data);
    stbi_image_free(data);

    Textures[name] = texture;
    return Textures[name];
}


