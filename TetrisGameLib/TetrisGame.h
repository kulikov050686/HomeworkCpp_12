#pragma once
#include <locale.h>
#include <memory>

/// <summary>
/// ���� ������
/// </summary>
class TetrisGame
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	TetrisGame() = default;

	/// <summary>
	/// ������ ����
	/// </summary>
	void Run();

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~TetrisGame() = default;
};

