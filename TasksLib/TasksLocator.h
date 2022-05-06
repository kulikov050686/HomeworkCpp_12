#pragma once
#include <memory>
#include "ITask.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"
#include "Task6.h"
#include "Task7.h"
#include "Task8.h"
#include "Task9.h"
#include "../SnakeGameLib/Game.h"
#include "../SnakeGameLib/ControllerLocator.h"
#include "../TetrisGameLib/Game.h"

/// <summary>
/// Локатор задач
/// </summary>
class TasksLocator
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	TasksLocator() = default;

	/// <summary>
	/// Задача 1
	/// </summary>
	std::shared_ptr<ITask> GetTask1() 
	{
		auto controller = std::make_shared<SnakeGameLib::ControllerLocator>();
		auto game = std::make_shared<SnakeGameLib::Game>(controller);
		auto snakeGame = std::make_shared<SnakeGameLib::SnakeGame>(game);

		return std::make_shared<Task1>(snakeGame);
	}

	/// <summary>
	/// Задача 2
	/// </summary>
	std::shared_ptr<ITask> GetTask2() 
	{
		auto task = std::make_shared<Task2>();
		task->SetMenuGameOver(CreateMenuGameOver());

		return task;
	}

	/// <summary>
	/// Задача 3
	/// </summary>
	std::shared_ptr<ITask> GetTask3() { return std::make_shared<Task3>(); }

	/// <summary>
	/// Задача 4
	/// </summary>
	std::shared_ptr<ITask> GetTask4() { return std::make_shared<Task4>(); }

	/// <summary>
	/// Задача 5
	/// </summary>
	std::shared_ptr<ITask> GetTask5() { return std::make_shared<Task5>(); }

	/// <summary>
	/// Задача 6
	/// </summary>
	std::shared_ptr<ITask> GetTask6() { return std::make_shared<Task6>(); }

	/// <summary>
	/// Задача 7
	/// </summary>	
	std::shared_ptr<ITask> GetTask7() { return std::make_shared<Task7>(); }

	/// <summary>
	/// Задача 8
	/// </summary>	
	std::shared_ptr<ITask> GetTask8() 
	{
		auto game = std::make_shared<TetrisGameLib::Game>();
		auto tetrisGame = std::make_shared<TetrisGameLib::TetrisGame>(game);

		return std::make_shared<Task8>(tetrisGame);
	}

	/// <summary>
	/// Задача 9
	/// </summary>	
	std::shared_ptr<ITask> GetTask9() { return std::make_shared<Task9>(std::make_shared<SeaBattleLib::SeaBattle>()); }
 
	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~TasksLocator() = default;

private:

	/// <summary>
	/// Меню завершения игры
	/// </summary>
	std::shared_ptr<IMenuController> CreateMenuGameOver()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

		std::vector<std::string> item = { "Да",
										  "Нет" };

		return std::make_shared<MenuController>(std::make_shared<Menu>(item), [](std::string text)
			{
				std::cout << text << std::endl;
			});
	}

	/// <summary>
	/// Запрет присваивания
	/// </summary>
	TasksLocator& operator = (const TasksLocator&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>
	TasksLocator(const TasksLocator&) = delete;
};
