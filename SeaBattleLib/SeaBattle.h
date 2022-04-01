#pragma once
#include <locale.h>
#include <memory>
#include <chrono>
#include <thread>
#include "Game.h"
#include "GameFieldController.h"
#include "ShipController.h"
#include "../InfrastructureLib/GameField.h"
#include "../InfrastructureLib/Templates.h"

/// <summary>
/// Морской бой
/// </summary>
class SeaBattle
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	SeaBattle() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	void Run();

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~SeaBattle() = default;

private:

	/// <summary>
	/// Начальная заставка экрана
	/// </summary>
	void StartScreenSaver();
		
	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	SeaBattle& operator = (const SeaBattle&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	SeaBattle(const SeaBattle&) = delete;
};
