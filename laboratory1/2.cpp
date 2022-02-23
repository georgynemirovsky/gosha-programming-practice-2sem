#include <iostream>
#include <cmath>
#include <random>

using namespace std;

void generatepoint(int n, int (&argv)[10]) {
    int seed = 0;
    mt19937 generator(seed);
    uniform_int_distribution<int> dis_locator(0, n);
    int i = dis_locator(generator);
    int j = dis_locator(generator);
    for (int i = 0; i < n; i++){
        argv[i] = dis_locator(generator);
    }
}

void moving(int &argc, int (&argv)[10]) {
    int speed = 0, a;
    mt19937 generator(speed);
    uniform_int_distribution<int> distr(1, 4);
    a = distr(generator);
    if (a == 1){
        argv[0]++;
    }
    if (a == 2){
        argv[1]++;
    }
    if (a == 3){
        argv[0]--;
    }
    if (a == 4){
        argv[1]--;
    }
 }

int main()
{
    int const n = 10;
    int matr[n][n] = {0};
    int dot[n] = {0};
    generatepoint(n, dot);
    for (int i = 0; i < n; i++){
        cout << dot[i] << " ";
    }
    return 0;
}
