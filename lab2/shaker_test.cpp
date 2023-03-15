#include <iostream>
#include <random>

using namespace std;

#ifndef N
#define N 50
#endif

void swap(unsigned& lha, unsigned& rha){
    unsigned buffer = lha;
    lha = rha;
    rha = buffer;
}

void forward_step(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    for (unsigned i = begin_idx; i < end_idx; i++){
        if (array[i+1] < array[i]){
            swap(array[i+1], array[i]);
        }
    }
}

void backward_step(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    for (unsigned i = end_idx; i > begin_idx; i--){
        if (array[i] < array[i-1]){
            swap(array[i], array[i-1]);
        }
    }
}

void shaker(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    unsigned l = begin_idx, r = end_idx;
    while (l <= r){
        forward_step(array, l, r);
        r--;
        backward_step(array, l, r);
        l++;
    }
}

void generate_array(unsigned (&array)[]){
    int seed = 7583;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 1000);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

void test(unsigned (&array)[N], unsigned n){
    for (int j = 0; j < n - 1; j++){
        if (array[j] > array[j+1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    unsigned arr[N];
    for (unsigned i = 5; i <= N; i += 5){
        generate_array(arr); 
        shaker(arr, 0, i); 
        test(arr, i);
    }
    return 0;
}