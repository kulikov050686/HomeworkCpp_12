#include "pch.h"
#include "Task9.h"

Task9::Task9(std::shared_ptr<SeaBattle> seaBattle)
{
	if (seaBattle == nullptr) throw "Error!!!";
	
	_seaBattle = seaBattle;
}

void Task9::Run()
{
	_seaBattle->Run();
}
