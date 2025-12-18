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
    cout << "===== SYSTEM REPORT =====\n";
    cout << "Total: " << totalResources << " resources\n\n";
    for (const auto &r : resources)
        r.printSchedule();
}
