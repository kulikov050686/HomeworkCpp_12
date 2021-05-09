#pragma once
#include <iostream>
#include <conio.h>
#include "Menu.h"

class MenuController
{
private:

	/// Меню приложения
	Menu* menu;

	/// Количество пунктов меню
	int SizeMenu;

	/// Печать пунктов меню
	void PrintMenu(int selection, const string text);

public:

	/// Создание нового контроллера меню
	MenuController(const vector<string> itemsMenu);
	
	/// Выбор пункта меню
	int selectedMenuItem(const string text);	

	/// Деструктор
	~MenuController();
};
