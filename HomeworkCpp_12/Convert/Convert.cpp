#include "Convert.h"

bool Convert::Numeral(char chr)
{
	return (chr == '0') ||
		   (chr == '1') ||
		   (chr == '2') ||
		   (chr == '3') ||
		   (chr == '4') ||
		   (chr == '5') ||
		   (chr == '6') ||
		   (chr == '7') ||
		   (chr == '8') ||
		   (chr == '9');
}

std::string Convert::RemoveSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	return str;
}

std::string Convert::RemoveZeros(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			str.erase(i, 1);
			i--;
		}
		else
		{
			break;
		}
	}

	return str;
}

bool Convert::ToInt(std::string strNumber, int& number)
{
	int sign = 1;
	int temp = 0;

	strNumber = RemoveSpaces(strNumber);

	if (strNumber[0] == '-')
	{
		strNumber.erase(0, 1);
		sign = -1;
	}
	else
	{
		if (strNumber[0] == '+')
		{
			strNumber.erase(0, 1);
			sign = 1;
		}
	}

	strNumber = RemoveZeros(strNumber);

	bool key = true;
	int numeral = 0;

	for (int i = 0; (i < strNumber.length()) && key; i++)
	{
		key = key && Numeral(strNumber[i]);

		if (key)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * ((int)pow(10, strNumber.length() - 1 - i));
		}
	}

	if (key)
	{
		number = sign * temp;		
	}

	return key;
}

bool Convert::ToDouble(std::string strNumber, double& number)
{
	int point = 0;
	int sign = 1;
	std::string strIntegerPart;    // целая часть действительного числа
	std::string strFractionalPart; // дробная часть действительного числа
	bool bFractionalPart = false;

	strNumber = RemoveSpaces(strNumber);

	bool key = true;

	for (int i = 0; i < strNumber.length() && key; i++)
	{
		key = key && (Numeral(strNumber[i]) || strNumber[i] == '.');
	}

	if (!key)
	{
		return false;
	}

	if (strNumber[strNumber.length() - 1] == '.')
	{
		strNumber += '0';
	}

	for (int i = 0; i < strNumber.length(); i++)
	{
		if (i == 0)
		{
			if (strNumber[0] == '-')
			{
				strNumber.erase(0, 1);
				sign = -1;
			}
			else
			{
				if (strNumber[0] == '+')
				{
					strNumber.erase(0, 1);
					sign = 1;
				}
			}
		}

		if (strNumber[i] == '.')
		{
			point++;
			bFractionalPart = true;
			i++;
		}

		if (point >= 2)
		{
			return false;
		}

		if (bFractionalPart)
		{
			strFractionalPart += strNumber[i];
		}
		else
		{
			strIntegerPart += strNumber[i];
		}
	}

	strIntegerPart = RemoveZeros(strIntegerPart);

	if (strIntegerPart == "")
	{
		strIntegerPart += '0';
	}

	bool key1 = true;
	bool key2 = true;
	double temp = 0;
	int numeral = 0;

	for (int i = 0; i < strFractionalPart.length() && key1; i++)
	{
		key1 = key1 && Numeral(strFractionalPart[i]);

		if (key1)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * pow(10, -(i + 1));
		}
	}

	for (int i = 0; i < strIntegerPart.length() && key2; i++)
	{
		key2 = key2 && Numeral(strIntegerPart[i]);

		if (key2)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * pow(10, strNumber.length() - 1 - i);
		}
	}

	if (key1 && key2)
	{
		number = sign * temp;
	}

	return key1 && key2;
}

std::string Convert::ToString(int number)
{
	std::string outString;

	if (number != 0)
	{
		int sign = 1;

		if (number < 0)
		{
			number = -number;
			sign = -1;
		}

		int numberOfDigits = floor(log10(number)); // Разрядность числа

		int k = numberOfDigits;
		int n = 0;

		while (0 <= k)
		{
			n = (number / pow(10, k));
			outString += n | 0x30;
			number -= n * pow(10, k);
			k--;
		}

		if (sign == -1)
		{
			outString = "-" + outString;
		}
	}
	else
	{
		outString = "0";
	}

	return outString;
}

bool Convert::ToUint(std::string strNumber, unsigned int& number)
{	
	unsigned int temp = 0;

	strNumber = RemoveSpaces(strNumber);
	strNumber = RemoveZeros(strNumber);

	bool key = true;
	int numeral = 0;

	for (int i = 0; (i < strNumber.length()) && key; i++)
	{
		key = key && Numeral(strNumber[i]);

		if (key)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * ((unsigned int)pow(10, strNumber.length() - 1 - i));
		}
	}

	if (key)
	{
		number = temp;		
	}

	return key;
}
