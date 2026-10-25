
#include <iostream>
#include <vector>
#include <numeric> 
#include <cmath>   
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<double> y = { 0, 10, 25, 20, 35, 30, 0 };
    vector<double> y_new(y.size());
    adjacent_difference(y.begin(), y.end(), y_new.begin());
    double sum = 0;
    for (size_t i = 1; i < y_new.size(); ++i) {
        sum += abs(y_new[i]);
    }
    cout << "Суммарный пройденный путь: " << sum << " м" << endl;;

    return 0;
}