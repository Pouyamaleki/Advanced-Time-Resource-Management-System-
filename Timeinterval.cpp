#include <iostream>
#include <string>
#include "AMS.h"

using namespace std;

TimeInterval::TimeInterval(const Time &s, const Time &e) : start(s), end(e)
{
}

bool TimeInterval::overlaps(const TimeInterval &o) const
{
    bool beforeEnd = (end < o.start) || (end == o.start);
    bool afterstart = (o.end < start) || (o.end == start);
    return !(beforeEnd || afterstart);
}

bool TimeInterval::contiguous(const TimeInterval &o) const
{
    return end == o.start || start == o.end;
}

int TimeInterval::duration() const
{
    return end - start;
}

bool TimeInterval::merge(const TimeInterval &o, TimeInterval &out) const
{
    if (!overlaps(o) && !contiguous(o))
    {
        return false;
    }
    Time s = (o.start < start ? o.start : start);
    Time e = (o.end < end ? end : o.end);
    out = TimeInterval(s, e);
    return true;
}

TimeInterval TimeInterval::operator+(const TimeInterval &o) const
{
    TimeInterval r;
    merge(o, r);
    return r;
}

bool TimeInterval::operator<(const TimeInterval &o) const
{
    return start < o.start;
}

bool TimeInterval::operator==(const TimeInterval &o) const
{
    return start == o.start && end == o.end;
}

string TimeInterval::toString() const
{
    return "[" + start.toString() + " - " + end.toString() + "]";
}