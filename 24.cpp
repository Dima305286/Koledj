#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string get_current_date() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string months[] = {"январь", "февраль", "март", "апрель", "май", "июнь", 
                       "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"};
    char buf[64];
    snprintf(buf, sizeof(buf), "%02d/%s/%04d", now->tm_mday, months[now->tm_mon].c_str(), now->tm_year + 1900);
    return string(buf);
}

void test() {
    string d = get_current_date();
    if (!d.empty() && d.find('/') != string::npos) return;
    exit(1);
}

int main() {
    test();
    cout << get_current_date() << "\n";
    return 0;
}