#pragma once
#include <iostream>
#include "ITask.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// ������ 4
/// </summary>
class Task4 : public ITask
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	Task4() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Run() override;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Task4() = default;

private:

	/// <summary>
	/// ���� ������
	/// </summary>
	/// <param name="matrix"> ������� </param>
	void DataInputInMatrix(Matrix& matrix);

	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="matrix"> ������� </param>
	void PrintMatrix(Matrix& matrix);
};
