#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct AirCraft {
    double m;
    double s;
    double CL;
    double ay;
    double L;
    double t;
    double v;

};

int main()
{
    setlocale(LC_ALL, "Russian");
    AirCraft Airplane[3];
    double h, g, ro;
    cout << "введите высоту(м): " << endl;
    cin >> h;
    while (h < 0) {
        cout << "Некорректное значение! Введите высоту (>0): ";
        cin >> h;
    }
    int i;
    g = 9.81;
    ro = 0.5;
    for (i = 0; i < 3; i++)
    {
        cout << "введите параметры " << i + 1 << "-го самолета" << endl;
        cout << "введите площадь крыла(м^2): " << endl;
        cin >> Airplane[i].s;
        cout << "введите скорость полета(м\с): " << endl;
        cin >> Airplane[i].v;
        cout << "введите массу(кг): " << endl;
        cin >> Airplane[i].m;
        cout << "введите коэффициент подъемной силы: " << endl;
        cin >> Airplane[i].CL;
        

        Airplane[i].L = 0.5 * ro * Airplane[i].v * Airplane[i].v * Airplane[i].s * Airplane[i].CL;
        Airplane[i].ay = (Airplane[i].L - Airplane[i].m * g) / Airplane[i].m;
        if (Airplane[i].ay < 0) {
            cout << i + 1 << "-ый самолет не поднимется на заданную высоу" << endl;
            Airplane[i].t = -1;
        }
        if (Airplane[i].ay > 0) {
            Airplane[i].t = sqrt(2 * h / Airplane[i].ay);
        }
    }
   
    cout << "|  №   | Скорость,м\c |   Масса,кг   | Подъёмная сила,н   | Ускорение,м\c^2   |  Время, с    |\n";
    

    for (int i = 0; i < 3; i++)
    {
        cout << "|" << setw(5) << i + 1
            << " |" << setw(13) << Airplane[i].v
            << " |" << setw(13) << Airplane[i].m
            << " |" << setw(19) << Airplane[i].L
            << " |" << setw(18) << Airplane[i].ay
            << " |";

        if (Airplane[i].t < 0)
            cout << setw(14) << "не взлетит";
        else
            cout << setw(14) << Airplane[i].t;


    }

    

    return 0;
}

