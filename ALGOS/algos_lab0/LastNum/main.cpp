#include <iostream>

int main() {
    int a;
    std::cin >> a;
    while (a > 10){
        a = a%10;
    }
    std::cout <<a << std::endl;
}