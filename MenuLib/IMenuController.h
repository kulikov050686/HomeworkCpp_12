#pragma once
#include <iostream>

/// <summary>
/// Интерфейс контроллера меню
/// </summary>
class IMenuController
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IMenuController() = default;

	/// <summary>
	/// Выбор пункта меню
	/// </summary>
	/// <param name="text"> Текст заголовка </param>	
	virtual int SelectedMenuItem(const std::string text) = 0;

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	IMenuController& operator = (const IMenuController&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	IMenuController(const IMenuController&) = delete;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IMenuController() = default;
};
