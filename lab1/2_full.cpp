#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 510000
#endif

void full_enumeration(int k, int array[N], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(array[i] + array[j] == k){
                return;
            }
        }
    }
}

void generate_array(int (&array)[N]){
    unsigned seed = 1001;
    std::default_random_engine rgn(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rgn);
    }
}

int generate_value(){
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    return dstr(rng);
}

int main() {
    int arr[N];
    int k = 2*N;
    generate_array(arr);
    std::ofstream out;
    out.open("2_full_stat.txt");
    for(int n = 5000; n <= N; n += 10000){
        auto begin = std::chrono::steady_clock::now();
        full_enumeration(k, arr, n);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << time_span.count() << ' ' << n << std::endl;
        out << n << ' ' << time_span.count() << std::endl;
    }
    out.close();
    return 0;
}