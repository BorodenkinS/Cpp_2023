#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n){
    for(int i = 2; i < floor(sqrt(n)); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if (is_prime(n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}