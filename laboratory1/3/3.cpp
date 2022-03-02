#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

mt19937 generator(time(NULL));
uniform_int_distribution<int> distr(1, 2);
uniform_int_distribution<int> dis_locator(0, 19);

void generatepoint(int (&loc)[20]) {
    int x = dis_locator(generator);
    while (loc[x] != 0){
        x = dis_locator(generator);
    }
    loc[x] = 1;
}

void moving(int n, int (&loc)[20], int x, int &c) {
    int a = distr(generator);
    if (a == 1){
        loc[x] = 0;
        if (x + 1 < n){
            if (loc[x + 1] == 0){
                loc[x] = 0;
                loc[x + 1] = 3;
            } else {
                loc[x + 1] = 2;
                loc[x] = 2;
                c--;
                c--;
            }
        } else {
            loc[x + 1] = 2;
            loc[x] = 0;
            c--;
        }
    }
    if (a == 2){
        loc[x] = 0;
        if (x - 1 > 0){
            if (loc[x - 1] == 0){
                loc[x] = 0;
                loc[x - 1] = 1;
            } else {
                loc[x - 1] = 2;
                loc[x] = 2;
                c--;
                c--;
            }
        } else {
            loc[x - 1] = 2;
            loc[x] = 0;
            c--;
        }
    }
 }

void pointconcl(int (&loc)[20], int x, int &c){
    if (loc[x] = 1){
        if (loc[x - 1] == 1 or loc[x - 1] == 2){
            loc[x] = 2;
            c--;
            if (loc[x - 1] != 2){
                loc[x - 1] = 2;
                c--;
            }
        }
        if (loc[x + 1] == 1 or loc[x + 1] == 2){
            loc[x] = 2;
            c--;
            if (loc[x + 1] != 2){
                loc[x + 1] = 2;
                c--;
            }
        }
    }
 }

int main()
{
    ofstream file("one-dimensional.txt");
    int const n = 20;
    int matr[n] = {0};
    for (int i = 1; i <= n; i++){
        int c = i, steps = 0;
        for (int nom = 1; nom <= 10000; nom++){
            for (int j = 0; j < i; j++){
                generatepoint(matr);
            }
            int c = i;
            while (c > 0){
                if (matr[19] == 1){
                    matr[19] = 2;
                    c--;
                }
                if (matr[0] == 1){
                    matr[0] = 2;
                    c--;
                }
                for (int j = 1; j < n - 1; j++){
                    if (matr[j] == 1){
                        pointconcl(matr, j, c);
                    }
                }
                for (int j = 0; j < n; j++){
                    if (matr[j] == 1){
                        moving(n, matr, j, c);
                        steps++;
                    } else if (matr[j] == 3){
                        matr[j] = 1;
                    }
                }
            }
            for (int j = 0; j < n; j++){
                matr[j] = 0;
                }
        }
        file << i << " " << steps / 10000 << endl;
    }
    file.close();
    return 0;
}
