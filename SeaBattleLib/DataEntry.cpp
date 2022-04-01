#include "pch.h"
#include "DataEntry.h"

namespace SeaBattleLib
{
	bool DataEntry::EnteringDirection(Direction& direction)
	{
		setlocale(LC_ALL, "Russian.utf8");

		std::string strChoice = "";
		uint16_t choice = 0;

		std::cout << "Введите направление корабля (1-вверх, 2-вниз, 3-налево, 4-направо): ";
		std::getline(std::cin, strChoice);

		if (Convert::ToUshort(strChoice, choice) && (choice == 1 || choice == 2 || choice == 3 || choice == 4))
		{
			if (choice == 1) direction = Direction::UP;
			if (choice == 2) direction = Direction::DOWN;
			if (choice == 3) direction = Direction::LEFT;
			if (choice == 4) direction = Direction::RIGHT;

			return true;
		}

		return false;
	}

	bool DataEntry::EnterCoordinates(Point2D<uint16_t>& point)
	{
		setlocale(LC_ALL, "Russian.utf8");

		std::string strCoordinates = "";

		std::cout << "Введите координату (A,B,C,...,K и 0,1,3,...,9): ";
		std::getline(std::cin, strCoordinates);

		strCoordinates = RemoveSpaces(strCoordinates);

		if (strCoordinates.length() == 2 &&
			CheckingLetterSymbol(strCoordinates[0]) &&
			CheckingNumericCharacter(strCoordinates[1]))
		{
			point.x = CharacterConverter(strCoordinates[0]);
			point.y = CharacterConverter(strCoordinates[1]);

			return true;
		}

		return false;
	}

	bool DataEntry::CheckingLetterSymbol(char symbol)
	{
		return symbol == 'A' ||
			symbol == 'B' ||
			symbol == 'C' ||
			symbol == 'D' ||
			symbol == 'E' ||
			symbol == 'F' ||
			symbol == 'G' ||
			symbol == 'H' ||
			symbol == 'I' ||
			symbol == 'K';
	}

	bool DataEntry::CheckingNumericCharacter(char symbol)
	{
		return symbol == '0' ||
			symbol == '1' ||
			symbol == '2' ||
			symbol == '3' ||
			symbol == '4' ||
			symbol == '5' ||
			symbol == '6' ||
			symbol == '7' ||
			symbol == '8' ||
			symbol == '9';
	}

	uint16_t DataEntry::CharacterConverter(char symbol)
	{
		switch (symbol)
		{
		case 'A': return 0;
		case 'B': return 1;
		case 'C': return 2;
		case 'D': return 3;
		case 'E': return 4;
		case 'F': return 5;
		case 'G': return 6;
		case 'H': return 7;
		case 'I': return 8;
		case 'K': return 9;
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		}

		throw "Error!!!";
	}

	std::string DataEntry::RemoveSpaces(std::string str)
	{
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

		return str;
	}
}
