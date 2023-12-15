#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mp = {{"a", 1}, {"b", 2}};

    // insertion
    pair<string, int> p = make_pair("aryan", 23);
    pair<string, int> q("ram", 99);
    pair<string, int> r = {"krinsa", 101};
    pair<string, int> s;
    s.first = "hanuman";
    s.second = 80;

    mp.insert(p);
    mp.insert(q);
    mp.insert(r);
    mp.insert(s);
    mp["ramesh"] = 12;

    // access
    cout << "Value at 'aryan': " << mp.at("aryan") << endl;
    cout << "Value at 'aryan': " << mp["aryan"] << endl;

    // Print size of map
    cout << "Size of map 'mp': " << mp.size() << endl;

    // to check key is present or not: 0/1
    cout << "Is key 'lover' present: " << mp.count("lover") << endl;
    cout << "Is key 'lover' present: " << (mp.find("ram") != mp.end()) << endl;

    // VIP: If you try to access key that is not available using [], a new entry will be created with value 0
    cout << "Size of map 'mp': " << mp.size() << endl;
    cout << mp["radha"] << endl;
    // cout << mp.at("radha") << endl; // this will throw error if key not present so exists check before access
    cout << "Size of map 'mp': " << mp.size() << endl;

    cout << endl;

    // iterate
    cout << "Printing map: " << endl;
    for (const auto &[key, value] : mp)
    {
        cout << key << " - " << value << endl;
    }

    return 0;
}