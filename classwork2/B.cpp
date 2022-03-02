#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 0, b = -1;
    while (b != 0) {
        if (b % 2 == 0) {
            a++;
        } else {
            a = a;
        }
        cin >> b;
    }
    cout << a << endl;
    return 0;
}
