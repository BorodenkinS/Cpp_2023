#include <iostream>

using namespace std;

unsigned long int fact(int n){
    if (n == 0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int N;
    cin >> N;
    cout << fact(N) << endl;
    return 0;
}