#pragma once
#include <random>

/// <summary>
/// Генерация случайных чисел
/// </summary>
class Random
{
public:

	/// <summary>
	/// Генерирует случайное целое число без знака [min, max]
	/// </summary>
	/// <param name="min"> Минимальное значение </param>
	/// <param name="max"> Максимальное значение </param>
	static size_t Next(const size_t min, const size_t max);

	/// <summary>
	/// Генерирует случайное целое число [0, max]
	/// </summary>
	/// <param name="max"> Максимальное значение </param>
	static size_t Next(const size_t max);

	/// <summary>
	/// Генерирует случайное действительное число [0, 1]
	/// </summary>	
	static double Next();	
};
