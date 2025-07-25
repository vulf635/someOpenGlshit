﻿//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//
//
//using namespace std;
//
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//}
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\0";
//
//
//int main() {
//	if (!glfwInit()) {
//		std::cout << "glfw not initialized!";
//	}
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 800, "Test window", NULL, NULL);
//
//	if (window == NULL) {
//		std::cout << "window don't has been created";
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 800);
//
//	//triangle
//	float vertices[] = {
//		 0.0f,  0.5f, 0.0f,  
//		 0.5f, -0.5f, 0.0f,  
//		-0.5f, -0.5f, 0.0f,
//		0.0f,  0.5f, 0.0f,
//		 0.5f, -0.5f, 0.0f,
//		-0.5f, -0.6f, 0.0f,
//	};
//	unsigned int indices[] = {
//		0, 1, 3,
//		1, 2, 3
//	};
//	
//
//
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	int success; 
//	char infolog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
//	}
//
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infolog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	unsigned int VAO, VBO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//	
//	//general cycle
//	while (!glfwWindowShouldClose(window)) {
//
//		processInput(window);
//
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		/*glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);*/
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//	}
//
//	glfwTerminate();
//	return 0;
//}