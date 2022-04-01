#pragma once
#include <iostream>
#include <memory>
#include "ITask.h"
#include "../SeaBattleLib/SeaBattle.h"

/// <summary>
/// Задача 9
/// </summary>
class Task9 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task9(std::shared_ptr<SeaBattle> seaBattle);

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task9() = default;

private:

	/// <summary>
	/// Игра морской бой
	/// </summary>
	std::shared_ptr<SeaBattle> _seaBattle;
};
