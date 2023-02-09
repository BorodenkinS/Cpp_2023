#include <iostream>
#include <cmath>

using namespace std;

int GCD(int a, int b){
    while (a > 0 & b > 0){
        if (a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return max(a, b);
}

int LCM(int a, int b){
    return a*b/GCD(a, b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << LCM(a , b) << endl;
    return 0;
}