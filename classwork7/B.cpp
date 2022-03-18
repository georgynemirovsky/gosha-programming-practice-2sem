#include <iostream>
#include <string.h>

using namespace std;

struct person
{
    char name[20];
    unsigned int grade = 0;
};

int part(person* A, int lo, int hi, bool flag) {
    if (flag)
    {
        int pivot = A[(hi + lo) / 2].grade;
        int i = lo;
        int j = hi;
        while (true) {
            while (A[i].grade < pivot) {
                i++;
            }
            while (A[j].grade > pivot) {
                j--;
            }
            if (i >= j) {
                return j;
            }
            person t = A[i];
            A[i] = A[j];
            A[j] = t;
            i++;
            j--;
        }
    } else
    {
        char* pivot = A[(hi + lo) / 2].name;
        int i = lo;
        int j = hi;
        while (true) {
            while (strcmp(A[i].name, pivot) < 0) {
                i++;
            }
            while (strcmp(A[j].name, pivot) > 0) {
                j--;
            }
            if (i >= j) {
                return j;
            }
            person t = A[i];
            A[i] = A[j];
            A[j] = t;
            i++;
            j--;
        }
    }
}

void quicksort(person* A, int lo, int hi, bool flag)
{
    if (lo < hi) {
        int p = part(A, lo, hi, flag);
        quicksort(A, lo, p, flag);
        quicksort(A, p + 1, hi, flag);
    }
}

int main()
{
    int const n = 10;
    person *team = new person[10];
    for (int i = 0; i < n; i++)
    {
        cin >> team[i].name >> team[i].grade;

    }
    int board = 0;
    cin >> board;
    quicksort(team, 0, n - 1, true);
    for (int i = 0; i < n; i++)
    {
        if (team[i].grade >= board)
        {
            if (team[i].grade != team[i - 1].grade)
            {
                int k = 0;
                for (int j = i; j < n; j++)
                {
                     if (team[j].grade == team[i].grade)
                     {
                         k++;
                     }
                }
                if (k > 1)
                {
                    quicksort(team, i, i + k - 1, false);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (team[i].grade >= board)
        {
            cout << team[i].name << " ";
        }
    }
    delete [] team;
    return 0;
}
