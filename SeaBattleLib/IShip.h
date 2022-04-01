#pragma once
#include "Placement.h"
#include "Coordinates.h"
#include "../InfrastructureLib/Point.h"
#include "ResultOfShot.h"

/// <summary>
/// Интерфейс молели корабля
/// </summary>
class IShip
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IShip() = default;

	/// <summary>
	/// Получить размещение
	/// </summary>
	virtual Placement GetPlacement() = 0;

	/// <summary>
	/// Получить количество палуб
	/// </summary>
	virtual uint16_t GetNumberOfDecks() = 0;

	/// <summary>
	/// Получить координаты местоположения
	/// </summary>
	virtual Coordinates<Point2D<int16_t>> GetLocationCoordinates() = 0;

	/// <summary>
	/// Получить палубу корабля
	/// </summary>
	/// <param name="number"> Номер палубы </param>
	virtual uint16_t GetShipDeck(uint16_t number) = 0;

	/// <summary>
	/// Получить принадлежность точки кораблю
	/// </summary>
	/// <param name="point"> Точка </param>	
	virtual bool GetPointBelongingToShip(Point2D<uint16_t> point) = 0;

	/// <summary>
	/// Нападение на корабль
	/// </summary>
	/// <param name="point"> Точка </param>	
	virtual ResultOfShot AttackOnShip(Point2D<uint16_t> point) = 0;

	/// <summary>
	/// Получить количество попаданий
	/// </summary>	
	virtual uint16_t GetNumberOfHits() = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IShip() = default;

	/// <summary>
	/// Запрет присваивания
	/// </summary>
	IShip& operator = (const IShip&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>
	IShip(const IShip&) = delete;
};
