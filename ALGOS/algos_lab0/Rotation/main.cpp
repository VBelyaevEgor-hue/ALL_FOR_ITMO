#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int rotation[n];
    for (int i = 0; i < n; i++) {
        int deliverID;
        std:: cin >> deliverID;
        rotation[i] = deliverID;
    }
    std::cout << rotation[n-1] << " ";
    for (int i = 0; i < n-1; i++) {
        std::cout << rotation[i] << " ";
    }
    return 0;
}