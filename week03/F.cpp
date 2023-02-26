#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int binsearch(int (&array)[N]){
    int i = 0, l = 0, r = N-1;
    while (l < r){
        i = (l + r)/2;
        if (array[i] == 1){
            r = i;
        } else {
            l = i;
        }
        if (l == r - 1){
            return l;
        }
    }
    return l - 1;
}

int main(){
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << binsearch(arr) << endl;
    return 0;
}