#pragma once

/// <summary>
/// ��������� ������ ������� �����
/// </summary>
/// <typeparam name="T"> ��� ������ �������� ������� ����� </typeparam>
template <typename T>
class IGameMap
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	IGameMap() = default;
	
	// <summary>
	/// �������� ���������� �����
	/// </summary>	
	virtual size_t GetNumberOfRows() = 0;

	/// <summary>
	/// �������� ���������� �������
	/// </summary>	
	virtual size_t GetNumberOfColumns() = 0;

	/// <summary>
	/// �������� ������ ��������
	/// </summary>
	/// <param name="row"> ����� ���� </param>
	/// <param name="column"> ����� ������� </param>	
	virtual T GetElement(size_t row, size_t column) = 0;

	/// <summary>
	/// ������ ������ ��������
	/// </summary>
	/// <param name="row"> ����� ���� </param>
	/// <param name="column"> ����� ������� </param>
	/// <param name="data"> ������ </param>	
	virtual void SetElement(size_t row, size_t column, T data) = 0;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~IGameMap() = default;

	/// <summary>
	/// ������ ������������
	/// </summary>	
	IGameMap& operator = (const IGameMap&) = delete;

	/// <summary>
	/// ������ �����������
	/// </summary>	
	IGameMap(const IGameMap&) = delete;
};
