#include "pch.h"
#include "TetrisGame.h"

namespace TetrisGameLib
{
	std::shared_ptr<IGame> TetrisGame::_game;

	TetrisGame::TetrisGame(std::shared_ptr<IGame> game)
	{
		if (game == nullptr) throw "Error!!!";
		_game = game;
	}

	void TetrisGame::Run()
	{
		char** argv = nullptr;
		int argc = 1;

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(_widthWindow, _heightWindow);
		glutCreateWindow("Tetris");
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glViewport(0, 0, _widthWindow, _heightWindow);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, _widthWindow, 0.0, _heightWindow);

		//glutReshapeFunc(Reshape);
		//glutTimerFunc(300, Timer, 1);
		glutDisplayFunc(Display);
		//glutKeyboardFunc(Keyboard);

		glutMainLoop();
	}

	void TetrisGame::Display()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		_game->Draw();

		glFlush();
	}

	void TetrisGame::Timer(int value)
	{
		_game->Timer(value);

		//glutPostRedisplay();
		//glutTimerFunc(300, Timer, 1);
	}

	void TetrisGame::Reshape(int width, int height)
	{
		_game->Reshape(width, height);
	}

	void TetrisGame::Keyboard(unsigned char key, int x, int y)
	{
		_game->Keyboard(key, x, y);
	}
}
