#pragma once
#include <iostream>
#include <random>
#include "ITask.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// ������ 5
/// </summary>
class Task5 : public ITask
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	Task5() = default;

	/// <summary>
	/// ���������
	/// </summary>
	void Run() override;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Task5() = default;

private:

	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="matrix"> ������� </param>
	void PrintMatrix(Matrix& matrix);

	/// <summary>
	/// ��������� ������� ������������� �������
	/// </summary>
	/// <param name="matrix"> ������� </param>
	/// <param name="min"> ����������� ����� </param>
	/// <param name="max"> ������������ ����� </param>
	/// <param name="k"> ����������� </param>
	void FillMatrixRandomly(Matrix& matrix, int min, int max, double k = 1);

	/// <summary>
	/// ��������� ��������� ����� [min, max)
	/// </summary>
	/// <param name="min"> ����������� �������� </param>
	/// <param name="max"> ������������ �������� </param>
	int Random(int min, int max);
};
