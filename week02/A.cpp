#include <iostream>

using namespace std;

bool is_leap(int year){
    if (year % 400 == 0 | year % 4 == 0 & year % 100 != 0){
        return true;
    } else {
        return false;
    }
}

int main(){
    int year;
    cin >> year;
    if (is_leap(year)){
        cout << "YES" << endl;
    } else {
       cout << "NO" << endl; 
    }
    return 0;
}