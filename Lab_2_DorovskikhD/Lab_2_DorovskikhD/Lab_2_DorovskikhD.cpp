#include <iostream>
#include "Time.h"
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Time tim1, tim2;
    cout << "Введення:\n";
    cout << "Введення tim1:\n";
    tim1.Read();
    cout << "Введення tim2:\n";
    tim2.Read();
    cout << "\nОперації:\n";
    cout << "Час 1 (tim1) у рядок: " << tim1.toStr() << "\n";
    cout << "Час 2 (tim2) у рядок: " << tim2.toStr() << "\n";
    cout << "Різниця (tim1 - tim2) у секундах: " << tim1.diffSec(tim2) << " с\n";
    int cmp = tim1.compare(tim2);
    cout << "Порівняння tim1 і tim2: ";
    if (cmp > 0) cout << "tim1 більше за tim2\n";
    else if (cmp < 0) cout << "t1 менше за t2\n";
    else cout << "Час однаковий\n";
    cout << "tim1 у секундах: " << tim1.toSec() << " с\n";
    cout << "tim1 у хвилинах (з округленням): " << tim1.toMin() << " хв\n";
    long addS;
    cout << "Введіть час (у секундах) для додавання до tim1: ";
    cin >> addS;
    tim1.addSec(addS);
    cout << "Після додавання " << addS << " секунд: " << tim1.toStr() << "\n";
    long subS;
    cout << "Введіть час (у секундах) для віднімання до tim1: ";
    cin >> subS;
    tim1.subtrSec(subS);
    cout << "Після віднімання " << subS << " секунд: " << tim1.toStr() << "\n";
    cout << "\nІніціалізація:\n";
    tim1.Init(12, 30, 45);
    cout << "1. Числами (12, 30, 45): "; tim1.Display();
    tim1.Init("23:59:59");
    cout << "2. Рядком (\"23:59:59\"): "; tim1.Display();
    tim1.Init(3665L);
    cout << "3. Секундами (3665): "; tim1.Display();
    tim2.Init(tim1);
    cout << "4. Часом (tim2 як копія tim1): "; tim2.Display();
    return 0;
}