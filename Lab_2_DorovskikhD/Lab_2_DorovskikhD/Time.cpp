#include "Time.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// Лабораторне заняття 2, варіант 10, Доровских Д.О.
// Створити клас Time для роботи згодом у форматі «година:хвилина:секунда».
// Клас повинен містити в собі не менш чотирьох функцій ініціалізації : числами,
// рядком(наприклад, «23:59 : 59»), секундами й часом.Обов'язковими
// операціями є : обчислення різниці між двома моментами часу в секундах,
// додавання часу й заданого кількості секунд, вирахування із часу заданого
// кількості секунд, порівняння моментів часу, переведення у секунди,
// переведення у хвилини(з округленням до цілої хвилини).

bool Time::isValid(int h, int m, int s) const {
	return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}

bool Time::Init(int h, int m, int s)
{
    if (isValid(h, m, s)) {
        hours = h;
        minuts = m;
        seconds = s;
        return true;
    }
    cout << "Некоректні значення часу!\n";
    return false;
}

bool Time::Init(const std::string& timeStr)
{
    int h, m, s;
    char s1, s2;
    stringstream ss(timeStr);
    if (ss >> h >> s1 >> m >> s2 >> s && s1 == ':' && s2 == ':') {
        return Init(h, m, s);
    }
    cout << "Неправильний формат рядка (очікується HH:MM:SS)!\n";
    return false;
}

bool Time::Init(long totSec)
{
    long secInDay = 86400;
    if (totSec < 0) {
        totSec = (totSec % secInDay + secInDay) % secInDay;
    }
    else {
        totSec %= secInDay;
    }
    int h = totSec / 3600;
    int m = (totSec % 3600) / 60;
    int s = totSec % 60;
    return Init(h, m, s);
}

bool Time::Init(const Time& other)
{
    this->hours = other.hours;
    this->minuts = other.minuts;
    this->seconds = other.seconds;
    return true;
}

void Time::Read()
{
    string inp;
    do {
        cout << "Введіть час (HH:MM:SS): ";
        cin >> inp;
    } while (!Init(inp));
}

void Time::Display() const
{
    cout << toStr() << "\n";
}

std::string Time::toStr() const
{
    stringstream ss;
    ss << setfill('0') << setw(2) << hours
        << ":" << setfill('0') << setw(2) << minuts
        << ":" << setfill('0') << setw(2) << seconds;
    return ss.str();
}

long Time::diffSec(const Time& other) const
{
    return labs(this->toSec() - other.toSec());
}

void Time::addSec(long s)
{
    long total = toSec() + s;
    Init(total);
}

void Time::subtrSec(long s)
{
    long total = toSec() - s;
    Init(total);
}

int Time::compare(const Time& other) const
{
    long t1 = this->toSec();
    long t2 = other.toSec();
    if (t1 > t2) {
        return 1;
    }
    if (t1 < t2) {
        return -1;
    }
    return 0;
}

long Time::toSec() const
{
    return hours * 3600 + minuts * 60 + seconds;
}

long Time::toMin() const
{
    long totSec = toSec();
    return totSec / 60;
}

