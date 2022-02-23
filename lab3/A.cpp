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

int main()
{
    int const n = 10;
    int massive[n] = {0};
    for (int i = 0; i  < n; i++){
        cin >> massive[i];
    }
    gnomSort(n, massive);
    for (int i = 0; i < n; i++){
        cout << massive[i] << " ";
    }
    return 0;
}
