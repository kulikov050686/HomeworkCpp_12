#pragma once

/// <summary>
/// ��������� ����
/// </summary>
class IGame
{
public:

	/// <summary>
	/// �����������
	/// </summary>
	IGame() = default;

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~IGame() = default;
};
