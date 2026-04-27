// can't finish the code beacause of not having enough skills to working with json.
#include <string>
#include <nlohmann/json.hpp>
#include <ifstream>
#include <iostream>
#include <vector>
using json = nlohmann::json;
using namespace std;
class Person
{


public:
    int point;
    string fullName;
    Person *ptr;
    Person(string fullName = "", int point = 0, Person *ptr = nullptr)
    {
        this->fullName = fullName;
        this->point = point;
        this->ptr = ptr;
    }
    ~Person()
    {
        delete ptr;
    }
    void displayfullName()
    {
        cout << "Names:\n"
             << fullName << endl;
    }

    friend void from_json(const json &j, Person &p);
};
// i used AI to compare the json object with the person class 
void from_json(const json &j, Person &p) 
{
    j.at("fullName").get_to(p.fullName); // compaare json object with person class and assign values to person class
    j.at("point").get_to(p.point);
    if (j.contains("child") && !j["child"].is_null())
    {
        p.ptr = new Person();  
        j.at("child").get_to(*p.ptr); // recursive call to assign values to child person
    }
    else
    {
        p.ptr = nullptr;
    }

}

int main()
{
    ifstream file("data.json");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    json j;
    file >> j;
    Person person;
    from_json(j, person);
    

    return 0;
}