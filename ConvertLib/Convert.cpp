#include "pch.h"
#include "Convert.h"

bool Convert::ToUshort(std::string strNumber, unsigned short& number)
{
	unsigned long temp = 0;

	if (ToUlong(strNumber, temp) && temp <= 65535)
	{
		number = temp;
		return true;
	}

	return false;
}

bool Convert::ToInt(std::string strNumber, int& number)
{
	try
	{
		number = std::stoi(strNumber);		
	}
	catch (const std::invalid_argument& ex)
	{		
		return false;
	}

	return true;
}

bool Convert::ToUint(std::string strNumber, unsigned int& number)
{
	unsigned long temp = 0;

	if (ToUlong(strNumber, temp))
	{
		if (sizeof(unsigned int) == 4 && temp <= 4294967295)
		{
			number = temp;
			return true;
		}

		if (sizeof(unsigned int) == 2 && temp <= 65535)
		{
			number = temp;
			return true;
		}
	}

	return false;
}

bool Convert::ToDouble(std::string strNumber, double& number)
{
	try
	{
		number = std::stod(strNumber);
	}
	catch (const std::invalid_argument& ex)
	{
		return false;
	}

	return true;
}

bool Convert::ToUlong(std::string strNumber, unsigned long& number)
{	
	try
	{
		number = std::stoul(strNumber);
	}
	catch (const std::invalid_argument& ex)
	{
		return false;
	}

	return true;
}

bool Convert::ToLong(std::string strNumber, long& number)
{
	try
	{
		number = std::stol(strNumber);
	}
	catch (const std::invalid_argument& ex)
	{
		return false;
	}

	return true;
}

bool Convert::ToUlonglong(std::string strNumber, size_t& number)
{
	try
	{
		number = std::stoull(strNumber);
	}
	catch (const std::invalid_argument& ex)
	{
		return false;
	}

	return true;
}

std::string Convert::ToString(unsigned char number)
{
	return std::to_string(number);
}

std::string Convert::ToString(int number)
{
	return std::to_string(number);
}

std::string Convert::ToString(double number)
{
	return std::to_string(number);
}

std::string Convert::ToString(unsigned long number)
{
	return std::to_string(number);
}

std::string Convert::ToString(long number)
{
	return std::to_string(number);
}

std::string Convert::ToString(unsigned long long number)
{
	return std::to_string(number);
}
