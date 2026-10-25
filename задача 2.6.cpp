
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
    vector<double> heights = { 0.0, 1.5, 5.2, 9.9, 10.0, 12.3, 25.7, 8.4, 30.1 };

    cout << fixed << setprecision(2);

    cout << "исходный вектор: ";
    for (i = 0; i < (int)heights.size(); i++) 
    {
        cout << heights[i] << ", ";
        
    }
    cout << endl;

    // удаляем всё < 10
    auto new_end = remove_if(heights.begin(), heights.end(),
        [](double h) { return h < 10.0; });
    heights.erase(new_end, heights.end());

    cout << "удаляем всё h< 10" << endl;
    if (heights.empty()) {
        cout << "тепперь вектор пуст" << endl;;
    }
    else {
        cout << "новый вектор: ";
        for (i = 0; i < (int)heights.size(); i++)
        {
            cout << heights[i] << ", ";
            
        }
        cout << endl;
    }
	return 0;
}