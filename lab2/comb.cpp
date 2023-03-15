#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 1000
#endif

void swap(int& lha, int& rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

int step(int (&array)[N], int k, int n){
    int counter = 0;
    for (int i = 0; i < n-k; i += k){
        for (int j = 0; j < n-k-i; j += k){
            if (array[j+k] < array[j]){
                swap(array[j], array[j+k]);
                counter ++;
            }
        }
    }
    return counter;
}

int comb(int (&array)[N], int n){
    int counter = 0;
    for (int i = n/2; i > 0; i /= 2){
        counter += step(array, i, n);
    }
    return counter;
}

void generate_array(int (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 1000);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

int main(){
    int arr[N];
    ofstream out;
    out.open("comb_stat.txt");
    for (int i = 0; i <= N; i += 10){
        int t = 0, c = 0;
        for (int j = 0; j < 5000; j++){
            generate_array(arr);
            auto begin = chrono::steady_clock::now();
            c += comb(arr, i);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);
            t += time_span.count();
        }
        cout << i << ' ' << t/5000 << ' ' << c/5000 << endl;
        out << i << ' ' << t/5000 << ' ' << c/5000 << endl;
    }
    out.close();
    return 0;
}