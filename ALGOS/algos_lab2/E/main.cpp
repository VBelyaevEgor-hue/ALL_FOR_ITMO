#include <iostream>
#include <vector>

const int MAX_BLOCKS = 30000;
const int L = 600;

namespace forFreeBlocks{
    void SiftUp(std::vector<int> &list, int i){
        while (i > 0){
            int parentIndex = (i - 1) / 2;
            if (list[i] < list[parentIndex]){
                std::swap(list[i], list[parentIndex]);
                i = parentIndex;
            } else{
                break;
            }
        }
    }

    void Insert(std::vector<int> &list, int element){
        list.push_back(element);
        SiftUp(list, list.size() - 1);
    }

    void SiftDown(std::vector<int> &list, int i){
        while (2 * i + 1 < list.size()){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if ((right < list.size()) && ((list[right] < list[left]))){
                j = right;
            }
            if (list[i] <= list[j]){
                break;
            }
            std::swap(list[i], list[j]);
            i = j;
        }
    }

    int ExtractMin(std::vector<int> &list){
        int minElement = list[0];
        std::swap(list[0], list[list.size() - 1]);
        list.pop_back();
        SiftDown(list, 0);
        return minElement;
    }

    void BuidHeap(std::vector<int> &list){
        for (int i = list.size() / 2; i > 0; i--){
            SiftDown(list, i - 1);
        }
    }
}

namespace forBusyBlocks{
    void SiftUp(std::vector<std::pair<int, int>> &list, int i){
        while (i > 0){
            int parentIndex = (i - 1) / 2;
            if (list[i] < list[parentIndex]){
                std::swap(list[i], list[parentIndex]);
                i = parentIndex;
            } else{
                break;
            }
        }
    }

    void Insert(std::vector<std::pair<int, int>> &list, std::pair<int, int> element){
        list.push_back(element);
        SiftUp(list, list.size() - 1);
    }

    void SiftDown(std::vector<std::pair<int, int>> &list, int i){
        while (2 * i + 1 < list.size()){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if ((right < list.size()) && ((list[right] < list[left]))){
                j = right;
            }
            if (list[i] <= list[j]){
                break;
            }
            std::swap(list[i], list[j]);
            i = j;
        }
    }

    std::pair<int, int> ExtractMin(std::vector<std::pair<int, int>> &list){
        std::pair<int, int> minElement = list[0];
        std::swap(list[0], list[list.size() - 1]);
        list.pop_back();
        SiftDown(list, 0);
        return minElement;
    }
}

int main(){
    std::vector<int> freeBlocks(MAX_BLOCKS);
    for (int i = 0; i < MAX_BLOCKS; i++){
        freeBlocks[i] = i + 1;
    }
    forFreeBlocks::BuidHeap(freeBlocks);
    std::vector<std::pair<int, int>> busyBlocks; 
    std::vector<bool> busy(MAX_BLOCKS + 1, false);
    std::vector<int> releaseTime(MAX_BLOCKS + 1, 0);
    int t;
    char operation;
    while (std::cin >> t >> operation){
        while (!busyBlocks.empty() && busyBlocks[0].first <= t){
            std::pair<int, int> released = forBusyBlocks::ExtractMin(busyBlocks);
            if (busy[released.second] && releaseTime[released.second] == released.first){
                busy[released.second] = false;
                forFreeBlocks::Insert(freeBlocks, released.second);
            }
        }
        if (operation == '+'){
            int block = forFreeBlocks::ExtractMin(freeBlocks);
            busy[block] = true;
            releaseTime[block] = t + L;
            forBusyBlocks::Insert(busyBlocks, {t + L, block});
            std::cout << block << '\n';
        } else {
            int block;
            std::cin >> block;
            if (busy[block]){
                releaseTime[block] = t + L;
                forBusyBlocks::Insert(busyBlocks, {t + L, block});
                std::cout << "+" << '\n';
            } else {
                std::cout << "-" << '\n';
            }
        }
    }
    return 0;
}
