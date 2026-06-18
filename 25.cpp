#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count_lines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return -1;
    int count = 0;
    string line;
    while (getline(file, line)) count++;
    return count;
}

void test() {
    ofstream out("temp.txt");
    out << "1\n2\n3\n";
    out.close();
    if (count_lines("temp.txt") != 3) exit(1);
    remove("temp.txt");
}

int main() {
    test();
    string filename;
    if (cin >> filename) cout << count_lines(filename) << "\n";
    return 0;
}