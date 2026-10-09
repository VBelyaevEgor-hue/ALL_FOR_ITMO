#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
using namespace std;

uint32_t cur = 0;

uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;
    return cur >> 8;
}

uint32_t nextRand32(uint32_t a, uint32_t b) {
    uint32_t x = nextRand24(a, b);
    uint32_t y = nextRand24(a, b);
    return (x << 8) ^ y;
}

// k-й по порядку элемент (нумерация с 0), массив меняется на месте
uint32_t quickSelect(vector<uint32_t>& arr, int k) {
    int l = 0, r = (int)arr.size() - 1;
    while (l < r) {
        uint32_t pivot = arr[l + rand() % (r - l + 1)];

        int lt = l, i = l, gt = r;
        while (i <= gt) {
            if (arr[i] < pivot) {
                uint32_t t = arr[lt]; arr[lt] = arr[i]; arr[i] = t;
                lt++; i++;
            } else if (arr[i] > pivot) {
                uint32_t t = arr[gt]; arr[gt] = arr[i]; arr[i] = t;
                gt--;
            } else {
                i++;
            }
        }
        // [l, lt-1] < pivot, [lt, gt] == pivot, [gt+1, r] > pivot
        if (k < lt)      r = lt - 1;
        else if (k > gt) l = gt + 1;
        else             return pivot;
    }
    return arr[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n, a, b;
    cin >> n >> a >> b;

    vector<uint32_t> arr(n);
    for (uint32_t i = 0; i < n; i++)
        arr[i] = nextRand32(a, b);

    long long x = quickSelect(arr, n / 2);   // медиана

    long long sum_ans = 0;
    for (uint32_t i = 0; i < n; i++) {
        long long d = (long long)arr[i] - x;
        sum_ans += d < 0 ? -d : d;
    }

    cout << sum_ans << "\n";
}
