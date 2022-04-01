#pragma once
#include <memory>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "../InfrastructureLib/Point.h"
#include "Direction.h"
#include "Ship.h"
#include "ShipController.h"
#include "GameFieldController.h"
#include "../ConvertLib/Convert.h"
#include "DataEntry.h"

namespace SeaBattleLib
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
		/// <param name="fieldController1"> Контроллер игрового поля 1 </param>
		/// <param name="fieldController2"> Контроллер игрового поля 2 </param>
		/// <param name="shipController"> Контроллер корабля </param>
		/// <param name="gameLogic"> Игровая логика </param>
		Game(std::shared_ptr<GameFieldController> fieldController1,
			std::shared_ptr<GameFieldController> fieldController2,
			std::shared_ptr<ShipController> shipController);

		/// <summary>
		/// Запуск игры
		/// </summary>
		void Run();

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~Game() = default;

	private:

		/// <summary>
		/// Контроллер игрового поля 1
		/// </summary>
		std::shared_ptr<GameFieldController> _fieldController1;

		/// <summary>
		/// Контроллер игрового поля 2
		/// </summary>
		std::shared_ptr<GameFieldController> _fieldController2;

		/// <summary>
		/// Контроллер корабля
		/// </summary>
		std::shared_ptr<ShipController> _shipController;

		/// <summary>
		/// Игрок
		/// </summary>
		bool _player = true;

		/// <summary>
		/// Печать игрового поля во время заполнения
		/// </summary>
		/// <param name="fieldController"> Контроллер игрового поля </param>
		void Print(std::shared_ptr<GameFieldController> fieldController);

		/// <summary>
		/// Печать игрового поля во время игры
		/// </summary>
		/// <param name="fieldController"> Контроллер игрового поля </param>
		void PrintGame(std::shared_ptr<GameFieldController> fieldController);

		/// <summary>
		/// Создание кораблей на игровом поле
		/// </summary>
		/// <param name="fieldController"> Контроллер игрового поля </param>
		/// <param name="shipController"> Контроллер корабля </param>
		void CreateShipsOnField(std::shared_ptr<GameFieldController> fieldController,
			std::shared_ptr<ShipController> shipController);

		/// <summary>
		/// Атаковать корабль
		/// </summary>
		/// <param name="fieldController"> Контроллер игрового поля </param>	
		void AttackShip(std::shared_ptr<GameFieldController> fieldController);

		/// <summary>
		/// Открыть область
		/// </summary>
		/// <param name="fieldController"> Контроллер игрового поля </param>
		void OpenArea(std::shared_ptr<GameFieldController> fieldController);

		/// <summary>
		/// Запрет присвания
		/// </summary>	
		Game& operator = (const Game&) = delete;

		/// <summary>
		/// Запрет копирования
		/// </summary>
		Game(const Game&) = delete;
	};
}
