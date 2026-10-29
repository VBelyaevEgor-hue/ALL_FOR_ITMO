#include <iostream>
#include <vector>

struct TaskOptions{
    long long startTime;
    int value;
};

namespace forFreeCores{
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
            SiftDown(list, i -1);
        }
    }
}

namespace forBusyCores{
    void SiftUp(std::vector<std::pair<long long, long long>> &list, int i){
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

    void Insert(std::vector<std::pair<long long, long long>> &list, std::pair<long long, long long> element){
        list.push_back(element);
        SiftUp(list, list.size() - 1);
    }

    void SiftDown(std::vector<std::pair<long long, long long>> &list, int i){
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

    std::pair<long long, long long> ExtractMin(std::vector<std::pair<long long, long long>> &list){
        std::pair<long long, long long> minElement = list[0];
        std::swap(list[0], list[list.size() - 1]);
        list.pop_back();
        SiftDown(list, 0);
        return minElement;
    }

    void BuidHeap(std::vector<std::pair<long long, long long>> &list){
        for (int i = list.size() / 2; i > 0; i--){
            SiftDown(list, i -1);
        }
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> freeCores(n);
    for (int i = 0; i < n; i++){
        std::cin >> freeCores[i];
    }
    forFreeCores::BuidHeap(freeCores);
    std::vector<std::pair<long long, long long>> busyCores; // (время освобождения, ставка)
    long long total = 0;
    for (int j = 0; j < m; j++){
        long long t, f;
        std::cin >> t >> f;
        while (!busyCores.empty() && busyCores[0].first <= t){
            forFreeCores::Insert(freeCores, forBusyCores::ExtractMin(busyCores).second);
        }
        if (freeCores.empty()){
            continue;
        }
        long long rate = forFreeCores::ExtractMin(freeCores);
        total += rate * f;
        forBusyCores::Insert(busyCores, {t + f, rate});
    }
    std::cout << total;
    return 0;
}