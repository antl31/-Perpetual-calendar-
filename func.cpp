#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include "clocale"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//проверка года в пределах от 1583 до 9999
int correct_year(unsigned int _year)
{
	if (_year < 1583)
	{
		return 1;
	}
	if (_year > 9999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int LeapYear(int _year) // проверка на високосный год
{
	return	((_year % 4) == 0) &&// год делится на 4 без остатка и год делится на 100 остаток не равен 0
		(((_year % 100) != 0) || //  или год делится на 400 и остаток равен 0
		((_year % 400) == 0));// при високосном вовзращается знач = 0

}

int check(int _year, int _day, int _month) //проверка на правильность ввода числа (1= ошибка)
{
	if ((_month == 13 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) && (_day > 31 || _day < 1))
		return 1;
	if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && (_day > 30 || _day < 1))
		return 1;
	if (_month == 14 && (LeapYear(_year) == 1) && (_day>29 || _day < 1))
		return 1;
	if (_month == 14 && (LeapYear(_year) == 0) && (_day>28 || _day < 1))
		return 1;


	else
	{
		return 0;
	}
}



// ввод словами месяц
int translate(const char* _month_s, int _year)
{
	char str1[] = { "January" }, str2[] = { "February" }, str3[] = { "March" }, str4[] = { "April" }, str5[] = { "May" },
		str6[] = { "June" }, str7[] = { "July" }, str8[] = { "August" }, str9[] = { "September" }, str10[] = { "October" },
		str11[] = { "November" }, str12[] = { "December" };

	char str13[] = { "1" }, str14[] = { "2" }, str15[] = { "3" }, str16[] = { "4" }, str17[] = { "5" }, str18[] = { "6" },
		str19[] = { "7" }, str20[] = { "8" }, str21[] = { "9" }, str22[] = { "10" }, str23[] = { "11" }, str24[] = { "12" };

	if (_stricmp(_month_s, str1) == 0 || _stricmp(_month_s, str13) == 0) {
		return 13; _year--;
	}

	if (_stricmp(_month_s, str2) == 0 || _stricmp(_month_s, str14) == 0) {
		return 14; _year--;
	}

	if (_stricmp(_month_s, str3) == 0 || _stricmp(_month_s, str15) == 0)return 3;

	if (_stricmp(_month_s, str4) == 0 || _stricmp(_month_s, str16) == 0)return 4;

	if (_stricmp(_month_s, str5) == 0 || _stricmp(_month_s, str17) == 0)return 5;

	if (_stricmp(_month_s, str6) == 0 || _stricmp(_month_s, str18) == 0)return 6;

	if (_stricmp(_month_s, str7) == 0 || _stricmp(_month_s, str19) == 0)return 7;

	if (_stricmp(_month_s, str8) == 0 || _stricmp(_month_s, str20) == 0)return 8;

	if (_stricmp(_month_s, str9) == 0 || _stricmp(_month_s, str21) == 0)return 9;

	if (_stricmp(_month_s, str10) == 0 || _stricmp(_month_s, str22) == 0)return 10;

	if (_stricmp(_month_s, str11) == 0 || _stricmp(_month_s, str23) == 0)return 11;

	if (_stricmp(_month_s, str12) == 0 || _stricmp(_month_s, str24) == 0)return 12;

	else return 25;

}
//вывод
void Result_out(int _result)
{
	if (_result % 7 == 0)

		std::cout << "Воскресенье";

	if (_result%7 == 1)
		std::cout << "Понедельник";


	if (_result % 7 == 2)

		std::cout << "Вторник";

	if (_result % 7 == 3)

		std::cout << "Среда";


	if (_result % 7 == 4)

		std::cout << "Четверг";


	if (_result % 7 == 5)

		std::cout << "Пятница";

	if (_result % 7 == 6)
		std::cout << "Суббота";
}


//подсчет знака заодиака
void ZnakZodiaka(int _day, int _month)
{
	if ((_month == 3 && _day >= 21) || (_month == 4 && _day <= 20))
		std::cout << "Овен" << std::endl;
	if ((_month == 4 && _day >= 21) || (_month == 5 && _day <= 20))
		std::cout << "Телец" << std::endl;
	if ((_month == 5 && _day >= 21) || (_month == 6 && _day <= 21))
		std::cout << "Близнецы" << std::endl;
	if ((_month == 6 && _day >= 22) || (_month == 7 && _day <= 22))
		std::cout << "Рак" << std::endl;
	if ((_month == 7 && _day >= 23) || (_month == 8 && _day <= 23))
		std::cout << "Лев" << std::endl;
	if ((_month == 8 && _day >= 24) || (_month == 9 && _day <= 23))
		std::cout << "Дева" << std::endl;
	if ((_month == 9 && _day >= 24) || (_month == 10 && _day <= 22))
		std::cout << "Весы" << std::endl;
	if ((_month == 10 && _day >= 23) || (_month == 11 && _day <= 22))
		std::cout << "Скорпион" << std::endl;
	if ((_month == 11 && _day >= 23) || (_month == 12 && _day <= 21))
		std::cout << "Стрелец" << std::endl;
	if ((_month == 12 && _day >= 22) || (_month == 1 && _day <= 20))
		std::cout << "Козерог" << std::endl;
	if ((_month == 1 && _day >= 21) || (_month == 2 && _day <= 19))
		std::cout << "Водолей" << std::endl;
	if ((_month == 2 && _day >= 20) || (_month == 3 && _day <= 20))
		std::cout << "Рыбы" << std::endl;
}

//подсчет года по китайскому календарю
void ChinaCalend(int year)
{
	if (year % 12 == 4) std::cout << "Крысы" << std::endl;
	if (year % 12 == 5) std::cout << "Быка" << std::endl;
	if (year % 12 == 6) std::cout << "Тигра" << std::endl;
	if (year % 12 == 7) std::cout << "Кролика" << std::endl;
	if (year % 12 == 8) std::cout << "Дракона" << std::endl;
	if (year % 12 == 9) std::cout << "Змеи" << std::endl;
	if (year % 12 == 10)std::cout << "Лошади" << std::endl;
	if (year % 12 == 11) std::cout << "Овцы" << std::endl;
	if (year % 12 == 0) std::cout << "Обезьяны" << std::endl;
	if (year % 12 == 1) std::cout << "Петуха" << std::endl;
	if (year % 12 == 2) std::cout << "Собаки" << std::endl;
	if (year % 12 == 3) std::cout << "Свиньи" << std::endl;
}
