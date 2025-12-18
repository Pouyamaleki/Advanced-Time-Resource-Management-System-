#include <iostream>
#include "AMS.h"

using namespace std;

int main()
{
    ResourceManager manager;
    int resourceCount;
    string name;
    cout << "how many resources do you want to have? " << endl;
    cin >> resourceCount;

    for (int i = 0; i < resourceCount; i++)
    {
        int id;
        cout << "Resource " << i + 1 << " ID: " << endl;
        cin >> id;
        cout << "Resource name: " << endl;
        cin >> name;
        Resource res(id, name);
        int intervalCount;
        cout << "Number of time intervals: " << endl;
        cin >> intervalCount;

        for (int j = 0; j < intervalCount; j++)
        {
            int h1, m1, h2, m2;
            cout << "Start time (hour minute): " << endl;
            cin >> h1 >> m1;
            cout << "End time (hour minute): " << endl;
            cin >> h2 >> m2;
            TimeInterval ti(Time(h1, m1), Time(h2, m2));
            
            if (!res.addInterval(ti))
            {
                cerr << "Time interference!!!!!" << endl;
            }
        }
        manager.addResource(res);
    }

    cout << endl;
    manager.printReport();

    return 0;
}
