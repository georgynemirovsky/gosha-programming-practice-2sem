#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int nomber_of_coins = 0;
    int nominal[4] = {98, 49, 7, 1};
    cin >> sum;
    for (int i = 0; i < 4; i++){
        nomber_of_coins += (sum / nominal[i]);
        sum -= (sum / nominal[i]) * nominal[i];
    }
    cout << nomber_of_coins << endl;
    return 0;
}
