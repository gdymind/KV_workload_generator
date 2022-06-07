#include "zipf.hpp"
#include<cstring>

int main() {
    Zipf z;
    z.Init(20);
    int a[101];
    std::memset(a, 0, sizeof(a));
    for (int i = 0; i <= 1000; i++) {
        a[z.Next()]++;
    }

    for (int i = 0; i <= 20; i++) {
        std::cout << i << " " << a[i] << std::endl;
    }
    return 0; 
}