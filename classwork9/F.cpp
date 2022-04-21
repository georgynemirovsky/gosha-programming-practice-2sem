#include <iostream>

using namespace std;


int** matrix_init(int n, int m) {
    int **matr;
    matr = new int * [n];
    for (int i = 0; i < n; i++){
        matr[i] = new int [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
    return matr;
}


int ind_of_minimal_element(int a, int* mass) {
    int m = mass[0];
    int ind = 0;
    for (int i = 0; i < a; i++) {
        if (mass[i] < m && mass[i] != 0) {
            m = mass[i];
            ind = i;
        }
        if (m == 0 && mass[i] != 0) {
            m = mass[i];
            ind = i;
        }
    }
    return ind;
}


int index_of_delet_line(int ** matrix, int ind, int n) {
    for (int i = 1; i < n; i++) {
        if (matrix[i][ind] == matrix[0][ind]) {
            return i;
        }
    }
}


int** developing(int** matrix, int ind, int &n, int m) {
    for (int i = 0; i < m; i++) {
        if (matrix[ind][i] == matrix[0][i]) {
            matrix[0][i] = 0;
        } else {
            if (matrix[ind][i] != 0) {
                matrix[0][i] = matrix[ind][i];
            }
        }
    }

    n--;

    int **tmp = new int * [n];
    for (int i = 0; i < n; i++) {
        tmp[i] = new int [m];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < ind) {
                tmp[i][j] = matrix[i][j];
            }
            if (i > ind) {
                tmp[i - 1][j] = matrix[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
            delete [] matrix[i];
        }
    delete [] matrix;
    return tmp;
}


int min_len(int n, int m, int** matr) {
    int x = 0;
    int y = 0;
    static int sum = 0;
    while (n != 1) {
        y = ind_of_minimal_element(m, matr[0]);
        x = index_of_delet_line(matr, y, n);
        sum += matr[x][y];
        matr = developing(matr, x, n, m);
    }
    return sum;
}


int main() {
    int N, M;
    cin >> M >> N;
    int **matrix = matrix_init(N, M);
    cout << min_len(N, M, matrix) * 98 << endl;
    return 0;
}
