//
// Created by Олег Черепанов on 18.07.2025.
//

#include "Texture2d.h"
#include "glad/glad.h"

Texture2d::Texture2d() :
    width(0), height(0),
    internalFormat(GL_RGBA), imageFormat(GL_RGBA),
    Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT),
    Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
    glGenTextures(1, &this->ID);
}


void Texture2d::Generate(int width, int height, unsigned char* data)
{
    this->width = width;
    this->height = height;

    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internalFormat,
        width, height, 0, this->imageFormat, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2d::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
