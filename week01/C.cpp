#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n){
    int fact = 1;
    if (n == 0){
        fact = 1;
    }
    else{
        for(int i = 1; i <= n; i++){
            fact *= i;
            cout << fact << endl;
        }
    }
    return fact;
}

int main(){
    int number;
    cin >> number;
    cout << factorial(number) << endl;
    return 0;
}