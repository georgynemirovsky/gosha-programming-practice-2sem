#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    if (b * b - 4 * a * c > 0) {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double d;
        if (x1 > x2) {
            d = x1;
            x1 = x2;
            x2 = d;
        } else {
        }
        cout << x1 << ' ' << x2 << endl;
    } else if (b * b - 4 * a * c == 0) {
            cout << -b / (2 * a) << endl;
    } else {
            cout << endl;
    }
    return 0;
}
