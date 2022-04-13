#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
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
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(_widthWindow, _heightWindow);
        glutCreateWindow("Snake");
        glClearColor(0, 0, 0, 0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, _widthWindow, 0.0, _heightWindow);

        glutDisplayFunc(Display);

        glutMainLoop();
	}   
    
    void SnakeGame::Display()
    {       
        
    }
}
