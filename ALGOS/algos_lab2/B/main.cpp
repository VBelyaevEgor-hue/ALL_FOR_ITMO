#include <iostream>
#include <vector>


void SiftDown(std::vector<int> &list, int i, int size){
    while (2 * i + 1 < size){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;

            if ((right < size) && ((list[right] > list[left]))){
                j = right;
            }

            if (list[i] >= list[j]){
                break;
            }

            std::swap(list[i], list[j]);
            i = j;
    }
}



void BuildHeap(std::vector<int> &list){
    for (int i = list.size() / 2; i > 0; i--){
        SiftDown(list, i - 1, list.size());
    }
}

void delete_max(std::vector<int> &list, int size){
    std::swap(list[0], list[size - 1]);
    SiftDown(list, 0, size - 1);

}

void HeapSort(std::vector<int> &list){
    BuildHeap(list);
    for (int size = list.size(); size > 1; size--){
        delete_max(list, size);
    }
}

int main(){
    int N;
    std::cin >> N;
    std::vector<int>priorities(N);
    for (int i = 0; i < N; i++){
        std::cin >> priorities[i];
    }
    HeapSort(priorities);
    for (int i = 0; i < N; i++){
        std::cout << priorities[i] << " ";
    }
    return 0;
}