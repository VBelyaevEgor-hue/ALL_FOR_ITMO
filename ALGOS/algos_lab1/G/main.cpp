#include <iostream>
#include <vector>

void CountingSort(int arr1[], int N){
    int counts[101];
    for (int i = 0; i < 101; i++){
        counts[i] = 0;
    }

    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 1; j <= arr1[i]; j++){
            sum += counts[j];
        }
        std::cout << sum << " ";
        counts[arr1[i]] = counts[arr1[i]] + 1;
    }
}

int main(){
    int N;
    std:: cin >> N;

    int arr1[N];
    for (int i = 0; i < N; i++){
        std:: cin >> arr1[i];
    }

    CountingSort(arr1, N);
    return 0;
}