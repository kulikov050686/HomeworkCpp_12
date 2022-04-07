#pragma once
#include <iostream>
#include <memory>
#include "GameFieldController.h"
#include "../InfrastructureLib/Point.h"
#include "IFruit.h"
#include "ISnake.h"
#include "EntityCreator.h"

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
