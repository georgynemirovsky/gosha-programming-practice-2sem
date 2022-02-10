#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 1, b;
    cin >> b;
    while (b > a) {
        a*=2;
    }
    if (a == b) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
