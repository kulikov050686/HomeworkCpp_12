#pragma once
#include <iostream>
#include <memory>
#include "../MenuLib/MenuController.h"
#include "../TasksLib/TasksLocator.h"

namespace HomeWorkCpp_12
{
	class HomeWork
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		HomeWork() = default;

		/// <summary>
		/// Запуск
		/// </summary>
		void Run(std::shared_ptr<IMenuController> menuController,
				 std::shared_ptr<TasksLocator> taskLocator);

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~HomeWork() = default;

	private:

		/// <summary>
		/// Запрет присваивания
		/// </summary>	
		HomeWork& operator = (const HomeWork&) = delete;

		/// <summary>
		/// Запрет копирования
		/// </summary>	
		HomeWork(const HomeWork&) = delete;
	};
}
