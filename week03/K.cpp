#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int trace(int (&array)[N][N]){
    int trace = 0;
    for(int i = 0; i < N; i++){
        trace += array[i][i];
    }
    return trace;
}

int main(){
    int arr[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }     
    }
    cout << trace(arr) << endl;
    return 0;
}