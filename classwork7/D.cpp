#include <iostream>
#include <string.h>

using namespace std;

int krit(int x0, int y0, int x1, int y1, int x2, int y2)
{
    return (y1 - y0)*(x2 - x0) - (y2 - y0)*(x1 - x0);
}

bool compare(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ((krit(x0, y0, x1, y1, x2, y2) * krit(x0, y0, x1, y1, x3, y3) <= 0))
    {
        return true;
    } else
    {
        return false;
    }
}
struct dot
{
    unsigned int x1, y1, x2, y2;
    bool operator>>(dot d)
    {
        if (compare(d.x1, d.y1, d.x2, d.y2, x1, y1, x2, y2))
        {
            if (compare(x1, y1, x2, y2, d.x1, d.y1, d.x2, d.y2))
            {
                return true;
            } else
            {
                return false;
            }
        } else
        {
            return false;
        }
    }
};

int main()
{
    int const n = 10;
    dot d1, d2;
    cin >> d1.x1 >> d1.y1 >> d1.x2 >> d1.y2 >> d2.x1 >> d2.y1 >> d2.x2 >> d2.y2;
    if (d1 >> d2)
    {
        cout << "NO" << endl;
    } else
    {
        cout << "YES" << endl;
    }
    return 0;
}
