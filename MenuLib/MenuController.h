#pragma once
#include <functional>
#include <vector>
#include <conio.h>
#include <string>
#include <memory>
#include "Menu.h"
#include "IMenuController.h"

/// <summary>
/// Класс контроллера меню
/// </summary>
class MenuController : public IMenuController
{
private:

	/// <summary>
	/// Меню
	/// </summary>
	std::shared_ptr<IMenu> _menu;
		
	/// <summary>
	/// Количество пунктов меню
	/// </summary>
	int _sizeMenu = 0;
		
	/// <summary>
	/// Функция отрисовки текста
	/// </summary>
	std::function<void(std::string)> _funcPrint;
		
	/// <summary>
	/// Печать пунктов меню
	/// </summary>
	/// <param name="selection"> Номер пункта меню </param>
	/// <param name="text"> Текст заголовка </param>
	void PrintMenu(int selection, const std::string text);

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	MenuController& operator = (const MenuController&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	MenuController(const MenuController&) = delete;

public:

	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="menu"> Меню </param>
	/// <param name="funcPrint"> Функция отображения пунктов меню </param>
	MenuController(std::shared_ptr<IMenu> menu, std::function<void(std::string)> funcPrint);
	
	/// <summary>
	/// Выбор пункта меню
	/// </summary>
	/// <param name="text"> Текст заголовка </param>	
	int SelectedMenuItem(const std::string text) override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~MenuController() = default;
};
