﻿#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
using namespace std;
struct Time {
    unsigned days, hours, minutes, seconds;
    Time(unsigned _days = 0, unsigned _hours = 0, unsigned _minutes = 0, unsigned _seconds = 0) {
        days = _days;
        hours = _hours;
        minutes = _minutes;
        seconds = _seconds;
    }
};
void print(Time& time) {
    unsigned _case, time_spans[4] = { time.days, time.hours, time.minutes, time.seconds };
    string cases[4][3] = { { "дня", "день", "дней"},{"часа", "час", "часов"},{"минуты", "минута", "минут"},{"секунды", "секунда", "секунд"} };
    for (int i = 0; i < 4; ++i) {
        if (time_spans[i] < 4 && time_spans[i] > 1) _case = 0;
        else if (time_spans[i] == 1) _case = 1;
        else _case = 2;
        cout << time_spans[i] << " " << cases[i][_case] << " ";
    }
    cout << endl;
}
Time difference(Time& A, Time& B) {
    int timeA = ((A.days * 24 + A.hours) * 60 + A.minutes) * 60 + A.seconds;
    int timeB = ((B.days * 24 + B.hours) * 60 + B.minutes) * 60 + B.seconds;
    unsigned diff = abs(timeA - timeB);
    unsigned s = diff % 60;
    unsigned m = (diff % (60 * 60)) / 60;
    unsigned h = (diff % (60 * 60 * 24)) / (60 * 60);
    unsigned d = diff / (60 * 60 * 24);
    Time C(d, h, m, s);
    return C;
}
void main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введите первое время через пробел: дни, часы, минуты, секунды" << endl;
    unsigned d, h, m, s;
    cin >> d >> h >> m >> s;
    Time A(d, h, m, s);
    cout << "\nВведите второе время через пробел: дни, часы, минуты, секунды" << endl;
    cin >> d >> h >> m >> s;
    Time B(d, h, m, s);
    Time C = difference(A, B);
    cout << "\nПервое время: ";
    print(A);
    cout << "\nВторое время: ";
    print(B);
    cout << "\nРазница: ";
    print(C);
}