#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, x1, x2;
    cin >> a >> b;
    x1 = a;
    x2 = b;
    if (a < b) {
        int t;
        t = a;
        a = b;
        b = t;
    }
    while (a - (a - a%b) > 0){
        int t;
        t = a%b;
        a = b;
        b = t;
    }
    cout << x1 * x2 / b << endl;
    return 0;
}
