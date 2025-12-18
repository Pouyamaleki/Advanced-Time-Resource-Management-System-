#include "AMS.h"

using namespace std;

Time::Time(int h, int m) : hour(h), minute(m)
{
    normalize();
}

void Time::normalize()
{
    if (minute >= 60)
    {
        hour += minute / 60;
        minute %= 60;
    }
    else if (minute < 0)
    {
        int dec = (-minute + 59) / 60;
        hour -= dec;
        minute += dec * 60;
    }
    if (hour >= 24)
    {
        hour %= 24;
    }
    else if (hour < 0)
    {
        hour = (hour % 24 + 24) % 24;
    }
}

bool Time::operator<(const Time &o) const
{
    return (hour < o.hour) || (hour == o.hour && minute < o.minute);
}

bool Time::operator==(const Time &o) const
{
    return hour == o.hour && minute == o.minute;
}

int Time::operator-(const Time &o) const
{
    return hour * 60 + minute - (o.hour * 60 + o.minute);
}

string Time::toString() const
{
    string h = (hour < 10 ? "0" : "") + to_string(hour);
    string m = (minute < 10 ? "0" : "") + to_string(minute);
    return h + ":" + m;
}
