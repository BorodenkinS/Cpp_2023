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

void gnome(int (&array)[N]){
    for(int i = 1; i < N; i++){
        for(int j = i; j > 0 ; j--){
            if (array[j] < array[j-1]){
                swap(array[j], array[j-1]);
            }
        }
    }
}

int main(){
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    gnome(arr);
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}