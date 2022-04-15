#include <iostream>

using namespace std;


struct Lesson{
    int x;
    int y;

    Lesson () {
        x = 0;
        y = 0;
    }

    Lesson (int start, int end) {
        x = start;
        y = end;
    }
};


int part(Lesson* A, int lo, int hi) {
    Lesson pivot = A[(hi + lo) / 2];
    int i = lo;
    int j = hi;
    while (true) {
        while (A[i].y < pivot.y) {
            i++;
        }
        while (A[j].y > pivot.y) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        Lesson t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++;
        j--;
    }
}


void quicksort(Lesson* A, int lo, int hi) {
    if (lo < hi) {
        int p = part(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
}


int main() {
    int n = 0;
    int x = 0;
    int y = 0;
    int nomber_of_lessons = 0;
    cin >> n;
    Lesson *A;
    A = new Lesson[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }
    quicksort(A, 0, n-1);
    Lesson current_lesson = A[0];


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (current_lesson.y <= A[j].x) {
                current_lesson = A[j];
                nomber_of_lessons++;
                break;
            }
        }
    }

    cout << nomber_of_lessons + 1 << endl;

    delete [] A;
    return 0;
}
