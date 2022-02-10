#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 0, b = -1;
    cin >> a;
    while (b != 0) {
        if (b % 2 == 0) {
            if (b > a) {
                a = b;
            } else {
                a = a;
            }
        } else {
            a = a;
        }
        cin >> b;
    }
    cout << a << endl;
    return 0;
}
