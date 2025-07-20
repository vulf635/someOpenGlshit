#ifndef SPRITE_H
#define SPRITE_H

#include "Texture2d.h"
#include "glm/glm.hpp"
class Sprite {
public:
    Texture2d Texture;
    glm::vec2 Position;
    glm::vec2 Size;
    glm::vec3 Color;
    float Rotation;

    Sprite();
    void Draw(Shader &shader);
};



#endif //SPRITE_H
