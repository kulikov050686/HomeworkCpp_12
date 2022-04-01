#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ITask.h"
#include "../ConvertLib/Convert.h"

/// <summary>
/// Задача 7
/// </summary>
class Task7 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task7() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task7() = default;

private:

	/// <summary>
	/// Размер пупырки
	/// </summary>
	size_t _size = 12;

	/// <summary>
	/// Координата X начала региона
	/// </summary>
	size_t _beginningX = 0;

	/// <summary>
	/// Координата Y начала региона
	/// </summary>
	size_t _beginningY = 0;

	/// <summary>
	/// Координата X конца региона
	/// </summary>
	size_t _endX = 0;

	/// <summary>
	/// Координата Y конца региона
	/// </summary>
	size_t _endY = 0;

	/// <summary>
	/// Пупырка
	/// </summary>
	std::vector<std::vector<bool>> _pupyrka;

	/// <summary>
	/// Иннициализация
	/// </summary>
	void Init();

	/// <summary>
	/// Лопать пупырку
	/// </summary>
	void Burst();

	/// <summary>
	/// Печать пупырки
	/// </summary>
	bool Print();	
};

