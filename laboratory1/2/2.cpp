#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

mt19937 generator(time(NULL));
uniform_int_distribution<int> distr(1, 4);
uniform_int_distribution<int> dis_locator(0, 19);

void generatepoint(int (&loc)[20][20]) {
    int x = dis_locator(generator);
    int y = dis_locator(generator);
    while (loc[x][y] != 0){
        x = dis_locator(generator);
        y = dis_locator(generator);
    }
    loc[x][y] = 1;
}

void moving(int n, int (&loc)[20][20], int x, int y, int &c) {
    int a = distr(generator);
    if (a == 1){
        if (y + 1 < n - 1){
            if (loc[x][y + 1] == 0){
                loc[x][y] = 0;
                loc[x][y + 1] = 3;
            } else {
                loc[x][y + 1] = 2;
                loc[x][y] = 2;
                c--;
                c--;
            }
        } else {
            loc[x][y] = 0;
            loc[x][y + 1] = 2;
            c--;
        }
    }
    if (a == 2){
        loc[x][y] = 0;
        if (x + 1 < n){
            if (loc[x + 1][y] == 0){
                loc[x][y] = 0;
                loc[x + 1][y] = 3;
            } else {
                loc[x + 1][y] = 2;
                loc[x][y] = 2;
                c--;
                c--;
            }
        } else {
            loc[x + 1][y] = 2;
            loc[x][y] = 0;
            c--;
        }
    }
    if (a == 3){
        loc[x][y] = 0;
        if (x - 1 > 0){
            if (loc[x - 1][y] == 0){
                loc[x][y] = 0;
                loc[x - 1][y] = 1;
            } else {
                loc[x - 1][y] = 2;
                loc[x][y] = 2;
                c--;
                c--;
            }
        } else {
            loc[x - 1][y] = 2;
            loc[x][y] = 0;
            c--;
        }
    }
    if (a == 4){
        loc[x][y] = 0;
        if (y - 1 > 0){
            if (loc[x][y - 1] == 0){
                loc[x][y] = 0;
                loc[x][y - 1] = 1;
            } else {
                loc[x][y - 1] = 2;
                loc[x][y] = 2;
                c--;
                c--;
            }
        } else {
            loc[x][y - 1] = 2;
            loc[x][y] = 0;
            c--;
        }
    }
 }

void pointconcl(int (&loc)[20][20], int x, int y, int &c){
    if (loc[x][y] = 1){
        if (loc[x][y - 1] == 1 or loc[x][y - 1] == 2){
            loc[x][y] = 2;
            c--;
            if (loc[x][y - 1] != 2){
                loc[x][y - 1] = 2;
                c--;
            }
        }
        if (loc[x][y + 1] == 1 or loc[x][y + 1] == 2){
            loc[x][y] = 2;
            c--;
            if (loc[x][y + 1] != 2){
                loc[x][y + 1] = 2;
                c--;
            }
        }
        if (loc[x - 1][y] == 1 or loc[x - 1][y] == 2){
            loc[x][y] = 2;
            c--;
            if (loc[x - 1][y] != 2){
                loc[x - 1][y] = 2;
                c--;
            }
        }
        if (loc[x + 1][y] == 1 or loc[x + 1][y] == 2){
            loc[x][y] = 2;
            c--;
            if (loc[x + 1][y] != 2){
                loc[x + 1][y] = 2;
                c--;
            }
        }
    }
 }

int main()
{
    ofstream file("data.txt");
    int const n = 20;
    int matr[n][n] = {0,0};
    for (int i = 1; i <= n * n; i++){
        int c = i, steps = 0;
        for (int nom = 1; nom <= 10000; nom++){
            for (int j = 0; j < i; j++){
                generatepoint(matr);
            }
            int c = i;
            while (c > 0){
                for (int j = 0; j < n; j++){
                    if (matr[j][19] == 1){
                        matr[j][19] = 2;
                        c--;
                    }
                    if (matr[19][j] == 1){
                        matr[19][j] = 2;
                        c--;
                    }
                    if (matr[0][j] == 1){
                        matr[0][j] = 2;
                        c--;
                    }
                    if (matr[j][0] == 1){
                        matr[j][0] = 2;
                        c--;
                    }
                }
                for (int j = 1; j < n - 1; j++){
                    for (int k = 1; k < n - 1; k++){
                        if (matr[j][k] == 1){
                            pointconcl(matr, j, k , c);
                        }
                    }
                }
                for (int j = 0; j < n; j++){
                    for (int k = 0; k < n; k++){
                        if (matr[j][k] == 1){
                            moving(n, matr, j, k, c);
                            steps++;
                        } else if (matr[j][k] == 3){
                            matr[j][k] = 1;
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    matr[j][k] = 0;
                }
            }
        }
        file << i << " " << steps / 10000 << endl;
    }
    file.close();
    return 0;
}
