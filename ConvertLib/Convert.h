#pragma once
#include <iostream>
#include <string>

/// <summary>
/// Конвертация чисел в строки и обратно
/// </summary>
class Convert
{
public:

	/// <summary>
	/// Преобразует строку в короткое целое число без знака
	/// </summary>	
	static bool ToUshort(std::string strNumber, unsigned short& number);

	/// <summary>
	/// Преобразует строку в целое число
	/// </summary>
	static bool ToInt(std::string strNumber, int& number);

	/// <summary>
	/// Преобразует строку в целое число без знака
	/// </summary>	
	static bool ToUint(std::string strNumber, unsigned int& number);

	/// <summary>
	/// Преобразует строку в действительное число
	/// </summary>
	static bool ToDouble(std::string strNumber, double& number);

	/// <summary>
	/// Преобразует строку в длинное целое число без знака
	/// </summary>	
	static bool ToUlong(std::string strNumber, unsigned long& number);

	/// <summary>
	/// Преобразует строку в длинное целое число
	/// </summary>	
	static bool ToLong(std::string strNumber, long& number);

	/// <summary>
	/// Преобразует строку в длинное целое число без знака
	/// </summary>	
	static bool ToUlonglong(std::string strNumber, size_t& number);

	/// <summary>
	/// Преобразует короткое целое число без знака в строку
	/// </summary>	
	static std::string ToString(unsigned char number);

	/// <summary>
	/// Преобразует целое число в строку
	/// </summary>	
	static std::string ToString(int number);

	/// <summary>
	/// Преобразует дробное число в строку
	/// </summary>	
	static std::string ToString(double number);

	/// <summary>
	/// Преобразует длинное целое число без знака в строку
	/// </summary>	
	static std::string ToString(unsigned long number);

	/// <summary>
	/// Преобразует длинное целое число в строку
	/// </summary>	
	static std::string ToString(long number);

	/// <summary>
	/// Преобразует длинное целое число без знака в строку
	/// </summary>	
	static std::string ToString(unsigned long long number);
};
