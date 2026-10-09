#include <iostream>
#include <vector>

struct Track{
    int popularity;
    int stabilty;
    int index;
};

bool Compare(Track el1, Track el2){
    if (el1.popularity == el2.popularity){
        return (el1.stabilty >= el2.stabilty);
    } else {
        return(el1.popularity >= el2.popularity);
    }
}

void Merge(std::vector<Track>& list, int left, int mid, int right){
    int i = 0;
    int j =0;
    std::vector<Track> result(right - left);
    while ((left + i < mid) && (mid + j < right)){
        if (Compare(list[left + i], list[mid + j])){
            result[i+j] = list[left + i];
            i++;
        } else {
            result[i+j] = list[mid + j];
            j++;
        }
    }
    while (left + i < mid){
        result[i + j] = list[left + i];
        i++;
    }
    while (mid + j < right){
        result[i + j] = list[mid + j];
        j++;
    }
    for (int k = 0; k < i + j; k++){
        list[left + k] = result[k];
    }
}

void MergeSort(std::vector<Track>& list, int left, int right){
    if (left + 1 >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(list, left , mid);
    MergeSort(list, mid, right);
    Merge(list, left, mid, right);
}

int main(){
    int N;
    std:: cin >> N;

    std::vector<Track> tracks(N);


    for (int i =0; i < N; i++){
        std::cin >> tracks[i].popularity >> tracks[i].stabilty;
        tracks[i].index = i+1;
    }

    MergeSort(tracks, 0, N);
    int max_y = -2000000000;    
    std::vector<int> answer;
    for (int i = 0; i < N; i++){
        if ( tracks[i].stabilty > max_y){
            answer.push_back(tracks[i].index);
            max_y = tracks[i].stabilty;
        }
    }

    std::cout << answer.size() << std::endl;
    for (int i =0; i < answer.size(); i++){
        std::cout << answer[i] << " ";
    }

    return 0;
}