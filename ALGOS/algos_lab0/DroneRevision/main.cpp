#include <iostream>
#include <algorithm>

int main(){
    int n;
    std::cin >>n;
    int droneID[n];
    for (int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        droneID[i] = a;
    }
    int FirstMinValue = droneID[0];
    for (int i =0; i < n; i++) {
        if (droneID[i] < FirstMinValue) {
           FirstMinValue = droneID[i];
        }
    }
    if (std::count(droneID, droneID + n, FirstMinValue) == 1){
        int SecondMinValue = droneID[0];
        for (int i =0; i < n; i++) {
            if ((droneID[i] < SecondMinValue) && (droneID[i] != FirstMinValue)) {
                SecondMinValue = droneID[i];
            }
        }
        std::cout <<FirstMinValue<< " " <<SecondMinValue <<std::endl;
    } else {
        std::cout <<FirstMinValue<< " " <<FirstMinValue <<std::endl;
    }
    return 0;
}
