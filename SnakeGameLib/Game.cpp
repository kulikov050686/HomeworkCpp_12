#include "pch.h"
#include "Game.h"

namespace SnakeGameLib
{
	Game::Game(std::shared_ptr<ControllerLocator> controllerLocator)
	{
		if (controllerLocator == nullptr) throw "Error!!!"; 

		_gameFieldController = controllerLocator->GetGameFieldController();
		if (_gameFieldController == nullptr) throw "Error!!!";

		_entityCreator = controllerLocator->GetEntityCreator();
		if (_entityCreator == nullptr) throw "Error!!!";

		Init();
	}

	void Game::Draw()
	{
		size_t size = _gameFieldController->GetSizeField();
		Point2D<uint16_t> point{ 0,0 };
		Point2D<GLint> rectangleCoordinates{ 0,0 };
		
		for (size_t y = 0; y < size; y++)
		{
			point.y = y;

			for (size_t x = 0; x < size; x++)
			{
				point.x = x;

				switch (_gameFieldController->GetFieldElement(point))
				{
					case 1:
					{
						ColorRGB<float> color{ 0.8f, 0.8f, 0.8f };
						Rectangle(rectangleCoordinates, color, _shift);
						break;
					}
					case 2:
					{
						ColorRGB<float> color{ 0.0f, 0.0f, 1.0f };
						Rectangle(rectangleCoordinates, color, _shift);
						break;
					}
					case 3:
					{
						ColorRGB<float> color{ 1.0f, 1.0f, 1.0f };
						Rectangle(rectangleCoordinates, color, _shift);
						break;
					}
					case 4:
					{
						ColorRGB<float> color{ 0.0f, 1.0f, 0.0f };
						Rectangle(rectangleCoordinates, color, _shift);
						break;
					}
					case 5:
					{
						ColorRGB<float> color{ 1.0f, 0.0f, 0.0f };
						Rectangle(rectangleCoordinates, color, _shift);
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
			_shift = width / _gameFieldController->GetSizeField();
		}
		else
		{
			_shift = height / _gameFieldController->GetSizeField();
		}

		if (_shift == 0) _shift = 10;
		
		_widthWindow = width;
		_heightWindow = height;				
	}

	void Game::Keyboard(unsigned char key, int x, int y)
	{
	}

	void Game::Init()
	{
		_numberOfPoints = 0;
		_gameOver = false;		
		Point2D<size_t> point{ _gameFieldController->GetSizeField() / 2, _gameFieldController->GetSizeField() / 2 };

		_snake = _entityCreator->CreateSnake(point, 2, 4);
		_gameFieldController->AddSnakeOnField(_snake);

		AddFruit();
	}

	void Game::AddFruit()
	{
		do
		{
			switch (Random::Next(0, 2))
			{
				case 0:
					_fruit = _entityCreator->CreateFruit(_gameFieldController->CreateRandomPoint(), TypeOfFruit::APPLE);
				break;
				case 1:					
					_fruit = _entityCreator->CreateFruit(_gameFieldController->CreateRandomPoint(), TypeOfFruit::PEAR);
				break;
				case 2:					
					_fruit = _entityCreator->CreateFruit(_gameFieldController->CreateRandomPoint(), TypeOfFruit::PEACH);
				break;
			}			
		} while (GetOnSnake(_fruit, _snake));

		_gameFieldController->AddFruitOnField(_fruit);
	}
	
	bool Game::GetOnSnake(std::shared_ptr<IFruit> fruit, std::shared_ptr<ISnake<uint16_t>> snake)
	{
		for (size_t i = 0; i < snake->GetNumberOfElements(); i++)
		{
			if (snake->GetElement(i).coordinates == fruit->GetCoordinates())
			{
				return true;
			}
		}

		return false;
	}

	void Game::Rectangle(Point2D<GLint> rectangleCoordinates, ColorRGB<GLfloat> color, GLint size)
	{
		glColor3f(color.r, color.g, color.b);
		glRecti(rectangleCoordinates.x, rectangleCoordinates.y, rectangleCoordinates.x + size, rectangleCoordinates.y + size);
	}
	
	void Game::SnakeMovement(Direction direction)
	{
		for (size_t i = _snake->GetNumberOfElements() - 1; i > 0; --i)
		{
			auto s = _snake->GetElement(i);
			auto p = _snake->GetElement(i - 1);

			s.coordinates = p.coordinates;

			_snake->UpdateElement(s);
		}

		auto s = _snake->GetElement(0);

		switch (direction)
		{
			case Direction::RIGHT: 
				s.coordinates.x += 1;				
				break;					
			case Direction::LEFT:
				s.coordinates.x -= 1;				
				break;					
			case Direction::UP:
				s.coordinates.y += 1;				
				break;					
			case Direction::DOWN:
				s.coordinates.y -= 1;				
				break;						
		}

		_snake->UpdateElement(s);
	}
}
