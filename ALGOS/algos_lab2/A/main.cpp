#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::vector <long long> list(N);
    for (int i = 0; i < N; i++){
        std::cin >> list[i];
    }
    bool right = true;
    for (int i = 0; i < N; i++){
        if (2*i + 1 < N && list[i] > list[2*i + 1]){
            right = false;
        }
        if (2*i + 2 < N && list[i] > list[2*i + 2]){
            right = false;
        }
    }
    if (right){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}