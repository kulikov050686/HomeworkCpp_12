#pragma once

/// <summary>
/// ��������� ����������
/// </summary>
/// <typeparam name="inputType"> ������� ��� ������ </typeparam>
/// <typeparam name="outputType"> �������� ��� ������ </typeparam>
template <typename inputType, typename outputType>
class IConverter
{
public:
	/// <summary>
	/// �����������
	/// </summary>
	IConverter() = default;

	/// <summary>
	/// ����������� ��� inputType � ��� outputType
	/// </summary>	
	virtual outputType Convert(const inputType&) = 0;

	/// <summary>
	/// ����������� ��� outputType � ��� inputType
	/// </summary>	
	virtual inputType ConvertBack(const outputType&) = 0;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~IConverter() = default;

	/// <summary>
	/// ������ �����������
	/// </summary>	
	IConverter(const IConverter&) = delete;

	/// <summary>
	/// ������ ������������
	/// </summary>	
	IConverter& operator = (const IConverter&) = delete;
};
