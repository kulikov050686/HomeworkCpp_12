#include <iostream>
#include <memory>
#include "HomeWork.h"
#include "../MenuLib/MenuController.h"
#include "../TasksLib/TasksLocator.h"

namespace HomeWorkCpp_12
{
	/// <summary>
	/// Функция создания меню
	/// </summary>
	std::shared_ptr<IMenuController> CreateMenu()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

		std::vector<std::string> item = { "Task 1",
										  "Task 2",
										  "Task 3",
										  "Task 4",
										  "Task 5",
										  "Task 6",
										  "Task 7",
										  "Task 8",
										  "Task 9",
										  "Exit" };

		return std::make_shared<MenuController>(std::make_shared<Menu>(item), [](std::string text)
			{
				std::cout << text << std::endl;
			});
	}	
}

/// <summary>
/// Точка входа приложения
/// </summary>
int main()
{
	HomeWorkCpp_12::HomeWork* homework = new HomeWorkCpp_12::HomeWork();
	homework->Run(HomeWorkCpp_12::CreateMenu(), std::make_shared<TasksLocator>());

	return 0;
}
