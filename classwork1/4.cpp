#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
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
    cout << b << endl;
    return 0;
}
