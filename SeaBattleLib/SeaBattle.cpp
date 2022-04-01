#include "pch.h"
#include "SeaBattle.h"

void SeaBattle::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	StartScreenSaver();

	auto field_1 = std::make_shared<GameField<uint16_t>>(10);
	auto field_2 = std::make_shared<GameField<uint16_t>>(10);

	auto shipController = std::make_shared<ShipController>();

	auto fieldController1 = std::make_shared<GameFieldController>(field_1);
	auto fieldController2 = std::make_shared<GameFieldController>(field_2);

	auto game = std::make_shared<Game>(fieldController1, fieldController2, shipController);
	game->Run();	
}

void SeaBattle::StartScreenSaver()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::vector<std::string> text = { {"/////////////////"},
									  {"// Морской бой //"},
									  {"/////////////////"} };

	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");

	std::cout << text[1] << std::endl;
	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");

	std::cout << text[0] << std::endl;
	std::cout << text[1] << std::endl;
	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

