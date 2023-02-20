#include <iostream>

using namespace std;

void check(int n){
    if (n % 2 == 0 & n > 1){
        check(n/2);
    } else if (n % 2 == 1 & n > 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
    int N;
    cin >> N;
    check(N);
    return 0;
}