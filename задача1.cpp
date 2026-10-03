
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double s, v, ro, CL,L;
    cout << "введите площадь крыла(м^2): " << endl;
    cin >> s;
    cout << "введите скорость полета(м/с): " << endl;
    cin >> v;
    cout << "введите плотность воздуха(кг/м^3): " << endl;
    cin >> ro;
    cout << "введите коэффициент подъемной силы: " << endl;
    cin >> CL;
    L = 0.5 * ro * s * CL*v*v;
    cout.precision(7);  // Устанавливаем точность
    cout << fixed << L <<" Н " << endl;
    //ut << "Подъемная сила: " << L << endl;
   

    return 0;
}

