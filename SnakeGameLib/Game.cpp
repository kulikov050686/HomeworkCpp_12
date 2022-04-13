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
		DrowFiled();
	}

	void Game::Timer(int value)
	{		
	}

	void Game::Reshape(int width, int height)
	{
		GLfloat aspectRatio;

		if (height == 0) height = 1;	

		glViewport(0, 0, width, height);

		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		aspectRatio = (GLfloat)width / (GLfloat)height;

		if (width >= height)
		{
			gluOrtho2D(0, 0, width / aspectRatio, height / aspectRatio);
		}
		else
		{
			gluOrtho2D(0, 0, width, height);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/

		

		_widthWindow = width;
		_heightWindow = height;

		_width = width / _gameFieldController->GetSizeField();
		_height = height / _gameFieldController->GetSizeField();

		std::cout << "width: " << _widthWindow << " " << _width << std::endl;
		std::cout << "height: " << _heightWindow << " " << _height << std::endl;		
	}

	void Game::Keyboard(unsigned char key, int x, int y)
	{
	}	

	void Game::Init()
	{
		//Point2D<size_t> startPoint{ 10,10 };
		
		//_snake = _entityCreator->CreateSnake(startPoint, 2);
		//_gameFieldController->AddSnakeOnField(_snake);

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

	void Game::DrowFiled()
	{
		glColor3f(0.0f, 1.0f, 0.0f);

		glBegin(GL_LINES);

		for (int i = 0; i < _widthWindow; i += _width)
		{
			glVertex2f(i, 0);
			glVertex2f(i, _heightWindow);
		}
		
		for (int j = 0; j < _heightWindow; j += _height)
		{
			glVertex2f(0, j);
			glVertex2f(_widthWindow, j);
		}

		glEnd();
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
