#include <iostream>
#include <vector>

using namespace std;

int part(vector<int> &A, int lo, int hi) {
    int pivot = A[(hi + lo) / 2];
    int i = lo;
    int j = hi;
    while (true) {
        while (A[i] < pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++;
        j--;
    }
}

void quicksort(vector<int> &A, int lo, int hi)
{
    if (lo < hi) {
        int p = part(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
}

int main()
{
    int number = 0;
    int s = 0;
    vector<int> arr;
    while (cin >> number) {
        arr.push_back(number);
    }
    quicksort(arr, 0, arr.size() - 1);
    int *it = new int[arr.size()];

    for (int i = 0; i < arr.size(); i++) {
        it[i] = 0;
    }

    it[0] = 1;
    it[1] = 1;
    it[arr.size() - 1] = 1;
    it[arr.size() - 2] = 1;

    for (int i = 0; i < arr.size() - 2; i++) {
        if (it[i] == 0) {
            if (arr[i] - arr[i - 1] < arr[i + 1] - arr[i]) {
                it[i] = 1;
                s += arr[i] - arr[i - 1];
            } else {
                it[i + 1] = 1;
                it[i] = 1;
                s+= arr[i + 1] - arr[i];
            }
        }
    }
    if (arr.size() >= 4) {
        cout << arr[1] - arr[0] + s + arr[arr.size() - 1] - arr[arr.size() - 2] << endl;
    } else if (arr.size() == 2) {
        cout << arr[1] - arr[0] << endl;
    } else if (arr.size() == 3) {
        cout << arr[2] - arr[0] << endl;
    }
    return 0;
}
