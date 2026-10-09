
#include <iostream>

bool Compare(int list1[3], int list2[3]){
    if (list1[0] == list2[0]){
        return (list1[1] <= list2[1]);
    } else{
        return (list1[0] <= list2[0]);
    }
}

void Merge(int list[][3], int left, int mid, int right){
    int i = 0;
    int j = 0;
    int result[right - left][3];

    while ((left + i < mid) && (mid + j < right)){
        if (Compare(list[left + i], list[mid + j])){
            result[i+j][0] = list[left + i][0];
            result[i+j][1] = list[left + i][1];
            result[i + j][2] = list[left + i][2];
            i++;
        } else {
            result[i + j][0] = list[mid + j][0];
            result[i + j][1] = list[mid + j][1];
            result[i + j][2] = list[mid + j][2];
            j++;
        }
    }
    while (left + i < mid){
        result[i + j][0] = list[left + i][0];
        result[i + j][1] = list[left + i][1];
        result[i + j][2] = list[left + i][2];
        i++;
    }
    while (mid + j < right){
        result[i + j][0] = list[mid + j][0];
        result[i + j][1] = list[mid + j][1];
        result[i + j][2] = list[mid + j][2];
        j++;
    }
    for (int p = 0; p < i + j; p++){
        list[left + p][0] = result[p][0];
        list[left +p][1] = result[p][1];
        list[left +p][2] = result[p][2];
    }

}

void MergeSort(int list[][3], int left, int right){
    if (left + 1 >= right){
        return;
    }
    int mid = (left + right)/2;
    MergeSort(list, left, mid);
    MergeSort(list, mid, right);
    Merge(list, left, mid, right);
}

int main(){
    int N;
    std::cin >> N;

    int tracks[N][3];
    for (int i = 0; i < N; i++){
        std::cin >> tracks[i][0] >> tracks[i][1];
        tracks[i][2] = i+1;
    }

    MergeSort(tracks, 0, N);
    for (int i = 0; i < N; i++){
        std::cout << tracks[i][2] << " ";
    }
    return 0;
}