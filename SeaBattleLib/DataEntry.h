#pragma once
#include <iostream>
#include <string>
#include "../InfrastructureLib/Point.h"
#include "Direction.h"
#include "../ConvertLib/Convert.h"

/// <summary>
/// Класс ввода данных
/// </summary>
class DataEntry
{
public:

	/// <summary>
	/// Ввод направления
	/// </summary>
	/// <param name="direction"> Направление </param>	
	static bool EnteringDirection(Direction& direction);

	/// <summary>
	/// Ввод координат
	/// </summary>
	/// <param name="point"> Координата точки </param>	
	static bool EnterCoordinates(Point2D<uint16_t>& point);

private:

	/// <summary>
	/// Проверка буквенного символа
	/// </summary>
	/// <param name="symbol"> Буквенный символ </param>	
	static bool CheckingLetterSymbol(char symbol);

	/// <summary>
	/// Проверка числового символа
	/// </summary>
	/// <param name="symbol"> Числовой символ </param>	
	static bool CheckingNumericCharacter(char symbol);

	/// <summary>
	/// Преобразователь символов
	/// </summary>
	/// <param name="symbol"> Символ </param>	
	static uint16_t CharacterConverter(char symbol);

	/// <summary>
	/// Удаляет все пробелы в строке
	/// </summary>
	/// <param name="str"> Строка </param>	
	static std::string RemoveSpaces(std::string str);
};

