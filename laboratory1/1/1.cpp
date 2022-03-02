#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

int const n = 1000;
mt19937 generator(time(NULL));
uniform_int_distribution<int> distr(1, 4);
uniform_int_distribution<int> dis_locator(1, n);

void generatepoint(int n, int (&loc)[2]) {
    loc[0] = dis_locator(generator);
    loc[1] = dis_locator(generator);
}

void moving(int (&loc)[2]) {
    int a = distr(generator);
    if (a == 1){
        loc[0]++;
    }
    if (a == 2){
        loc[1]++;
    }
    if (a == 3){
        loc[0]--;
    }
    if (a == 4){
        loc[1]--;
    }
 }

int main()
{
    ofstream file("n-time.txt");
    for (int i = 1; i <= n; i++){
        int dot[2] = {i / 2, i / 2};
        long double col = 0;
        for (int j = 1; j <= 100; j++){
            int dot[2] = {i / 2, i / 2};
            while (dot[0] != 1 and dot[0] != i and dot[1] != 0 and dot[1] != i){
                moving(dot);
                col ++;
            }
        }
        file << i << " " << col / 100 << endl;
    }
    file.close();
    return 0;
}
