#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b = 1, sum = 0, mac;
    cin >> a;
    mac = a;
    while (a != 0) {
        if (mac == a){
            sum++;
        } else {
            if (a > mac){
                sum = 1;
                mac = a;
            }
        }
        cin >> a;
    }
    cout << sum << endl;
    return 0;
}
