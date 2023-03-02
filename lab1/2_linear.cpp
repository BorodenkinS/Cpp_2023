#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 510000
#endif

void linear_search(int k, int array[N], int n){
    int r = n - 1, l = 0;
    while (r >= l){
        if (array[r] + array[l] > k){
            r--;
        } else if (array[r] + array[l] < k){
            l++;
        } else {
            return;
        }
    }
}

void generate_array(int (&array)[N]){
    for(int i = 0; i < N; i++){
        array[i] = i;
    }
}

int main() {
    int arr[N];
    int k = 2*N;
    int t;
    generate_array(arr);
    std::ofstream out;
    out.open("2_lin_stat.txt");
    for(int n = 5000; n <= N; n += 1000){
        t = 0;
        for(int j = 50; j > 0; j--){
            auto begin = std::chrono::steady_clock::now();
            linear_search(-1, arr, n);
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            t += time_span.count();
        }
        std::cout << t/50 << ' ' << n << std::endl;
        out << n << ' ' << t/50 << std::endl;
    }
    out.close();
    return 0;
}