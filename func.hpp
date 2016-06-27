#pragma once
#ifndef _FUNC_H_
#define _FUNC_H_


int LeapYear(int _year);

int check(int _year, int _day, int _month);

int translate(const char* _month_s, int _year);

int correct_year(unsigned int _year);

void Result_out(int _result);

void ZnakZodiaka(int _day, int _month);

void ChinaCalend(int year);

#endif //  _FUNC_H_
