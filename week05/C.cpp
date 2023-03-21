#include <iostream>

using namespace std;

int main(){
    int i;
    int j = 0;
    int* arr = new int[j];
    cin >> i;
    while (i != 0){
        int* array = new int[j+1];
        for(int k = 0; k < j; k++){
            array[k] = arr[k];
        }
        array[j] = i;
        delete [] arr;
        arr = array;
        j++;
        cin >> i;
    }
    for(int k = 0; k < j-1; k++){
        cout << *(arr+k) - *(arr + k + 1) << ' ';
    }
    cout << endl;
    delete [] arr;
    return 0;
}