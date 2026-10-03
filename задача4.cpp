

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double h, L, t, a_y, g, m;
    cout << "введите высоту(м): " << endl;
    cin >> h;
    if (h < 0)
    {
        cout << "некорректное значение!" << endl;
        cout << "введите высоту (>0): " << endl;
        cin >> h;
    }
    cout << "введите подъемнуб силу(н): " << endl;
    cin >> L;
    g = 9.81;
    m = 50;
    a_y = (L - m * g) / m;
    if (a_y < 0)
    {
        cout << "набор высоты  невозможен (a_y<0)" << endl;
    }
    if (a_y > 0)
    {
        t = sqrt(2 * h / a_y);
        cout.precision(3);  // Устанавливаем точность
        cout << fixed << "высота " << h <<" м " << " будет достигнута через время: " << t << " секунд" << endl;
        return 0;
    }
}

