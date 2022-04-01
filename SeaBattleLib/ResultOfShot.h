#pragma once

/// <summary>
/// Результат выстрела
/// </summary>
enum class ResultOfShot
{
	/// <summary>
	/// Промахнулся
	/// </summary>
	MISSED = 0,

	/// <summary>
	/// Ранил
	/// </summary>
	WOUNDED = 1,

	/// <summary>
	/// Убил
	/// </summary>
	KILLED = 2
};
