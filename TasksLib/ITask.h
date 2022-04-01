#pragma once

/// <summary>
/// Интерфейс задача
/// </summary>
class ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	ITask() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	virtual void Run() = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~ITask() = default;

	/// <summary>
	/// Запрет присваивания
	/// </summary>
	ITask& operator = (const ITask&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>
	ITask(const ITask&) = delete;
};
