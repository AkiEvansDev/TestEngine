#include "Window.h"

Window::Window(const std::string& title, int width, int height)
{
	if (!glfwInit())
		throw std::runtime_error("Failed to GLFW init!");

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	pWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	if (!pWindow)
		throw std::runtime_error("Failed to load window!");

	glfwMakeContextCurrent(pWindow);

	if (!gladLoadGL())
		throw std::runtime_error("Failed to load GLAD!");
}

void Window::setSizeCallback(GLFWwindowsizefun callback)
{
	glfwSetWindowSizeCallback(pWindow, callback);
}

void Window::setKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(pWindow, callback);
}

void Window::loop()
{
	while (!glfwWindowShouldClose(pWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
}

Window::~Window()
{
	glfwTerminate();
}