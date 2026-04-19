#include <vector>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class city
{
    long population;
    string country;
    string cityName;
    int id;
    double lat;
    double lng;
    string iso2;
    string iso3;

public:
    city() : id(0), population(0), lat(0), lng(0) {}
    city(int id, string country, double lat, double lng, string cityName, string iso2, string iso3, long population = 0)
    {
        this->country = country;
        this->cityName = cityName;
        this->population = population;
        this->lat = lat;
        this->lng = lng;
        this->iso2 = iso2;
        this->iso3 = iso3;
        this->id = id;
    }
    void display()
    {
        cout << "id:" << id << "lat is:" << lat << "citi name is:" << cityName << "|| population is:" << population << endl;
    }
    long getpop()
    {
        return population;
    }
    int getid()
    {
        return id;
    }
    void setpop(int a)
    {
        population = a;
    }
    static void loadFromFile(string filename, vector<city> &cities);
    string getCityname()
    {
        return cityName;
    }
    friend city comparepop(vector<city> &cities);
};

void city::loadFromFile(string filename, vector<city> &cities)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Could not open the file!" << endl;
        return;
    }
    string line;
    getline(file, line);

    string temp = " ";
    int id;
    string country, cityName, iso2, iso3;
    double lat, lng;
    long population;
    while (getline(file, line))
    {
        stringstream ss(line);
        try
        {
            getline(ss, temp, ',');
            id = stoi(temp);
            getline(ss, country, ',');
            getline(ss, temp, ',');
            lat = stod(temp);
            getline(ss, temp, ',');
            lng = stod(temp);
            getline(ss, cityName, ',');
            getline(ss, iso2, ',');
            getline(ss, iso3, ',');
            getline(ss, temp, ',');
            population = stol(temp);

            cities.emplace_back(id, country, lat, lng, cityName, iso2, iso3, population);
        }
        catch (...)
        {
            continue;
        }
    }
}
city comparepop(vector<city> &cities)
{
    int index = 0;
    for (int i = 1; i < cities.size(); i++)
    {
        if (cities[i].getpop() > cities[index].getpop())
        {
            index = i;
        }
    }
    city topcity = cities[index];
    cities.erase(cities.begin() + index);
    return topcity;
}
string game(vector<city> &worldCities, vector<city> &gameCities, string name)
{

    if (name.empty())
        return "";
    gameCities.clear();
    char lastChar = name.back();
    lastChar = toupper(name.back());
    for (int i = 0; i < worldCities.size(); i++)
    {
        if (worldCities[i].getCityname()[0] == lastChar)
        {
            gameCities.push_back(worldCities[i]);
        }
    }

    if (gameCities.empty())
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        string gameName = comparepop(gameCities).getCityname();
        return gameName;
    }

    return "";
}

int main()
{
    vector<city> worldCities;
    vector<city> gameCities;
    city::loadFromFile("worldcities(2).csv", worldCities);
    string name;
    string helpname;
    while (true)
    {
        cout << "enter city name: ";
        getline(cin, name);
        if (name == "exit")
            break;
        if (name.empty())
            continue;;
        if (name != "help")
        {
            helpname = game(worldCities, gameCities, name);
            cout << helpname << endl;
        }
        string temp = helpname;
        if (name == "help")
        {
            name = temp;
            cout << game(worldCities, gameCities, name) << endl;
        }
    }
    return 0;
}