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
	}

	void Game::Draw()
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2d(-1, 0);
		glVertex2d(1, 0);
		glEnd();	
	}

	void Game::Timer(int value)
	{

	}

	void Game::Reshape(int width, int height)
	{

	}

	void Game::Keyboard(unsigned char key, int x, int y)
	{

	}

	void Game::Print()
	{
		setlocale(LC_ALL, "Russian.utf8");
		system("cls");

		Point2D<uint16_t> point{ 0, 0 };
		size_t size = _gameFieldController->GetSizeField();

		for (size_t y = 0; y < size; y++)
		{
			point.y = y;

			for (size_t x = 0; x < size; x++)
			{
				point.x = x;

				switch (_gameFieldController->GetFieldElement(point))
				{
				case 0:
					std::cout << ' ';
					break;
				case 1:
					std::cout << '#';
					break;
				case 2:
					std::cout << '*';
					break;
				case 3:
					std::cout << '&';
					break;
				case 4:
					std::cout << '$';
					break;
				case 5:
					std::cout << '@';
					break;				
				}								
			}

			std::cout << std::endl;
		}

		std::cout << "Количество очков: " << _numberOfPoints << std::endl;		
	}

	void Game::Init()
	{
		Point2D<size_t> startPoint{ 10,10 };
		
		_snake = _entityCreator->CreateSnake(startPoint, 2);
		_gameFieldController->AddSnakeOnField(_snake);

		//AddFruit();

		_numberOfPoints = 0;
		_gameOver = false;
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
				//std::cout << "RIGHT" << std::endl;
				break;					
			case Direction::LEFT:
				s.coordinates.x -= 1;
				//std::cout << "LEFT" << std::endl;
				break;					
			case Direction::UP:
				s.coordinates.y += 1;
				//std::cout << "UP" << std::endl;
				break;					
			case Direction::DOWN:
				s.coordinates.y -= 1;
				//std::cout << "DOWN" << std::endl;
				break;						
		}

		_snake->UpdateElement(s);
	}
}
