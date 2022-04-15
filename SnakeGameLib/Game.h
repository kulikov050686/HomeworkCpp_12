#pragma once
#include <iostream>
#include <GL/GL.h>
#include <memory>
#include "GameFieldController.h"
#include "../InfrastructureLib/Point.h"
#include "../RandomLib/Random.h"
#include "../InfrastructureLib/Direction.h"
#include "../InfrastructureLib/IGame.h"
#include "IFruit.h"
#include "ISnake.h"
#include "EntityCreator.h"
#include "TypeOfFruit.h"
#include "ControllerLocator.h";
#include "ColorRGB.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Класс игра
	/// </summary>
	class Game : public IGame
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="controllerLocator"> Локатор контроллеров </param>
		Game(std::shared_ptr<ControllerLocator> controllerLocator);

		/// <summary>
		/// Отрисовать
		/// </summary>
		void Draw() override;

		// <summary>
		/// Таймер
		/// </summary>
		/// <param name="value"></param>
		void Timer(int value) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="width"></param>
		/// <param name="height"></param>
		void Reshape(int width, int height) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="key"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		void Keyboard(unsigned char key, int x, int y) override;

		/// <summary>
		/// 
		/// </summary>
		void Idel() override;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~Game() = default;

	private:

		/// <summary>
		/// Контроллер игрового поля
		/// </summary>
		std::shared_ptr<GameFieldController> _gameFieldController;

		/// <summary>
		/// Создатель сущностей
		/// </summary>
		std::shared_ptr<EntityCreator> _entityCreator;

		/// <summary>
		/// Контроллер змейки
		/// </summary>
		std::shared_ptr<ISnake<uint16_t>> _snake;

		/// <summary>
		/// Контроллер фрукта
		/// </summary>
		std::shared_ptr<IFruit> _fruit;

		/// <summary>
		/// Количество очков
		/// </summary>
		size_t _numberOfPoints = 0;

		/// <summary>
		/// Завершение игры
		/// </summary>
		bool _gameOver = false;

		/// <summary>
		/// Направление
		/// </summary>
		Direction _direction;

		/// <summary>
		/// Текущее направление
		/// </summary>
		Direction _currentDirection;

		/// <summary>
		/// Ширина окна
		/// </summary>
		int _widthWindow = 0;

		/// <summary>
		/// Высота окна
		/// </summary>
		int _heightWindow = 0;

		/// <summary>
		/// Смещение
		/// </summary>
		GLint _shift = 0;

		/// <summary>
		/// Инициализация
		/// </summary>		
		void Init();
		
		/// <summary>
		/// Добавить фрукт на игровое поле
		/// </summary>
		void AddFruit();

		/// <summary>
		/// Движение змейки
		/// </summary>		
		void SnakeMovement();
		
		/// <summary>
		/// Попасть на змею
		/// </summary>
		/// <param name="fruit"> Фрукт </param>
		/// <param name="snake"> Змея </param>
		bool GetOnSnake(std::shared_ptr<IFruit> fruit, std::shared_ptr<ISnake<uint16_t>> snake);

		/// <summary>
		/// Прямоугольник
		/// </summary>		
		/// <param name="rectangleCoordinates"> Координаы прямоугольника </param>
		/// <param name="color"> Цвет </param>
		/// <param name="size"> Размер </param>
		void Rectangle(Point2D<GLint> rectangleCoordinates, ColorRGB<GLfloat> color, GLint size);
	};
}
