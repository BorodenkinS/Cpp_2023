#include <iostream>

using namespace std;

int int_power(int base, int power){
    if (power != 0){
        return base*int_power(base, power-1);
    } else {
        return 1;
    }
}

int main(){
    int a, n;
    cin >> a;
    cin >> n;
    cout << int_power(a, n) << endl;
    return 0;
}