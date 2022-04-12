#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
	void SnakeGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

        int argc = 0;
        char** argv = nullptr;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE);
        glutInitWindowSize(200, 200);
        glutInitWindowPosition(200, 200);
        glutCreateWindow("Window");
        glClearColor(1, 1, 1, 0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10, 10, -10, 10, 0, 0);
        glutDisplayFunc(Display);
        glutMainLoop();

		/*auto controllerLocator = std::make_shared<ControllerLocator>();
		auto game = std::make_shared<Game>(controllerLocator);

		game->Start();*/
	}
    void SnakeGame::Display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 0.0f, 0.0f);
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2d(-1, 0);
        glVertex2d(1, 0);
        glEnd();
        glutSwapBuffers();
    }
}
