// задача2.15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
   vector<double> x = { 1, 2, 4.5, 6, 3.67, 1, 2, 4.5, 6, 3.67 };
    sort(x.begin(), x.end());
    auto it = unique(x.begin(), x.end());
    x.erase(it, x.end());
    cout << "Траектория без дубликатов: ";
    for (size_t i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    return 0;
}