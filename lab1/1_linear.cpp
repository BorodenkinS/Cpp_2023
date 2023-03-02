#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 510000
#endif

void linear_search(int value, int array[N], int n){
    for(int i = 0; i < n; i++){
        if(array[i] == value){
            return;
        }
    }
}

void generate_array(int (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

int main(){
    int arr[N];
    int t;
    generate_array(arr);
    std::ofstream out;
    out.open("1_lin_stat.txt");
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