

#include <iostream>
#include <iomanip>

using namespace std;
double A_Sopr(double ro, double v, double s, double CD)
{
    double L;
    L = 0.5 * ro * v * v * s * CD;
    return L;
}
int main()
{
    double L;
    setlocale(LC_ALL, "Russian");
    double s, v, ro, CD, L1;
    cout << "введите площадь крыла(м^2): " << endl;
    cin >> s;
    cout << "введите скорость полета(м/с): " << endl;
    cin >> v;
    cout << "введите плотность воздуха(кг/м^3): " << endl;
    cin >> ro;
    cout << "введите коэффициент сопротивления: " << endl;
    cin >> CD;
    L1 = A_Sopr(ro,v,s, CD);
    cout.precision(7);  // Устанавливаем точность
    cout << fixed << "Аэродинамическое сопротивление(Н): " << L1 << endl;

    
    return 0;
    
}

