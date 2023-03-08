#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

void swap(int&lha, int&rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

void block(int (&array)[N], int i, int r){
    int max = i;

    if (2*i+1 < r and array[max] < array[2*i+1]){
        max = 2*i+1;
    }
    if (2*i+2 < r and array[max] < array[2*i+2]){
        max = 2*i+2;
    }
    if (max!=i){
        swap(array[max], array[i]);
        block(array, max, r);
    }
    
}

void cheops(int (&array)[N]){
    for (int i = N/2; i>=0; i--){
        block(array, i, N);
    }
    for (int i = N-1; i>=0; i--){
        swap(array[0], array[i]);
        block(array, 0, i);
    }
}

int main(){
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cheops(arr);
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}