#pragma once
#include <list>
#include <iterator>
#include <memory>
#include "../InfrastructureLib/Point.h"
#include "IShip.h"
#include "../InfrastructureLib/IGameField.h"
#include "ResultOfShot.h"
#include "Coordinates.h"

namespace SeaBattleLib
{
	/// <summary>
	/// Контроллер игрового поля
	/// </summary>
	class GameFieldController
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="field"> Игровое поле </param>
		GameFieldController(std::shared_ptr<IGameField<uint16_t>> field);

		/// <summary>
		/// Добавить корабль на игровое поле
		/// </summary>
		/// <param name="ship"> Корабль </param>
		bool AddShipOnField(std::shared_ptr<IShip> ship);

		/// <summary>
		/// Получить размер игрового поля
		/// </summary>
		uint16_t GetSizeField();

		/// <summary>
		/// Очистить игровое поле
		/// </summary>
		void ClearField();

		/// <summary>
		/// Задать элемент игрового поля
		/// </summary>
		/// <param name="point"> Точка игрового поля </param>
		/// <param name="data"> Данные </param>
		void SetFieldElement(Point2D<uint16_t> point, uint16_t data);

		/// <summary>
		/// Получить элемент игрового поля
		/// </summary>
		/// <param name="point"> Точка игрового поля </param>
		uint16_t GetFieldElement(Point2D<uint16_t> point);

		/// <summary>
		/// Выстрел по кораблю
		/// </summary>
		/// <param name="pointOfShot"> Точка встрела </param>
		ResultOfShot ShootAtShip(Point2D<uint16_t> pointOfShot);

		/// <summary>
		/// Количество кораблей на игровом поле
		/// </summary>	
		size_t NumberOfShipsOnField();

		/// <summary>
		/// Отсутствие кораблей на игровом поле
		/// </summary>	
		bool NoShipsOnField();

		/// <summary>
		/// Получить координаты затонувшего корабля
		/// </summary>	
		Coordinates<Point2D<int16_t>> GetCoordinatesOfSunkenShip();

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~GameFieldController() = default;

	private:

		/// <summary>
		/// Размер игрового поля
		/// </summary>
		uint16_t _sizeField = 0;

		/// <summary>
		/// Игровое поле
		/// </summary>
		std::shared_ptr<IGameField<uint16_t>> _field;

		/// <summary>
		/// Список кораблей
		/// </summary>
		std::list<std::shared_ptr<IShip>> _listShips;

		/// <summary>
		/// Координаты затонувшего корабля
		/// </summary>
		Coordinates<Point2D<int16_t>> _coordinatesOfSunkenShip{ -1,-1,-1,-1 };

		/// <summary>
		/// Проверка выхода за границы
		/// </summary>
		/// <param name="ship"> Корабль </param>
		bool CheckingBoundaries(std::shared_ptr<IShip> ship);

		/// <summary>
		/// Проверка столкновений кораблей
		/// </summary>
		/// <param name="ship"> Корабль </param>
		bool CollisionChecking(std::shared_ptr<IShip> ship);

		/// <summary>
		/// Результат атаки
		/// </summary>
		/// <param name="point"> Точка атаки </param>
		/// <param name="numberOfDecks"> Количество палуб </param>	
		ResultOfShot ResultOfAttack(Point2D<uint16_t> point, uint16_t numberOfDecks);

		/// <summary>
		/// Запрет присваивания
		/// </summary>
		GameFieldController& operator = (const GameFieldController&) = delete;

		/// <summary>
		/// Запрет копирования
		/// </summary>
		GameFieldController(const GameFieldController&) = delete;
	};
}
