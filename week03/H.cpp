#include <iostream>

using namespace std;

#ifndef N
#define N 4
#endif

#ifndef M
#define M 3
#endif

void print_transpose(int (&array)[N][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << array[j][i] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int arr[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> arr[i][j];
        }
    }
    print_transpose(arr);
    return 0;
}