#include <iostream>
#include <cmath>

using namespace std;

void gnomSort(int n, int (&massive1)[10])
{
    int i, j, t;
    i = 1;
    j = 2;
    while (i < n){
        if (massive1[i-1] < massive1[i]){
            i = j;
            j++;
        } else {
            t = massive1[i-1];
            massive1[i-1] = massive1[i];
            massive1[i] = t;
            i--;
            if (i == 0){
                i = j;
                j++;
            }
        }
    }
}

bool binpoisk(int data[], int val, unsigned l, unsigned r)
{
    int mid = 0;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (data[mid] < val){
            l = mid;
        } else {
            r = mid;
        }
    }
    if (val == data[r]){
        return true;
    } else {
        return false;
    }
}

int main()
{
    int const n = 10;
    int massive[n] = {0};
    for (int i = 0; i  < n; i++){
        cin >> massive[i];
    }
    gnomSort(n, massive);
    int val;
    cin >> val;
    if (binpoisk(massive, val, 0, n) == 1){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
