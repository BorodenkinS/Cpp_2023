#include <iostream>
#include <random>

using namespace std;

#ifndef N
#define N 20
#endif

void swap(unsigned& lha, unsigned& rha){
    unsigned buffer = lha;
    lha = rha;
    rha = buffer;
}

void forward_step(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    for (unsigned i = begin_idx + 1; i <= end_idx; i++){
        if (array[i] < array[i-1]){
            swap(array[i], array[i-1]);
        }
    }
}

void backward_step(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    for (unsigned i = end_idx-1; i > begin_idx; i--){
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

void generate_array(unsigned (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 1000);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

int main(){
    unsigned arr[N];
    generate_array(arr);
    for (int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl; 
    shaker(arr, 0, N);
    for (int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;   
    return 0;
}