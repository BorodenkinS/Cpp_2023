#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    float D = b*b - 4*a*c;
    if (D < 0){
        cout << '\n' << endl;
    } else if (D == 0){
        cout << -b/(2*a) << endl;
    } else {
        cout << (-b + sqrt(D))/(2*a) << ' ' << (-b - sqrt(D))/(2*a) << endl;
    }
    return 0;
}