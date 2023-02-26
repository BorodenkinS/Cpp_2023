#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif

#ifndef M
#define M 2
#endif

void sort2d(int (&array)[N][M]) {
    int line_array[N*M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            line_array[j+M*i] = array[i][j];
        }
    }
    for (int j = 0; j < N*M; j++) {
        int num = line_array[j];
        int k = j - 1;
        while (k >= 0 & num < line_array[k]) {
            line_array[k + 1] = line_array[k];
            k--; 
            line_array[k + 1] = num;
        }
    }
    for (int i = 0; i<N*M; i++) {
        array[i/M][i%M] = line_array[i];
    }
}

int main(){
    int arr[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> arr[i][j];
        }
    }
    sort2d(arr);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}