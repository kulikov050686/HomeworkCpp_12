#pragma once
#include <string>
#include <vector>
#include "IMenu.h"

/// <summary>
/// Класс меню
/// </summary>
class Menu : public IMenu
{
private:

	/// <summary>
	/// Количество пунктов меню
	/// </summary>
	int _sizeMenu = 0;

	/// <summary>
	/// Названия пунктов меню
	/// </summary>
	std::vector<std::string> _itemsName;

	/// <summary>
	/// Запрет копировария
	/// </summary>	
	Menu(const Menu& object) = delete;

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	Menu& operator = (const Menu&) = delete;

public:

	/// <summary>
	/// Конструктор меню
	/// </summary>
	/// <param name="nameItemsMenu"> Список названий пунктов меню </param>
	Menu(std::vector<std::string> nameItemsMenu);
	
	/// <summary>
	/// Получить название пункта меню по номеру
	/// </summary>
	/// <param name="menuItemNumber"> Номер пункта меню </param>	
	std::string GetItemMenu(int menuItemNumber) override;

	/// <summary>
	/// Количество пунктов меню
	/// </summary>	
	int GetSizeMenu() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Menu() = default;
};
