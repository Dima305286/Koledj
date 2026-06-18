#include <iostream>
#include <fstream>

using namespace std;

bool compare_files(const string& f1, const string& f2) {
    ifstream file1(f1, ios::binary);
    ifstream file2(f2, ios::binary);
    if (!file1.is_open() || !file2.is_open()) return false;
    char c1, c2;
    while (file1.get(c1) && file2.get(c2)) {
        if (c1 != c2) return false;
    }
    return file1.eof() && file2.eof();
}

void test() {
    ofstream out1("t1.txt"), out2("t2.txt"), out3("t3.txt");
    out1 << "abc"; out2 << "abc"; out3 << "abd";
    out1.close(); out2.close(); out3.close();
    if (!compare_files("t1.txt", "t2.txt") || compare_files("t1.txt", "t3.txt")) exit(1);
    remove("t1.txt"); remove("t2.txt"); remove("t3.txt");
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        cout << (compare_files(argv[1], argv[2]) ? "Match" : "Differ") << "\n";
    } else {
        test();
    }
    return 0;
}