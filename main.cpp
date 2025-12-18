#include <iostream>
#include "AMS.h"

using namespace std;

int main()
{
    ResourceManager manager;
    int resourceCount;
    cout << "how many resources do you want to have? " << endl;
    cin >> resourceCount;
    
    for (int i = 0; i < resourceCount; i++)
    {
        string name;
        int id;
        cout << "Resource" << i + 1 << " ID: " << endl;
        cin >> id;
        cout << "Resource name: " << endl;
        cin >> name;
        Resource res(id, name);
        int intervalCount;
        cout << "How many Time Interval do you want? " << endl;
        cin >> intervalCount;

        for (int j = 0; j < intervalCount; j++)
        {
            int h1, m1, h2, m2;
            cout << "Start of the time: (Hour/Minute)" << endl;
            cin >> h1 >> m1;
            cout << "End of the time (Hour/minute): " << endl;
            cin >> h2 >> m2;
            cout << "----------------------" << endl;
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
