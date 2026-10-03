

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct samolet {
    double m;
    double s;
    double T;
    double CL;
    double CD;
    double ay;
    double L;
    double t;
    double D;
    double v;

};

int main()
{
    setlocale(LC_ALL, "Russian");
    samolet Airplane[3];
    double h,g,ro, minn;
    int  min_ind;
    cout << "введите высоту(м): " << endl;
    cin >> h;
    if (h < 0)
    {
        cout << "некорректное значение!" << endl;
        cout << "введите высоту (>0): " << endl;
        cin >> h;
    }
    int i;
    g = 9.81;
    ro = 100;
    for (i = 0; i < 3; i++)
    {
        cout << "введите параметры " << i+1 << "-го самолета" << endl;
        cout << "введите площадь крыла(м^2): " << endl;
        cin >> Airplane[i].s;
        cout << "введите скорость полета(м/c): " << endl;
        cin >> Airplane[i].v;
        cout << "введите массу(кг): " << endl;
        cin >> Airplane[i].m;
        cout << "введите коэффициент сопротивления: " << endl;
        cin >> Airplane[i].CD;
        cout << "введите коэффициент подъемной силы: " << endl;
        cin >> Airplane[i].CL;
        cout << "введите тягу двигателя(н): " << endl;
        cin >> Airplane[i].T;

        Airplane[i].L = 0.5 * ro * Airplane[i].v * Airplane[i].v * Airplane[i].s * Airplane[i].CL;
        Airplane[i].D = 0.5 * ro * Airplane[i].v * Airplane[i].v * Airplane[i].s * Airplane[i].CD;
        Airplane[i].ay = (Airplane[i].L - Airplane[i].m * g) / Airplane[i].m;
        if (Airplane[i].ay<0) {
            cout << i + 1 << "-ый самолет не поднимется на заданную высоу" << endl;
            Airplane[i].t = -1;
        }
        if (Airplane[i].ay > 0) {
            Airplane[i].t = sqrt(2 * h / Airplane[i].ay);
        }
    }
    minn = 10000000000000; 
    min_ind = -1;

    for (i = 0; i < 3; i++)
    {
        if (Airplane[i].t < minn && Airplane[i].t != -1) {
            minn = Airplane[i].t;
            min_ind = i;
        }
    }

     
    cout << fixed << setprecision(3)<<"быстрее всех заданную высоту наберет самолет номеер " <<min_ind+1<<endl;
    return 0;
}

