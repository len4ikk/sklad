#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double Tmax, Tmin, dT,ay,m,g,D, minn,h,t;
    int n,i,ind_min;
    cout << "введите значение  тяги Tmax (Н) " << endl;
    cin >> Tmax;
    cout << "введите значение тяги Tmin(Н) " << endl;
    cin >> Tmin;
    cout << "введите значение dT(Н) " << endl;
    cin >> dT;
    cout << "введите значение высоты (м) " << endl;
    cin >> h;
 while (Tmax <= Tmin) {
     cout << "некорректные границы массива" << endl;
     cout << "введите значение Tmax (Н) " << endl;
     cin >> Tmax;
     cout << "введите значение Tmin (Н) " << endl;
     cin >> Tmin;
 }

 if (Tmax > Tmin) {
        n = floor((Tmax - Tmin) / dT)+1;
    }

 double* T = new double[n];
   
 for (i = 0; i < n; i++) {
     T[i] = Tmin + i * dT;
 }
 m = 500;
 g = 9.81;
 minn = 1000000;
 D = 50;
 ind_min = -1;
 for (i = 0; i < n; i++) {
     if (T[i] <= D) {
        //тяга меньще чем сопртивление, значит самолет не может взлететь...
         t = 10000000;
     }
     else {
         ay = ((T[i] - D) / m) * ((T[i] - D) / (m * g));
         if (ay <= 0) {
             t = 10000000;
         }
         if (ay > 0) {
             t = sqrt(2 * h / ay);
             if (t < minn) {
                 minn = t;
                 ind_min = i;
             }
         }

     }
 }
 if (ind_min == -1) {
     cout << "ни при какой тяге самолет не набирает высоту";
 }
 else {
     cout << "оптимальное значение тяги: " << T[ind_min] <<"(Н) " << " со временем набора высоты: " << minn << " (м)" << endl;
 }

 
 delete[] T;
 return 0;
}
