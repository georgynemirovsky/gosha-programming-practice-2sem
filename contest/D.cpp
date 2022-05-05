#include <iostream>

using namespace std;

struct Pawn {
    int color;
    int roads;
};


int num(char *a) {
    if (a[0] == 'a') {
        return 1;
    }
    if (a[0] == 'b') {
        return 2;
    }
    if (a[0] == 'c') {
        return 3;
    }
    if (a[0] == 'd') {
        return 4;
    }
    if (a[0] == 'e') {
        return 5;
    }
    if (a[0] == 'f') {
        return 6;
    }
    if (a[0] == 'g') {
        return 7;
    }
    if (a[0] == 'h') {
        return 8;
    }
}


int num1(char *a) {
    if (a[1] == '1') {
        return 1;
    }
    if (a[1] == '2') {
        return 2;
    }
    if (a[1] == '3') {
        return 3;
    }
    if (a[1] == '4') {
        return 4;
    }
    if (a[1] == '5') {
        return 5;
    }
    if (a[1] == '6') {
        return 6;
    }
    if (a[1] == '7') {
        return 7;
    }
    if (a[1] == '8') {
        return 8;
    }
}


int road_number(Pawn** a, int x, int y) {
    for (int i = y; i < 8; i++) {
        for (int j = 1; j < 7; j++) {
            if (a[j][i].color == 1) {
                a[j][i].roads = a[j - 1][i - 1].roads + a[j + 1][i - 1].roads;
            } else {
                a[j][i].roads = a[j][i - 1].roads;
            }
        }
        if (a[0][i].color == 1) {
            a[0][i].roads = a[1][i - 1].roads;
        } else {
            a[0][i].roads = a[0][i - 1].roads;
        }
        if (a[7][i].color == 1) {
            a[7][i].roads = a[7 - 1][i - 1].roads;
        } else {
            a[7][i].roads = a[7][i - 1].roads;
        }
    }
    int s = 0;
    for (int i = 0; i < 8; i++){
        s+=a[i][7].roads;
    }
    return s;
}


int main() {
    int n;
    int x = 0;
    int y = 0;
    cin >> n;
    char point[3];

    Pawn** a = new Pawn*[8];
    for (int i = 0; i < 8; i++) {
        a[i] = new Pawn[8];
    }


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j].color = 0;
            a[i][j].roads = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> point;
        a[num(point) - 1][num1(point) - 1].color = 1;
    }

    cin >> point;
    x = num(point);
    y = num1(point);
    a[x - 1][y - 1].color = 2;
    a[x - 1][y - 1].roads = 1;

    cout << road_number(a, x, y) << endl;
    return 0;
}
