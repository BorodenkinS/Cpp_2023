#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int main(){
    int arr[N];
    int k;
    cin >> k;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < k%N; i++){
        for(int j = 1; j < N; j++){
            swap(arr[N-j], arr[N-j-1]);
        }
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}