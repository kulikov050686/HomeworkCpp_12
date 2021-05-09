#pragma once
#include <iostream>

class Convert
{
private:

	/// <summary>
	/// Проверяет является ли символ цифрой
	/// </summary>	
	static bool Numeral(char chr);

	/// <summary>
	/// Удаляет все пробелы в строке
	/// </summary>	
	static std::string RemoveSpaces(std::string str);

	/// <summary>
	/// Удаляет нули стоящие перед целым числом
	/// </summary>	
	static std::string RemoveZeros(std::string str);
		
public:

	/// <summary>
	/// Преобразует строку в целое число
	/// </summary>
	static bool ToInt(std::string strNumber, int& number);

	/// <summary>
	/// Преобразует строку в действительное число
	/// </summary>
	static bool ToDouble(std::string strNumber, double& number);

	/// <summary>
	/// Преобразует целое число в строку
	/// </summary>	
	static std::string ToString(int number);

	/// <summary>
	/// Преобразует строку в целое число без знака
	/// </summary>	
	static bool ToUint(std::string strNumber, unsigned int& number);
};
