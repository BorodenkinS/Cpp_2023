#include <iostream>

using namespace std;

long long int int_power(int base, int power){
    if (power != 0){
        return base*int_power(base, power-1);
    } else {
        return 1;
    }
}

long long int reverse(long long int n){
    long long int reverse_n = 0;
    int N;
    long long int num = n;
    while (num / 10 != 0){
        N++;
        num = num / 10;
    }
    while (N > 0){
        reverse_n += (n % 10) * int_power(10, N);
        N--;
        n = n / 10;
    }
    reverse_n += (n % 10) * int_power(10, N);
    cout << reverse_n << endl;
    return reverse_n;
}

int main(){
    long long int n;
    cin >> n;
    if (n == reverse(n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}