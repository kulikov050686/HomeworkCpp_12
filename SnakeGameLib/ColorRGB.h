#pragma once

namespace SnakeGameLib
{
	/// <summary>
	/// �����
	/// </summary>
	/// <typeparam name="T"> ��� ������ ����� </typeparam>
	template <typename T>
	struct ColorRGB
	{
		/// <summary>
		/// �������
		/// </summary>
		T r;

		/// <summary>
		/// �����
		/// </summary>
		T g;

		/// <summary>
		/// �����
		/// </summary>
		T b;
	};
}