#include <iostream>
#include <cstdlib>

int main(){
    int n;
    std::cin >> n;
    int routes[n];
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        routes[i] = a;
    }
    int x;
    std::cin >> x;
    for (int i = 1; i < n; i++) {
        if (std::abs(x-routes[i]) > std::abs(x-routes[i-1])) {
            std::swap(routes[i], routes[i-1]);
        }
    }
    std::cout << routes[n-1] << std::endl;
}