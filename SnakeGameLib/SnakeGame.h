#pragma once
#include <locale.h>
#include <memory>

/// <summary>
/// ���� ������
/// </summary>
class SnakeGame
{
public:
	
	/// <summary>
	/// �����������
	/// </summary>
	SnakeGame() = default;

	/// <summary>
	/// ������ ����
	/// </summary>
	void Run();

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~SnakeGame() = default;
};
