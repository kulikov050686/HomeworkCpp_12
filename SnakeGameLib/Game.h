#pragma once
#include <iostream>
#include <memory>
#include "GameFieldController.h"
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
		/// <param name="gameFieldController"> Конструктор игрового поля </param>
		Game(std::shared_ptr<GameFieldController> gameFieldController);

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
		/// Печать игрового поля
		/// </summary>		
		void Print();

		/// <summary>
		/// Инициализация
		/// </summary>		
		void Init();

		/// <summary>
		/// Инициализация игрового поля
		/// </summary>
		void InitGameField();
	};
}
