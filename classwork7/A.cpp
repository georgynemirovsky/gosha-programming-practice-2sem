#include <iostream>

using namespace std;

struct person
{
    char name[20];
    unsigned int grade = 0;
};
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
    for (int i = 0; i < n; i++)
    {
        if (team[i].grade > board)
        {
            cout << team[i].name << " ";
        }
    }
    delete [] team;
    return 0;
}
