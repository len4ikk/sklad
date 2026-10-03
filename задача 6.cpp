
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double g, CL,s;
    double L[9];
    int i;
    int v[9] = {50,60,70,80,90,80,70,80,90 };
    double ro[9] = { 5, 4, 3, 2, 2 ,1.5, 1, 0.8, 1.55};
    g = 9.81;
    CL = 0.5;
    s = 50;
    for (i = 0; i < 9; i++)
    {
        L[i]= 0.5 * ro[i] * v[i] * v[i] * s * CL;
    }

    cout << fixed << setprecision(2);  // Устанавливаем точность
    cout << "|" << setw(5) << "Шаг"
        << "|" << setw(14) << "Скорость,м\c"
        << "|" << setw(17) << "Плотность,кг\м^3"
        << "|" << setw(18) << "Подъёмная сила,н" << "|" << endl;

    // Данные
    for (int i = 0; i < 9; i++) {
        cout << "|" << setw(5) << i
            << "|" << setw(14) << v[i]
            << "|" << setw(17) << ro[i]
            << "|" << setw(18) << L[i] << "|" << endl;
    }
    return 0;

}

