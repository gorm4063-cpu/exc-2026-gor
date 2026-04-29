#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Database1
{
public:
    int id;
    int balance;
    int lastUpdate;
    string name;
    Database1(string name = "", int id = 0, int balance = 0, int lastUpdate = 0)
    {
        this->id = id;
        this->balance = balance;
        this->name = name;
        this->lastUpdate = lastUpdate;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Update: " << lastUpdate << ":00 o'clock" << endl;
    }
    int getId()
    {
        return id;
    }
    int getLastUpdate()
    {
        return lastUpdate;
    }
};

int main()
{
    int LastUpdateTimefordb1 = 5;
    int LastUpdateTimefordb2 = 3;
    vector<Database1> db1 = {
        Database1("Alice", 1, 1000, 20240101),
        Database1("Bob", 2, 1500, 20240201),
        Database1("Charlie", 3, 2000, 20240301),
        Database1("David", 4, 2500, 20240401),
        Database1("Eve", 5, 3000, 20240501),
        Database1("Frank", 6, 3500, 20240601),
        Database1("Grace", 7, 4000, 20240701),
        Database1("Heidi", 8, 4500, 20240801),
        Database1("Ivan", 9, 5000, 20240901),
        Database1("Judy", 10, 5500, 20241001),
    };
    vector<Database1> db2 = {
        Database1("Alice", 1, 1100, 20240115),
        Database1("Bob", 2, 1400, 20240215),
        Database1("Charlie", 3, 2100, 20240315),
        Database1("David", 4, 2400, 20240415),
        Database1("Eve", 5, 3100, 20240515),
        Database1("Frank", 6, 3400, 20240615),
        Database1("Grace", 7, 4100, 20240715),
    };

    vector<Database1> lastUpdates1;
    vector<Database1> lastUpdates2;
    for (auto &record : db1)
    {
        if (record.getLastUpdate() == LastUpdateTimefordb1 || record.getLastUpdate() >= LastUpdateTimefordb1 - 1)
            ;
        lastUpdates1.push_back(record);
    }
    for (auto &record : db2)
    {
        if (record.getLastUpdate() == LastUpdateTimefordb2 || record.getLastUpdate() >= LastUpdateTimefordb2 - 1)
            ;
        lastUpdates2.push_back(record);
    }

    if (!lastUpdates1.empty() && !lastUpdates2.empty())
    {
        for (auto &update1 : lastUpdates1)
        {
            for (auto &update2 : lastUpdates2)
            {
                if (update1.getId() != update2.getId())
                {
                    db1.push_back(update2);
                    db2.push_back(update1);
                }
                else
                {
                    if (update1.getLastUpdate() > update2.getLastUpdate())
                    {
                        update2.getLastUpdate = update1.getLastUpdate;
                    }
                    else if (update1.getLastUpdate() < update2.getLastUpdate())
                    {
                        update1.getLastUpdate = update2.getLastUpdate;
                    }
                }
            }
        }
    }
    else if (lastUpdates1.empty())
    {
        db1.insert(db1.end(), lastUpdates2.begin(), lastUpdates2.end());
    }
    else if (lastUpdates2.empty())
    {
        db2.insert(db2.end(), lastUpdates1.begin(), lastUpdates1.end());
    }
    else
    {
        cout << "No updates found in either database." << endl;
    }

    return 0;
}
