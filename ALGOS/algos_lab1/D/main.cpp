#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'000'000;
uint32_t arr[MAXN];
uint64_t inversions = 0;
uint32_t cur = 0;

uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;
    return cur >> 8;
}

void Merge(uint32_t arr[], int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int result[right - left];

    while ((left + i < mid) && (mid + j < right)) {
        if (arr[left + i] <= arr[mid + j]){
            result[i + j] = arr[left + i];
            i++;
        } else {
            result[i + j] = arr[mid + j];
            inversions += mid - (left + i);
            j++;
        }
    }
    while (left + i < mid) {
        result[i + j] = arr[left + i];
        i++;
    }
    while (mid + j < right) {
        result[i + j] = arr[mid + j];
        j++;
    }
    for (int k = 0; k < i + j; k++) {
        arr[left + k] = result[k];
    }
}

void MergeSort(uint32_t arr[], int left, int right){
    if (left + 1 >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid, right);
    Merge(arr, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n, m, a, b;
    if (!(cin >> n >> m >> a >> b)) {
        return 0;
    }

    if (n > MAXN) {
        cerr << "n exceeds limit\n";
        return 1;
    }

    for (uint32_t i = 0; i < n; ++i) {
        arr[i] = nextRand24(a, b) % m;
    }

    MergeSort(arr, 0, n);
    cout << inversions;
    return 0;
}