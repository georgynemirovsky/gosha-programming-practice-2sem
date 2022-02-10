#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b = 2;
    cin >> a;
    while (a > 1 and b <= a){
        if (a % b == 0){
            while (a % b == 0){
                a = a / b;
            }
            cout << b << " ";
        }
        b++;
    }
    return 0;
}
