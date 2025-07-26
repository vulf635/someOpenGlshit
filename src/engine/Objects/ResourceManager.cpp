#include "ResourceManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <fstream>
#include <sstream>
#include <iostream>
std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture2d> ResourceManager::Textures;



Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, std::string name) {
    Shaders[name] = LoadShaderFromFile(vShaderFile, fShaderFile);
    return Shaders[name];
}

Texture2d ResourceManager::LoadTexture(const char* file, std::string name, bool alpha) {
    Textures[name] = LoadTextureFromFile(file, alpha);
    return Textures[name];
}


//Texture2d ResourceManager::LoadTexture(const std::string &file, const std::string &name) {
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
//
//    Texture2d texture;
//    texture.Generate(width, height, data);
//    stbi_image_free(data);
//
//    Textures[name] = texture;
//    return Textures[name];
//}

Shader ResourceManager::LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile) {
    std::string vertexCode;
    std::string fragmentCode;

    try {
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::exception& e) {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n";
    }

    Shader shader;

    shader.Compile(vertexCode.c_str(), fragmentCode.c_str());

    return shader;
}

Texture2d ResourceManager::LoadTextureFromFile(const char* file, bool alpha) {
    Texture2d texture;

    if (alpha) {
        texture.internalFormat = GL_RGBA;
        texture.internalFormat = GL_RGBA;
    }

    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);

    if (data) {
        texture.Generate(width, height, data);
        stbi_image_free(data);
	} else {
		std::cerr << "Failed to load texture: " << file << std::endl;
	}
}


