
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    vector<double> temperatures = { 25, -150, 85, 300, 90, -105, 40 };
    auto it = remove_if(temperatures.begin(), temperatures.end(), [](double t) {
        return t < -100.0 || t > 200.0;
        });
    temperatures.erase(it, temperatures.end());

   cout << "Очищенный вектор температур: ";
   for (size_t i = 0; i < temperatures.size(); i++) {
        cout << temperatures[i] << " ";
    }
    return 0;
}