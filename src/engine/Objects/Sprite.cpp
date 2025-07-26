#include "Sprite.h"
#include "Texture2d.h"

Sprite::Sprite(Shader shader) {
	this->shader = shader;
	initRenderData();
}

Sprite::~Sprite() {
	glDeleteVertexArrays(1, &quadVAO);
}

void Sprite::Draw(Texture2d& texture, float x, float y, float width, float height) {
	this->shader.Use();
	float vertices[] = {
		x,         y + height, 0.0f, 1.0f,
		x,         y,          0.0f, 0.0f,
		x + width, y,          1.0f, 0.0f,

		x,         y + height, 0.0f, 1.0f,
		x + width, y,          1.0f, 0.0f,
		x + width, y + height, 1.0f, 1.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, quadVAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	texture.Bind();

	glDrawArrays(GL_TRIANGLES, 0, 6);

}

void Sprite::initRenderData() {
	GLuint VBO;
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

