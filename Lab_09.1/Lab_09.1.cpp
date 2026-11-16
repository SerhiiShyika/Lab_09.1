
#include <iostream>
#include <cmath>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = ";
    cin >> x_p;

    cout << "x_k = ";
    cin >> x_k;

    cout << "dx = ";
    cin >> dx;

    cout << "e = ";
    cin >> e;

    // Перевірка області допустимих значень
    if (dx <= 0 || e <= 0 || x_p > x_k ||
        !(x_k < -1 || x_p > 1))
    {
        cout << "Invalid input!" << endl;
        return 1;
    }


    cout << endl;
    cout << "Taylor series for Arcth(x)" << endl;

    cout << fixed << setprecision(8);

    cout << "+------------+------------------+------------------+--------+" << endl;
    cout << "|      x     |     Function     |      Series      | Terms  |" << endl;
    cout << "+------------+------------------+------------------+--------+" << endl;

    x = x_p;

    while (x <= x_k)
    {
        sum();

        cout << "| " << setw(10) << x
            << " | " << setw(16) << 0.5 * log((x + 1) / (x - 1))
            << " | " << setw(16) << s
            << " | " << setw(6) << n + 1
            << " |" << endl;

        x += dx;
    }

    cout << "+------------+------------------+------------------+--------+" << endl;

    return 0;
}
