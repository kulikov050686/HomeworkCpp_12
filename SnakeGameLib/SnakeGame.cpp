#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
    std::shared_ptr<IGame> SnakeGame::_game;

    SnakeGame::SnakeGame(std::shared_ptr<IGame> game)
    {
        if(game == nullptr) throw "Error!!!";
        _game = game;       
    }

    void SnakeGame::Run()
	{
        char** argv = nullptr;
        int argc = 1;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(_widthWindow, _heightWindow);
        glutCreateWindow("Snake");
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glViewport(0, 0, _widthWindow, _heightWindow);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, _widthWindow, 0.0, _heightWindow);

        glutReshapeFunc(Reshape);
        glutTimerFunc(300, Timer, 1);
        glutDisplayFunc(Display);
        glutKeyboardFunc(Keyboard);        

        glutMainLoop();        
	}

    void SnakeGame::Display()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        _game->Draw();

        glFlush();
    }

    void SnakeGame::Timer(int value)
    {
        _game->Timer(value);

        glutPostRedisplay();
        glutTimerFunc(300, Timer, 1);
    }

    void SnakeGame::Reshape(int width, int height)
    {
        _game->Reshape(width, height);
    }

    void SnakeGame::Keyboard(unsigned char key, int x, int y)
    {
        _game->Keyboard(key, x, y);
    }    
}
