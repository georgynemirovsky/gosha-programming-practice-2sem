#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, p = 3;
    bool flag = true;
    cin >> a;
    if (a % 2 == 0) {
        cout << "NO" << endl;
    } else {
        while (p * p <= a) {
            if (a % p == 0) {
                cout << "NO" << endl;
                flag = false;
                break;
            } else {
                p += 2;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }
    return 0;
}
