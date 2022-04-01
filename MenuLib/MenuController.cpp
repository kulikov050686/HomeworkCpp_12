#include "MenuController.h"
#include "pch.h"

MenuController::MenuController(std::shared_ptr<IMenu> menu, std::function<void(std::string)> funcPrint)
{    
    _menu = menu;

    if (_menu != nullptr)
    {
        _sizeMenu = _menu->GetSizeMenu();
        _funcPrint = std::move(funcPrint);
    }
    else
    {
        throw "Error: menu = NULL!";
    }   
}

int MenuController::SelectedMenuItem(const std::string text)
{
    int selection = 0;
    PrintMenu(selection, text);

    do
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 72:
                //Up
                if (selection > 0) selection--;
                break;
            case 80:
                //Down
                if (selection < _sizeMenu - 1) selection++;
                break;            
            }
        }       
        
        PrintMenu(selection, text);
    }
    while (_getch() != 13);

    system("cls");

    return selection;
}

void MenuController::PrintMenu(int selection, const std::string text)
{
    system("cls");

    _funcPrint(text);

    for (int i = 0; i < _sizeMenu; i++)
    {
        if (i == selection)
        {
            _funcPrint("->" + _menu->GetItemMenu(i));
        }
        else
        {
            _funcPrint(_menu->GetItemMenu(i));
        }
    }
}
