#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int compare_dates(const string& d1, const string& d2) {
    int day1, month1, year1, day2, month2, year2;
    sscanf(d1.c_str(), "%d/%d/%d", &day1, &month1, &year1);
    sscanf(d2.c_str(), "%d/%d/%d", &day2, &month2, &year2);
    if (year1 != year2) return year1 - year2;
    if (month1 != month2) return month1 - month2;
    return day1 - day2;
}

void test() {
    if (compare_dates("01/01/2000", "02/01/2000") < 0 &&
        compare_dates("01/02/2000", "01/01/2000") > 0 &&
        compare_dates("15/05/2020", "15/05/2020") == 0) return;
    exit(1);
}

int main() {
    test();
    string d1, d2;
    if (cin >> d1 >> d2) cout << compare_dates(d1, d2) << "\n";
    return 0;
}