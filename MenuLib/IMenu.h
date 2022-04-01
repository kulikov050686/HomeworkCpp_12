#pragma once
#include <iostream>

/// <summary>
/// Интерфейс меню
/// </summary>
class IMenu
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IMenu() = default;

	/// <summary>
	/// Получить название пункта меню по номеру
	/// </summary>
	/// <param name="menuItemNumber"> Номер пункта меню </param>	
	virtual std::string GetItemMenu(int menuItemNumber) = 0;

	/// <summary>
	/// Количество пунктов меню
	/// </summary>	
	virtual int GetSizeMenu() = 0;

	/// <summary>
	/// Запрет копировария
	/// </summary>	
	IMenu(const IMenu& object) = delete;

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	IMenu& operator = (const IMenu&) = delete;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IMenu() = default;
};
