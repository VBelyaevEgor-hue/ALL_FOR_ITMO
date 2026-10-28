#include <iostream>
#include <vector>

struct Item{
    long long value;
    int index;
};


namespace MaxHeap{
    void SiftUp(std::vector<Item> &list, int i){
        while (i > 0){
            int parentIndex = (i - 1) / 2;
            if (list[i].value > list[parentIndex].value){
                std::swap(list[i], list[parentIndex]);
                i = parentIndex;
            } else{
                break;
            }
        }
    }

    void SiftDown(std::vector<Item> &list, int i){
        while (2 * i + 1 < list.size()){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if ((right < list.size()) && ((list[right].value > list[left].value))){
                j = right;
            }
            if (list[i].value >= list[j].value){
                break;
            }
            std::swap(list[i], list[j]);
            i = j;
        }
    }
}

namespace MinHeap{
    void SiftUp(std::vector<Item> &list, int i){
        while (i > 0){
            int parentIndex = (i - 1) / 2;
            if (list[i].value < list[parentIndex].value){
                std::swap(list[i], list[parentIndex]);
                i = parentIndex;
            } else{
                break;
            }
        }
    }

    void SiftDown(std::vector<Item> &list, int i){
        while (2 * i + 1 < list.size()){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if ((right < list.size()) && ((list[right].value < list[left].value))){
                j = right;
            }
            if (list[i].value <= list[j].value){
                break;
            }
            std::swap(list[i], list[j]);
            i = j;
        }
    }
}



void Insert(std::vector<Item> &list, long long insertion, int index, bool Max){
    list.push_back({insertion, index});
    if (Max){
        MaxHeap::SiftUp(list, list.size() - 1);
    } else {
        MinHeap::SiftUp(list, list.size() - 1);
    }
}

void Delete(std::vector<Item> &list, bool Max){
    std::swap(list[0], list[list.size() - 1]);
    list.erase(list.begin() + list.size() - 1);
    if (Max){
        MaxHeap::SiftDown(list, 0);
    } else {
        MinHeap::SiftDown(list, 0);
    }
}

int main() {
    int N;
    int insertsCount = 0;
    std::cin >> N;
    std::cin.ignore();
    std::vector<bool> removed(N + 1, false);
    std::vector<Item> minHeap;
    std::vector<Item> maxHeap;
    for (int i = 0; i < N; i++){
        insertsCount += 1;
        char currentOperation[64];
        std::cin.getline(currentOperation, 64);
        if (currentOperation[0] == 'I'){
            long long insertion = 0;
            bool isNegative = false;
            for (int j = 0; currentOperation[j] != '\0'; j++){
                if (currentOperation[j] == '-'){
                    isNegative = true;
                } else if ((currentOperation[j] >= '0') && (currentOperation[j] <= '9')) {
                    insertion = insertion * 10 + (currentOperation[j] - '0');
                }
            }
            if (isNegative){
                insertion = -insertion;
            }
            Insert(maxHeap, insertion, insertsCount, true);
            Insert(minHeap, insertion, insertsCount,false);
        } else if (currentOperation[4] == 'a'){
            while (removed[maxHeap[0].index]){
                Delete(maxHeap, true);
            }
            std::cout << maxHeap[0].value << '\n';
            removed[maxHeap[0].index] = true;
            Delete(maxHeap, true);
        } else if (currentOperation[4] == 'i'){
            while (removed[minHeap[0].index]){
                Delete(minHeap, false);
            }
            std::cout << minHeap[0].value << '\n';
            removed[minHeap[0].index] = true;
            Delete(minHeap, false);

        }
    }
    return 0;
}