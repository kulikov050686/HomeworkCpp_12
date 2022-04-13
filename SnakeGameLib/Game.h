#pragma once
#include <iostream>
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

		/// <summary>
		/// Движение змейки
		/// </summary>
		/// /// <param name="direction"> Направление </param>
		void SnakeMovement(Direction direction);
		
		/// <summary>
		/// Попасть на змею
		/// </summary>
		/// <param name="fruit"> Фрукт </param>
		/// <param name="snake"> Змея </param>
		bool GetOnSnake(std::shared_ptr<IFruit> fruit, std::shared_ptr<ISnake<uint16_t>> snake);		
	};
}
