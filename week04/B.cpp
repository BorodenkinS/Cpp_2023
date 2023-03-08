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

int permutation(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quick(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = permutation(arr, l, r);

        quick(arr, l, pivot - 1);
        quick(arr, pivot + 1, r);
    }
}

int main(){
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    quick(arr, 0, N-1);
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}