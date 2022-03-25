#include <iostream>
#include <string.h>

using namespace std;

struct time
{
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
    time operator+(time r)
    {
        r.seconds += seconds;
        r.minutes += minutes;
        r.hours += hours;
        int s = r.seconds;
        r.seconds = r.seconds % 60;
        int m = r.minutes + s / 60;
        r.minutes += s / 60;
        r.minutes = r.minutes % 60;
        r.hours = (r.hours + m / 60) % 24;
        return r;
    }
};

int main()
{
    int const n = 10;
    time time_start;
    time time_end;
    cin >> time_start.hours >> time_start.minutes >> time_start.seconds;
    cin >> time_end.hours >> time_end.minutes >> time_end .seconds;
    time_start = time_end + time_start;
    cout << time_start.hours << ":" << time_start.minutes << ":" << time_start.seconds;
    return 0;
}
