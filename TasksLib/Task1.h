#pragma once
#include <iostream>
#include <memory>
#include "ITask.h"
#include "../SnakeGameLib/SnakeGame.h"

/// <summary>
/// ������ 1
/// </summary>
class Task1 : public ITask
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	Task1(std::shared_ptr<SnakeGameLib::SnakeGame> snakeGame);

	/// <summary>
	/// ������
	/// </summary>
	void Run() override;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Task1() = default;

private:

	/// <summary>
	/// ���� ������
	/// </summary>
	std::shared_ptr<SnakeGameLib::SnakeGame> _snakeGame;
};
