#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double m, L, D, T, a_x, a_y, g, s, v, ro, CL;
    cout << "введите площадь крыла: " << endl;
    cin >> s;
    cout << "введите скорость полета: " << endl;
    cin >> v;
    cout << "введите плотность воздуха: " << endl;
    cin >> ro;
    cout << "введите коэффициент подъемной силы: " << endl;
    cin >> CL;
    cout << "введите тягу двигателя: " << endl;
    cin >> T;
    cout << "введите сопрртивление: " << endl;
    cin >> D;
    cout << "введите массу: " << endl;
    cin >> m;
    L = 0.5 * ro * v * v * s * CL;
    g = 9.81;
    a_x = (T - D) /m;
    a_y = (L - m * g)/m;
    cout.precision(3);  // Устанавливаем точность
    cout << fixed << "Вертикальное ускорение: " << a_y << endl;
    cout << fixed << "Горизонтальное ускорение: " << a_x << endl;
    return 0;
}
