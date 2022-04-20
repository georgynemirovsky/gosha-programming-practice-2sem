#include <iostream>

using namespace std;

int** matrix_init(int n, int m) {
    int **matr_sm;
    matr_sm = new int * [n];
    for (int i = 0; i < n; i++){
        matr_sm[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr_sm[i][j];
        }
    }
    return matr_sm;
}


int** matrix_in_init(int **matr_sm, int n, int m) {
    int **matr_in;
    int edge = 0;
    matr_in = new int * [n];
    for (int i = 0; i < n; i++){
        matr_in[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr_in[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (matr_sm[i][j] != 0) {
                matr_in[i][edge] = matr_sm[i][j];
                matr_in[j][edge] = matr_sm[i][j];
                edge++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete [] matr_sm[i];
    }
    delete [] matr_sm;
    return matr_in;
}


void print(int n, int m, int **matr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
    return;
}


int main() {
    int top_number = 0;
    cin >> top_number;
    int edges = 0;
    int **matr_sm = matrix_init(top_number, top_number);

    for (int i = 0; i < top_number; i++) {
        for (int j = i; j < top_number; j++) {
            if (matr_sm[i][j] != 0) {
                edges++;
            }
        }
    }

    int **matr_in = matrix_in_init(matr_sm, top_number, edges);
    print(top_number, edges, matr_in);
    for (int i = 0; i < top_number; i++) {
        delete [] matr_in[i];
    }
    delete [] matr_in;
    return 0;
}
