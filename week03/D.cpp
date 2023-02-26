#include <iostream>

using namespace std;

#ifndef N
#define N 6
#endif

void swap(int&lha, int&rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

int main() {
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(arr[j] < 0 and arr[j+1] >= 0){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}