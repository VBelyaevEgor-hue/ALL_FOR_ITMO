#include <iostream>
#include <algorithm>
#include <cstdlib>

int Partrition(int list[], int left, int right){

    int random = left + rand() % (right - left + 1);
    std::swap(list[random], list[right]);
    
    int pivot = list[right];
    int i = left - 1;

    for(int j = left; j <right; j++){
        if (list[j] <= pivot){
            i +=1;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i+1], list[right]);
    return i + 1;
}

void QuickSort(int list[], int left, int right){
    if (left < right){
        int q = Partrition(list, left, right);

        QuickSort(list, left, q-1);
        QuickSort(list, q+1, right);
    }
}


int main(){
    int N;
    std::cin >> N;
    int tracks[N];
    for (int i = 0; i < N; i++){
        std::cin >> tracks[i];
    }

    if (N > 0) {
        QuickSort(tracks, 0, N - 1);
    }

    for (int i = 0; i < N; i++){
        std::cout << tracks[i] << " ";
    }
    return 0;
}