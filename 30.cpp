#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    int x = 40, y = 12; // Центр консоли
    srand(time(0));
    
    for (int i = 0; i < 100; ++i) {
        int dir = rand() % 4;
        if (dir == 0) x += 2;
        else if (dir == 1) x -= 2;
        else if (dir == 2) y += 2;
        else if (dir == 3) y -= 2;
        std::cout << "Current position: (" << x << ", " << y << ")" << std::endl;
    }
    return 0;
}