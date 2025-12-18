#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Time
{
private:
    int hour, minute;

public:
    Time(int h = 0, int m = 0);
    void normalize();
    bool operator<(const Time &) const;
    bool operator==(const Time &) const;
    int operator-(const Time &) const;
    string toString() const;
};

class TimeInterval
{
private:
    Time start, end;

public:
    TimeInterval(const Time &s = Time(), const Time &e = Time());
    bool overlaps(const TimeInterval &) const;
    bool contiguous(const TimeInterval &) const;
    int duration() const;
    bool merge(const TimeInterval &, TimeInterval &) const;
    bool operator<(const TimeInterval &) const;
    bool operator==(const TimeInterval &) const;
    TimeInterval operator+(const TimeInterval &) const;
    string toString() const;
};

class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    Resource(int _id = 0, string _name = "");
    int getId() const;
    const string &getName() const;
    bool hasConflict(const TimeInterval &) const;
    bool addInterval(const TimeInterval &);
    void normalize();
    void printSchedule() const;
};

class ResourceManager
{
private:
    vector<Resource> resources;

public:
    static int totalResources;
    void addResource(const Resource &r);
    Resource *findById(int id);
    void printReport() const;
};

void bubbleSort(vector<TimeInterval> &arr);

#endif