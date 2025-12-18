#include <iostream>
#include "AMS.h"

using namespace std;

int ResourceManager::totalResources = 0;

void ResourceManager::addResource(const Resource &r)
{
    resources.push_back(r);
    totalResources++;
}

Resource *ResourceManager::findById(int id)
{
    for (auto &r : resources)
    {
        if (r.getId() == id)
        {
            return &r;
        }
    }
    return nullptr;
}

void ResourceManager::printReport() const
{
    cout << "System Log" << endl;
    cout << "Total: " << totalResources << " resources" << endl
         << endl;
    for (const auto &r : resources)
    {
        r.printSchedule();
    }
}
