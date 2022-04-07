#pragma once
#include <iostream>
#include <memory>
#include "GameFieldController.h"
#include "FruitController.h"
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Класс игра
	/// </summary>
	class Game
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="controllerLocator"> Локатор контроллеров </param>
		Game(std::shared_ptr<ControllerLocator> controllerLocator);

		/// <summary>
		/// Старт игры
		/// </summary>
		void Start();

		/// <summary>
		/// Дестуктор
		/// </summary>
		virtual ~Game() = default;

	private:

		/// <summary>
		/// Контроллер игрового поля
		/// </summary>
		std::shared_ptr<GameFieldController> _gameFieldController;

		/// <summary>
		/// Контроллер змейки
		/// </summary>
		std::shared_ptr<SnakeController> _snakeController;

		/// <summary>
		/// Контроллер фрукта
		/// </summary>
		std::shared_ptr<FruitController> _fruitController;

		/// <summary>
		/// Количество очков
		/// </summary>
		size_t _numberOfPoints = 0;

		/// <summary>
		/// Печать игрового поля
		/// </summary>		
		void Print();

		/// <summary>
		/// Инициализация
		/// </summary>		
		void Init();
		
		/// <summary>
		/// Добавить фрукт на игровое поле
		/// </summary>
		void AddFruit();
	};
}
