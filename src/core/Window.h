#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>

class Window
{
public:
	Window(const std::string& title, int width, int height);
	void setSizeCallback(GLFWwindowsizefun callback);
	void setKeyCallback(GLFWkeyfun callback);
	void loop();
	~Window();
private:
	GLFWwindow* pWindow;
};