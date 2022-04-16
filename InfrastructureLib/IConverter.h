#pragma once

/// <summary>
/// Интерфейс конвертера
/// </summary>
/// <typeparam name="inputType"> Входной тип данных </typeparam>
/// <typeparam name="outputType"> Выходной тип данных </typeparam>
template <typename inputType, typename outputType>
class IConverter
{
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	IConverter() = default;

	/// <summary>
	/// Преобразует тип inputType в тип outputType
	/// </summary>	
	virtual outputType Convert(const inputType&) = 0;

	/// <summary>
	/// Преобразует тип outputType в тип inputType
	/// </summary>	
	virtual inputType ConvertBack(const outputType&) = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IConverter() = default;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	IConverter(const IConverter&) = delete;

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	IConverter& operator = (const IConverter&) = delete;
};
