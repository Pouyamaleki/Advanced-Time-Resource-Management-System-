#include "AMS.h"

using namespace std;

Resource::Resource(int _id, string _name) : id(_id), name(_name)
{
}

int Resource::getId() const
{
    return id;
}
const string &Resource::getName() const
{
    return name;
}

bool Resource::hasConflict(const TimeInterval &ti) const
{
    for (const auto &x : intervals)
        if (x.overlaps(ti))
            return true;
    return false;
}

bool Resource::addInterval(const TimeInterval &ti)
{
    for (const auto &x : intervals)
    {
        if (x.overlaps(ti))
        {
            return false;
        }
    }
    intervals.push_back(ti);
    normalize();
    return true;
}

void bubbleSort(vector<TimeInterval> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Resource::normalize()
{
    if (intervals.empty())
    {
        return;
    }
    bubbleSort(intervals);
    vector<TimeInterval> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        TimeInterval out;
        if (merged.back().merge(intervals[i], out))
            merged.back() = out;
        else
            merged.push_back(intervals[i]);
    }
    intervals = merged;
}

void Resource::printSchedule() const
{
    cout << "Resource: " << id << " and name: " << name << endl;
    cout << "-------------------------" << endl;
    for (const auto &x : intervals)
    {
        cout << x.toString() << endl;
    }
    cout << endl;
}
