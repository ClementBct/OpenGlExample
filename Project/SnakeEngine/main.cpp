#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


void error_callback(int i_error, const char* i_description) {
	printf("Error code : %d - Error description : %s", i_error, i_description);
}

int main(int argc, char** argv) {
	if (!glfwInit())
	{
		printf("Error initialize GLFW\n");
	}
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Sa C ma WINDOWS FDP", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		printf("Impossible to create window\n");
		return -1;
	}
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		printf("Error initialize GLEW\n");
		return -1;
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, 0.5f * float(sqrt(3)) * 2, 0.0f,
	};

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}