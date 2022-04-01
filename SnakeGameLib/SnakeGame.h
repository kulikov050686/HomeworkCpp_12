#pragma once
#include <locale.h>
#include <memory>
#include "../InfrastructureLib/GameField.h"
#include "../InfrastructureLib/Templates.h"

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

private:

	/// <summary>
	/// ������ ������������
	/// </summary>	
	SnakeGame& operator = (const SnakeGame&) = delete;

	/// <summary>
	/// ������ �����������
	/// </summary>	
	SnakeGame(const SnakeGame&) = delete;
};
