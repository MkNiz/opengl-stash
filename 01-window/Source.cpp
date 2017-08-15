#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	// Initialize glfw with window hints
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window and its pointer
	GLFWwindow* window = glfwCreateWindow(640, 480, "MyOpenGLWindow", NULL, NULL);
	if (window == NULL) {
		cout << "Window creation failed" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Load the appropriate function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GLAD could not initialize" << endl;
		return -1;
	}

	// Set viewport
	glViewport(0, 0, 640, 480);

	// Set callback for framebuffer size changes
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Basic render loop
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Terminate
	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}