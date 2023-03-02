#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 510000
#endif

void binary_search(int value, int (&array)[N], int r, int l = 0){
    while(r >= l){
        int mid = l + (r - l) / 2;
        if (array[mid] > value){
            r = mid - 1;
        } else if (array[mid] < value){
            l = mid + 1;
        } else {
            return;
        }
    }
    return;
}

void generate_array(int (&array)[N]){
    for(int i = 0; i < N; i++){
        array[i] = i;
    }
}

int main(){
    int arr[N];
    int t;
    generate_array(arr);
    std::ofstream out;
    out.open("1_bin_stat.txt");
    for(int n = 5000; n <= N; n += 1000){
        t = 0;
        for(int j = 1000; j > 0; j--){
            auto begin = std::chrono::steady_clock::now();
            binary_search(-1, arr, n);
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            t += time_span.count();
        }
        std::cout << t/1000 << ' ' << n << std::endl;
        out << n << ' ' << t/1000 << std::endl;
    }
    out.close();
    return 0;
}