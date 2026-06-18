#include <iostream>
#include <string>

using namespace std;

struct YoungPerson {
    string name;
    string dob;
    int status;
    string school;
    string grade;
    string uni;
    string faculty;
    string group;
};

int main() {
    YoungPerson p;
    getline(cin, p.name);
    getline(cin, p.dob);
    cin >> p.status;
    cin.ignore();
    
    if (p.status == 1) {
        getline(cin, p.school);
        getline(cin, p.grade);
    } else if (p.status == 2) {
        getline(cin, p.uni);
        getline(cin, p.faculty);
        getline(cin, p.group);
    }
    return 0;
}