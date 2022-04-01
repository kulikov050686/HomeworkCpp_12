#include "Menu.h"
#include "pch.h"

Menu::Menu(std::vector<std::string> nameItemsMenu)
{
	_sizeMenu = nameItemsMenu.size();
	
	if (_sizeMenu > 0)
	{
		_itemsName.resize(_sizeMenu);

		for (int i = 0; i < _sizeMenu; i++)
		{
			_itemsName[i] = nameItemsMenu[i];
		}
	}
	else
	{
		throw "Error: the number of menu items cannot be 0!!!";
	}
}

std::string Menu::GetItemMenu(int menuItemNumber)
{
	if (0 <= menuItemNumber && menuItemNumber < _sizeMenu)
	{
		return _itemsName[menuItemNumber];
	}

	return "Error!";
}

int Menu::GetSizeMenu()
{
	return _sizeMenu;
}
