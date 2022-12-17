#include "pch.h"
#include "Game.h"

namespace TetrisGameLib
{
	Game::Game(std::shared_ptr<ControllerLocator> controllerLocator)
	{
		if (controllerLocator == nullptr) throw "Error!!!";

		_gameMapController = controllerLocator->GetGameMapController();
		if(_gameMapController == nullptr) throw "Error!!!";

		_entityCreator = controllerLocator->GetEntityCreator();
		if(_entityCreator == nullptr) throw "Error!!!";
	}

	void Game::Draw()
	{
		size_t rows = _gameMapController->GetNumberOfRows();
		size_t columns = _gameMapController->GetNumberOfColumns();
		Point2D<uint16_t> point{ 0,0 };
		Point2D<GLint> rectangleCoordinates{ 0,0 };

		for (size_t y = 0; y < rows; y++)
		{
			point.y = y;

			for (size_t x = 0; x < columns; x++)
			{
				point.x = x;

				switch (_gameMapController->GetFieldElement(point))
				{
					case 1:
					{
						ColorRGB<float> color{ 0.8f, 0.8f, 0.8f };
						Rectangle(rectangleCoordinates, color, _shift);
						break;
					}
					case 2:
					{
						break;
					}
					case 3:
					{
						break;
					}
					case 4:
					{
						break;
					}
					case 5:
					{
						break;
					}
				}

				rectangleCoordinates.x += _shift;
			}

			rectangleCoordinates.y += _shift;
			rectangleCoordinates.x = 0;
		}
	}

	void Game::Timer(int value)
	{
	}

	void Game::Reshape(int width, int height)
	{
		if (height == 0) height = 1;
		glViewport(0, 0, width, height);

		if (width > height)
		{
			_shift = width / _gameMapController->GetNumberOfColumns();
		}
		else
		{
			_shift = height / _gameMapController->GetNumberOfRows();
		}

		if (_shift == 0) _shift = 10;

		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();

		_widthWindow = width;
		_heightWindow = height;
	}

	void Game::Keyboard(unsigned char key, int x, int y)
	{
	}

	void Game::Idel()
	{
	}

	void Game::Rectangle(Point2D<GLint> rectangleCoordinates, ColorRGB<GLfloat> color, GLint size)
	{
		glColor3f(color.r, color.g, color.b);
		glRecti(rectangleCoordinates.x, rectangleCoordinates.y, rectangleCoordinates.x + size, rectangleCoordinates.y + size);
	}
}