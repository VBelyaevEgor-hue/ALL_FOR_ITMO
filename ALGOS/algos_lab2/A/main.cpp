#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::vector <int> list(N);
    for (int i = 0; i < N; i++){
        std::cin >> list[i];
    }
    
    for (int i = 0; i < N; i++){
        if ((list[2*i] > list[i]) || (list[2*i + 1] > list[i])){
            std::cout << "NO" << std::endl;
            break;
        std::cout << "YES" << std::endl;
    }
}