#pragma once
#include <vector>
#include "IGameMap.h"

/// <summary>
/// ������ ������� �����
/// </summary>
/// <typeparam name="T"> ��� ������ �������� ������� ����� </typeparam>
template <typename T>
class GameMap : public IGameMap<T>
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="numberOfColumns"> ���������� ������� </param>
	/// <param name="numberOfRows"> ���������� ����� </param>
	GameMap(size_t numberOfColumns, size_t numberOfRows);
	
	// <summary>
	/// �������� ���������� �����
	/// </summary>	
	size_t GetNumberOfRows() override;

	/// <summary>
	/// �������� ���������� �������
	/// </summary>	
	size_t GetNumberOfColumns() override;

	/// <summary>
	/// �������� ������ ��������
	/// </summary>
	/// <param name="row"> ����� ���� </param>
	/// <param name="column"> ����� ������� </param>	
	T GetElement(size_t row, size_t column) override;

	/// <summary>
	/// ������ ������ ��������
	/// </summary>
	/// <param name="row"> ����� ���� </param>
	/// <param name="column"> ����� ������� </param>
	/// <param name="data"> ������ </param>	
	void SetElement(size_t row, size_t column, T data) override;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~GameMap() = default;

public:

	/// <summary>
	/// ���������� �������
	/// </summary>
	size_t _numberOfColumns = 0;

	/// <summary>
	/// ���������� �����
	/// </summary>
	size_t _numberOfRows = 0;

	/// <summary>
	/// ������� �����
	/// </summary>
	std::vector<std::vector<T>> _gameMap;

	/// <summary>
	/// �������������
	/// </summary>
	void Init();
};
