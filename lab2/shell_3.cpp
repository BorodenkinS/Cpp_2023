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

int F(int n){
    if (n > 1){
        return F(n-1) + F(n-2);
    }
    return 1;
}

int biggest_fibonacci(int n){
    int i = 0;
    while (F(i) <= n){
        i++;
    }
    return i;
}

int step(int (&array)[N], int k, int n){
    int counter = 0;
    for (int i = 0; i < n-k; i += k){
        for (int j = i+k; j >=0; j -= k){
            if (array[j] < array[j-1]){
                swap(array[j], array[j-1]);
                counter++;
            }
        }
    }
    return counter;
}

int shell(int (&array)[N], int n){
    int counter = 0;
    for(int i = biggest_fibonacci(n); i > 0; i--){
        counter += step(array, F(i), n);
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
    long int total = 0;
    ofstream out;
    out.open("shell_3_stat.txt");
    cout << endl;
    for (int i = 0; i <= N; i += 10){
        int t = 0, c = 0;
        for (int j = 0; j < 1000; j++){
            generate_array(arr);
            auto begin = chrono::steady_clock::now();
            c += shell(arr, i);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);
            t += time_span.count();
        }
        total += c/1000;
        cout << i << ' ' << t/1000 << ' ' << c/1000 << endl;
        out << i << ' ' << t/1000 << ' ' << c/1000 << endl;
    }
    out.close();
    cout << total/100 << endl;
    return 0;
}