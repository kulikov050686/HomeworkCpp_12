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
	/// ������
	/// </summary>
	/// <param name="value"></param>
	virtual void Timer(int value) = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	virtual void Reshape(int width, int height) = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="key"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	virtual void Keyboard(unsigned char key, int x, int y) = 0;

	/// <summary>
	/// 
	/// </summary>
	virtual void Idel() = 0;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~IGame() = default;
};
