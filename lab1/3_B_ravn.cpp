#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 510000
#endif

void swap(int&lha, int&rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

void linear_search_B(int value, int (&array)[N], int n){
    for(int i = 0; i < n; i++){
        if (array[i] == value & array[i] != array[0]){
            swap(array[i-1], array[i]);
            return;
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

int main() {
    int arr[N];
    int k;
    unsigned seed = 1001;
    generate_array(arr);
    std::ofstream out;
    out.open("B_stat.txt");
    for(int n = 5000; n <= N; n += 1000){
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, N);
        auto begin = std::chrono::steady_clock::now();
        for(int j = 2000; j > 0; j--){
            k = dstr(rng);
            linear_search_B(k, arr, n);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << time_span.count() << ' ' << n << std::endl;
        out << n << ' ' << time_span.count() << std::endl;
    }
    out.close();
    return 0;
}