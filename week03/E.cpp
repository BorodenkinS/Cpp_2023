#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int main(){
    int a[N], b[N], c[2*N];
    int j = 0, k = 0, i = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    for (int i = 0; i < N; i++){
        cin >> b[i];
    }
    while(j < N & k < N & i < 2*N) {
        if (a[j] < b[k]) {
            c[i] = a[j];
            ++j;
        } else {
            c[i] = b[k];
            ++k;
        }
        i++;
    }
    while (j < N) {
        c[k+j] = a[j];
        j++;
    }
    while (k < N) {
        c[k + j] = b[k];
        k++;
    }
    for (int i = 0; i < 2*N; i++){
        cout << c[i] << ' ' ;
    }
    cout << endl;
    return 0;
}