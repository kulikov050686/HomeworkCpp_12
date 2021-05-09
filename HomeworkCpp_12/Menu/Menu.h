#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:

	/// Количество пунктов меню
	int SizeMenu = 0;

	/// Название пунктов меню
	string* ItemsName = nullptr;

public:

	/// Конструктор меню	
	Menu(const vector<string> nameItemsMenu);

	/// Конструктор копирования
	Menu(const Menu& object);

	/// Получить название пункта меню по номеру
	string getItemMenu(const int menuItemNumber);

	/// Деструктор
	~Menu();
};
