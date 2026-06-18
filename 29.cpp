#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string name;
    string dob;
    int type;
    vector<string> professions;
    vector<int> categories;
    string uni;
    int grad_year;
    vector<string> langs;
    vector<int> levels;
};

int main() {
    Employee e;
    getline(cin, e.name);
    getline(cin, e.dob);
    cin >> e.type;
    
    if (e.type == 1) {
        int k;
        cin >> k;
        for (int i = 0; i < k && i < 5; ++i) {
            string prof; 
            int cat;
            cin >> prof >> cat;
            e.professions.push_back(prof);
            e.categories.push_back(cat);
        }
    } else if (e.type == 2) {
        cin >> e.uni >> e.grad_year;
        int k;
        cin >> k;
        for (int i = 0; i < k && i < 5; ++i) {
            string lang; 
            int lvl;
            cin >> lang >> lvl;
            e.langs.push_back(lang);
            e.levels.push_back(lvl);
        }
    }
    return 0;
}