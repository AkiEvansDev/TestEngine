#include "core/Window.h"

#include <iostream>

//cmake --build .

void onSizeChange(GLFWwindow* pWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}

void onKey(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{

}

int main(void)
{
    try
    {
        Window root("Test", 800, 600);

        root.setSizeCallback(onSizeChange);
        root.setKeyCallback(onKey);

        std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

        root.loop();
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    return 0;
}