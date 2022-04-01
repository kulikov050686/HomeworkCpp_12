#pragma once
#include <locale.h>
#include <memory>

namespace TetrisGameLib
{
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
}
