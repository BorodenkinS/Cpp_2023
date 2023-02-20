#include <iostream>

using namespace std;

long long int F(int n){
    if (n > 1){
        return F(n-1) + F(n-2);
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    cout << F(n) << endl;
    return 0;
}