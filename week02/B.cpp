#include <iostream>

using namespace std;

int main(){
    int i;
    cin >> i;
    int amount = 0;
    while (i != 0){
        if (i % 2 == 0){
            amount += 1;
        }
        cin >> i;
    }
    cout << amount << endl;
    return 0;
}