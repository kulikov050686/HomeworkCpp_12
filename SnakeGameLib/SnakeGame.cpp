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
        
        static IGame* g = _game->GetPointer();
        
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(_widthWindow, _heightWindow);
        glutCreateWindow("Snake");
        glClearColor(0, 0, 0, 0);
        //glViewport(0, 0, _widthWindow, _heightWindow);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //gluOrtho2D(0.0, _widthWindow, 0.0, _heightWindow);

        glutReshapeFunc([](int w, int h)
            {
                g->Reshape(w, h);
            });

        glutTimerFunc(50, [](int value)
            {
                g->Timer(value);
            }, 1);

        glutKeyboardFunc([](unsigned char k, int x, int y) 
            { 
                g->Keyboard(k, x, y); 
            });

        glutDisplayFunc([]()
            { 
                glClear(GL_COLOR_BUFFER_BIT);
                g->Draw(); 
                glFlush();
            });

        glutMainLoop();        
	}   
}
