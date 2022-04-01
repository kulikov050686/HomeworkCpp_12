#pragma once
#include <vector>
#include "IShip.h"
#include "Point.h"
#include "Placement.h"
#include "Coordinates.h"
#include "Direction.h"
#include "ResultOfShot.h"

/// <summary>
/// Модель корабля
/// </summary>
class Ship : public IShip
{
public:

	/// <summary>
	/// Конструктор для однопалубного корабля
	/// </summary>
	/// <param name="shipCoordinate"> Координаты корабля </param>
	Ship(Point2D<uint16_t> shipCoordinate);
	
	/// <summary>
	/// Конструктор для многопалубного корабля
	/// </summary>
	/// <param name="shipCoordinate"> Координаты корабля </param>
	/// <param name="numberOfDecks"> Количество палуб у корабля </param>
	/// <param name="direction"> Направление </param>
	Ship(Point2D<uint16_t> shipCoordinate, uint16_t numberOfDecks, Direction direction);

	/// <summary>
	/// Получить размещение
	/// </summary>	
	Placement GetPlacement() override;

	/// <summary>
	/// Получить количество палуб
	/// </summary>	
	uint16_t GetNumberOfDecks() override;

	/// <summary>
	/// Получить координаты местоположения
	/// </summary>	
	Coordinates<Point2D<int16_t>> GetLocationCoordinates() override;

	/// <summary>
	/// Получить палубу корабля
	/// </summary>
	/// <param name="number"> Номер палубы </param>	
	uint16_t GetShipDeck(uint16_t number) override;

	/// <summary>
	/// Получить принадлежность точки кораблю
	/// </summary>
	/// <param name="point"> Точка </param>
	bool GetPointBelongingToShip(Point2D<uint16_t> point) override;

	/// <summary>
	/// Нападение на корабль
	/// </summary>
	/// <param name="point"> Точка </param>	
	ResultOfShot AttackOnShip(Point2D<uint16_t> point) override;

	/// <summary>
	/// Получить количество попаданий
	/// </summary>
	uint16_t GetNumberOfHits() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Ship() = default;

private:

	/// <summary>
	/// Координаты корабля
	/// </summary>
	Coordinates<Point2D<int16_t>> _shipCoordinate{ 0, 0, 0, 0 };

	/// <summary>
	/// Направление
	/// </summary>
	Direction _direction = Direction::RIGHT;

	/// <summary>
	/// Размещение
	/// </summary>
	Placement _placement = Placement::HORIZONTALLY;

	/// <summary>
	/// Количество палуб у корабля
	/// </summary>
	uint16_t _numberOfDecks = 1;

	/// <summary>
	/// Количество попаданий
	/// </summary>
	uint16_t _numberOfHits = 0;

	/// <summary>
	/// Корабль
	/// </summary>
	std::vector<uint16_t> _ship;

	/// <summary>
	/// Создать корабль
	/// </summary>
	void CreateShip();

	/// <summary>
	/// Создать координаты корабля
	/// </summary>
	/// <param name="shipCoordinate"> Координаты отсчёта </param>
	void CreateShipCoordinate(Point2D<uint16_t> shipCoordinate);
};
