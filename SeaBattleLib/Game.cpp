#include "pch.h"
#include "Game.h"

namespace SeaBattleLib
{
	Game::Game(std::shared_ptr<GameFieldController> fieldController1,
		std::shared_ptr<GameFieldController> fieldController2,
		std::shared_ptr<ShipController> shipController)
	{
		if (fieldController1 == nullptr ||
			fieldController2 == nullptr ||
			shipController == nullptr) throw "Error!!!";

		if (fieldController1->GetSizeField() != fieldController2->GetSizeField()) throw "Error!!!";

		_fieldController1 = fieldController1;
		_fieldController2 = fieldController2;
		_shipController = shipController;
	}

	void Game::Run()
	{
		system("cls");

		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << "Заполенение игрового поля 1-го игрока" << std::endl;
		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << "\n" << std::endl;
		CreateShipsOnField(_fieldController1, _shipController);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");

		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << "Заполенение игрового поля 2-го игрока" << std::endl;
		std::cout << "/////////////////////////////////////" << std::endl;
		std::cout << "\n" << std::endl;
		CreateShipsOnField(_fieldController2, _shipController);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");

		while (!_fieldController1->NoShipsOnField() && !_fieldController2->NoShipsOnField())
		{
			if (_player)
			{
				system("cls");
				std::cout << "Ход первого игрока!\n" << std::endl;
				PrintGame(_fieldController2);
				AttackShip(_fieldController2);
				std::this_thread::sleep_for(std::chrono::seconds(2));
			}
			else
			{
				system("cls");
				std::cout << "Ход второго игрока!\n" << std::endl;
				PrintGame(_fieldController1);
				AttackShip(_fieldController1);
				std::this_thread::sleep_for(std::chrono::seconds(2));
			}
		}

		if (_fieldController1->NoShipsOnField())
		{
			std::cout << "Выиграл второй игрок!!!" << std::endl;
		}

		if (_fieldController2->NoShipsOnField())
		{
			std::cout << "Выиграл первый игрок!!!" << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	void Game::Print(std::shared_ptr<GameFieldController> fieldController)
	{
		setlocale(LC_ALL, "Russian.utf8");

		size_t size = fieldController->GetSizeField();

		std::cout << "  ABCDEFGHIK" << std::endl;

		for (size_t y = 0; y < size; y++)
		{
			std::cout << y << "|";

			for (size_t x = 0; x < size; x++)
			{
				Point2D<uint16_t> point{ x, y };

				if (fieldController->GetFieldElement(point) == 0)
				{
					std::cout << '-';
				}
				else
				{
					std::cout << fieldController->GetFieldElement(point);
				}
			}

			std::cout << "|" << y << std::endl;
		}

		std::cout << "  ABCDEFGHIK" << std::endl;
	}

	void Game::PrintGame(std::shared_ptr<GameFieldController> fieldController)
	{
		setlocale(LC_ALL, "Russian.utf8");

		size_t size = fieldController->GetSizeField();

		std::cout << "  ABCDEFGHIK" << std::endl;

		for (size_t y = 0; y < size; y++)
		{
			std::cout << y << "|";

			for (size_t x = 0; x < size; x++)
			{
				Point2D<uint16_t> point{ x,y };

				if (fieldController->GetFieldElement(point) == 5)
				{
					std::cout << ' ';
				}
				else if (fieldController->GetFieldElement(point) == 6)
				{
					std::cout << '#';
				}
				else
				{
					std::cout << '*';
				}
			}

			std::cout << "|" << y << std::endl;
		}

		std::cout << "  ABCDEFGHIK" << std::endl;
	}

	void Game::CreateShipsOnField(std::shared_ptr<GameFieldController> fieldController,
		std::shared_ptr<ShipController> shipController)
	{
		setlocale(LC_ALL, "Russian.utf8");

		uint16_t numberOfShipDecks = 1; // Количество палуб у корабля
		Point2D<uint16_t> point;

		Print(fieldController);

		while (numberOfShipDecks <= 4)
		{
			for (size_t i = 1; i <= 5 - numberOfShipDecks; i++)
			{
				if (numberOfShipDecks == 1)
				{
					while (!(DataEntry::EnterCoordinates(point) &&
						fieldController->AddShipOnField(shipController->CreateShip(point))))
					{
						std::cout << "Ошибка ввода данных!!!" << std::endl;
					}
				}
				else
				{
					Direction direction;

					while (!(DataEntry::EnterCoordinates(point) &&
						DataEntry::EnteringDirection(direction) &&
						fieldController->AddShipOnField(shipController->CreateShip(point, numberOfShipDecks, direction))))
					{
						std::cout << "Ошибка ввода данных!!!" << std::endl;
					}
				}

				Print(fieldController);
			}

			numberOfShipDecks++;
		}
	}

	void Game::AttackShip(std::shared_ptr<GameFieldController> fieldController)
	{
		setlocale(LC_ALL, "Russian.utf8");

		Point2D<uint16_t> point;

		while (!(DataEntry::EnterCoordinates(point)))
		{
			std::cout << "Ошибка ввода данных!!!" << std::endl;
		}

		switch (fieldController->ShootAtShip(point))
		{
		case ResultOfShot::KILLED:
		{
			std::cout << "Убил!!!" << std::endl;
			fieldController->SetFieldElement(point, 6);
			OpenArea(fieldController);
			break;
		}
		case ResultOfShot::WOUNDED:
		{
			std::cout << "Ранил!!!" << std::endl;
			fieldController->SetFieldElement(point, 6);
			break;
		}
		case ResultOfShot::MISSED:
		{
			std::cout << "Промахнулся!!!" << std::endl;
			fieldController->SetFieldElement(point, 5);
			_player = !_player;
			break;
		}
		}
	}

	void Game::OpenArea(std::shared_ptr<GameFieldController> fieldController)
	{
		size_t sizeField = fieldController->GetSizeField();

		int16_t minX = fieldController->GetCoordinatesOfSunkenShip().beginning.x - 1;
		int16_t minY = fieldController->GetCoordinatesOfSunkenShip().beginning.y - 1;
		int16_t maxX = fieldController->GetCoordinatesOfSunkenShip().end.x + 1;
		int16_t maxY = fieldController->GetCoordinatesOfSunkenShip().end.y + 1;

		if (minX < 0) minX = 0;
		if (maxX == sizeField) maxX = sizeField - 1;
		if (minY < 0) minY = 0;
		if (maxY == sizeField) maxY = sizeField - 1;

		for (size_t x = minX; x <= maxX; x++)
		{
			for (size_t y = minY; y <= maxY; y++)
			{
				Point2D<uint16_t> point{ x,y };

				if (fieldController->GetFieldElement(point) == 0)
				{
					fieldController->SetFieldElement(point, 5);
				}
			}
		}
	}
}
