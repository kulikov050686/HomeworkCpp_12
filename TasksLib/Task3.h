#pragma once
#include <iostream>
#include"ITask.h"
#include "../ConvertLib/Convert.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// ������ 3
/// </summary>
class Task3 : public ITask
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	Task3() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Run() override;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Task3() = default;

private:

	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="matrix"> ������� </param>
	void PrintMatrix(Matrix& matrix);
};

