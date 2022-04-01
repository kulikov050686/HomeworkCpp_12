#pragma once
#include <memory>
#include "Ship.h"
#include "../InfrastructureLib/Point.h"
#include "Placement.h"
#include "Direction.h"

namespace SeaBattleLib
{
	/// <summary>
	/// Контроллер корабля
	/// </summary>
	class ShipController
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		ShipController() = default;

		/// <summary>
		/// Создать однопалубный корабль
		/// </summary>
		/// <param name="shipCoordinate"> Координаты корабля </param>	
		std::shared_ptr<IShip> CreateShip(Point2D<uint16_t> shipCoordinate);

		/// <summary>
		/// Создать многопалубный корабль
		/// </summary>
		/// <param name="shipCoordinate"> Координаты корабля </param>
		/// <param name="numberOfDecks"> Количество палуб у корабля </param>
		/// <param name="direction"> Направление </param>	
		std::shared_ptr<IShip> CreateShip(Point2D<uint16_t> shipCoordinate,
			uint16_t numberOfDecks,
			Direction direction);

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~ShipController() = default;

	private:

		/// <summary>
		/// Запрет присваивания
		/// </summary>	
		ShipController& operator = (const ShipController&) = delete;

		/// <summary>
		/// Запрет копирования
		/// </summary>	
		ShipController(const ShipController&) = delete;
	};
}
