#include <iostream>

using namespace std;

struct Time{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t_1, t_2, t;
    cin >> t_1.hours >> t_1.minutes >> t_1.seconds >> t.hours >> t.minutes >> t.seconds;
    t_2.seconds = (t_1.seconds + t.seconds) % 60;
    t_2.minutes = (t_1.minutes + t.minutes + (t_1.seconds + t.seconds) / 60) % 60;
    t_2.hours   = (t_1.hours + t.hours + (t_1.minutes + t.minutes + (t_1.seconds + t.seconds) / 60) / 60) % 24;
    cout << t_2.hours << ':' << t_2.minutes << ':' << t_2.seconds << endl;
    return 0;
}
