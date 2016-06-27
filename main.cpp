#include "func.h"
#include "locale.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	//создание переменных
	unsigned	int day = 0, month = 0, year = 0, year_Minus = 0;
	char month_s[20];

	//ввод и проверка года на корректность
	while (true)
	{
		char * temp = new char;
		std::cout << " " << std::endl;
		std::cout << " введите год от 1583 до 9999 | ";
		std::cin.clear();
		std::cin >> temp;
		int a = atoi(temp);
		if (correct_year(a) == 0) {
			system("cls");
			std::cin.clear();
			year = a;
			break;
		}
		if (correct_year(a) != 0) {
			system("cls");
			std::cin.clear();
			std::cout << " Неправильный ввод. Повторите.\n";
		}
	}
	//проверка на високосность года
	system("cls");
	if (LeapYear(year) == 1)
	{
		std::cout << year << " год високосный, в феврале 29 дней " << std::endl;
	}

	else
	{
		std::cout << year << " год НЕ високосный, в феврале 28 дней " << std::endl;
	}

	//ввод месяца
	while (translate(month_s, year_Minus) == 25)
	{
		std::cout << " " << std::endl;
		std::cout << " Введите месяц английскими буквами или цифрами без 0 для 1-9 месяцев | ";
		std::cin >> month_s;
	}
	year_Minus = year;
	if (translate(month_s, year_Minus)==13 || translate(month_s, year_Minus) == 14)
	{
		year_Minus--;
	}

	

	//перевод месяца в численный эквивалент
	int month_cout = translate(month_s, year_Minus);
	if (month_cout == 13)
	{
		month_cout = 1;
	}
	if (month_cout == 14)
	{
		month_cout = 2;
	}

	// проверка дня месяца на корректность
	while (check(year, day, translate(month_s, year_Minus)) == 1)
	{
		std::cout << " " << std::endl;
		std::cout << " введите число месяца | ";
		while (!(std::cin >> day))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << " Неправильный ввод. Повторите.\n";
		}
	}
//	std::cin.clear();
	 month=translate(month_s, year_Minus) ;
	//подсчеты алгоритма вычисления дня недели
	int a = (14 - month) / 12;
	int	y = year_Minus - a;
	int m = month + 12 * a - 2;
	int  result = ((7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)));
	int result_j = ((6998 + (day + y + y / 4 + (31 * m) / 12)));
	system("cls");
	//вывод результата
	std::cout << " " << std::endl;
	std::cout << "                 ----------" << std::endl;
	if (day < 10) {
		if (month_cout < 10)std::cout << "\tВы ввели 0" << day << ".0" << month_cout << "." << year << std::endl;
		else
			std::cout << "\tВы ввели 0" << day << "." << month_cout << "." << year << std::endl;
	}
	else {
		if (month_cout < 10)std::cout << "\tВы ввели " << day << ".0" << month_cout << "." << year << std::endl;
		else
			std::cout << "\tВы ввели " << day << "." << month_cout << "." << year << std::endl;
	}

	std::cout << "                 ----------" << std::endl;
	std::cout << " " << std::endl;
	Result_out(result);
	std::cout << " - Григорианский календарь" << std::endl;
	std::cout << " " << std::endl;

	Result_out(result_j);

	std::cout << " - Юлианский календарь" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "День принадлежит знаку зодиака: ";
	ZnakZodiaka(day, month_cout);
	std::cout << " " << std::endl;
	std::cout << "По китайскому календарю " << year << " - год ";
	ChinaCalend(year);
	std::cout << " " << std::endl;
	//std::cout << " By Lysenko Anton " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	

	system("PAUSE");
	return 0;
}
