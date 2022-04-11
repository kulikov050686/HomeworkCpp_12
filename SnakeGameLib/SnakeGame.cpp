#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
	void SnakeGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW!!!" << std::endl;
            return;
        }

        GLFWwindow* window = glfwCreateWindow(1200, 1200, "Snake", nullptr, nullptr);

        if (!window)
        {
            std::cout << "Window failed!!!" << std::endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);
        
        std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

        if (glewInit() != GLEW_OK)
        {
            std::cout << "Failed to initialize GLEW!!!" << std::endl;
            return;
        }

        while (!glfwWindowShouldClose(window))
        {

            glClear(GL_COLOR_BUFFER_BIT);


            glfwSwapBuffers(window);


            glfwPollEvents();
        }

        glfwTerminate();

		/*auto controllerLocator = std::make_shared<ControllerLocator>();
		auto game = std::make_shared<Game>(controllerLocator);

		game->Start();*/
	}
}
