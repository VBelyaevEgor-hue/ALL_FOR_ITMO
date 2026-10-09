#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int orders[n];
    for (int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        orders[i] = a;
    }
    int b = 0;
    for (int i =1; i < n-1; i++){
        if ((orders[i-1] < orders[i]) && (orders[i+1] < orders[i])){
            b++;
        }
    
    }
    if ((orders[0] > orders[1]) && (orders[0] > orders[n-1])){
        b++;
    }
    if ((orders[n-1] > orders[n-2]) && (orders[n-1] > orders[0])){
        b++;
    }
    
    std::cout << b << std::endl;
    return 0;
}