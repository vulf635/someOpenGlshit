#ifndef SPRITE_H
#define SPRITE_H

#include "Texture2d.h"
#include "glm/glm.hpp"
#include "Shader.h"
#include "glad/glad.h"


class Sprite {
public:
    Texture2d Texture;
    glm::vec2 Position;
    glm::vec2 Size;
    glm::vec3 Color;
    float Rotation;

    Sprite(Shader shader);
    ~Sprite();
    


    void Draw(Texture2d &texture, float x, float y, float width, float height);
private:
    Shader shader;
    GLuint quadVAO;

    void initRenderData();
};



#endif //SPRITE_H
