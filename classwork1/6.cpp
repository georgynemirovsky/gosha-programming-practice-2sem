#include <iostream>
#include <cmath>

using namespace std;

int nod(int a, int b) {
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
    return b;
}

int nok(int a, int b) {
    int x1, x2, del;
    x1 = a;
    x2 = b;
    del = nod(a, b);
    return x1 * x2 / del;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "The largest common divisor = " << nod(a, b) << '\n' << "The smallest common multiple = " << nok(a, b) << endl;
}
