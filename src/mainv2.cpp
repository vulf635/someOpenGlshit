#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "engine/Objects/ResourceManager.h"
#include "engine/Objects/Sprite.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



int main() {
	if (!glfwInit()) {
		std::cout << "glfw not initialized!";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Test window", NULL, NULL);

	if (window == NULL) {
		std::cout << "window don't has been created";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 800);


	/*ResourceManager::LoadShader(
		"src/Shaders/test/vertex.glsl",
		"src/Shaders/test/fragment.glsl",
		"sprite"
	);

	ResourceManager::LoadTexture("src/Textures/planet.png", "planet", true);

	Shader& shader = ResourceManager::GetShader("sprite");
	shader.Use();
	shader.SetInteger("image", 0, true);



	Sprite sprite(shader);*/





	while (!glfwWindowShouldClose(window)) {

		//processInput(window);


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		

		//sprite.Draw(ResourceManager::GetTexture("planet"), 0.5f, 0.5f, 0.5f, 0.5f);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();
	return 0;




}