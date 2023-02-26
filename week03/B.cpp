#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void swap(int&lha, int&rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

int main(){
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < N; i++){
        swap(arr[N-i], arr[N-i-1]);
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}