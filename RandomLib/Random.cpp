#include "pch.h"
#include "Random.h"

size_t Random::Next(const size_t min, const size_t max)
{
	std::random_device rd;								 // Генерируем случайное число
	std::mt19937 mersenne(rd());						 // Инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_int_distribution<size_t> uid(min, max); // Указываем диапазон
	
	return uid(mersenne);
}

size_t Random::Next(const size_t max)
{
	std::random_device rd;								 // Генерируем случайное число
	std::mt19937 mersenne(rd());						 // Инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_int_distribution<size_t> uid(0, max);   // Указываем диапазон

	return uid(mersenne);
}

double Random::Next()
{
	std::random_device rd;		                      // Генерируем случайное число
	std::mt19937 mersenne(rd());				      // Инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<double> urd(0, 1); // Указываем диапазон

	return urd(mersenne);
}
