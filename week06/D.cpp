#include <iostream>

using namespace std;

struct Street{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
}street1, street2;

int main(){
    Street street1, street2;
    cin >> street1.x_1 >> street1.y_1 >> street1.x_2 >> street1.y_2 >> street2.x_1 >> street2.y_1 >> street2.x_2 >> street2.y_2;
    if ((street1.x_1 <= street2.x_2) & (street1.x_2 >= street2.x_1) & (street1.y_1 <= street2.y_2) & (street1.y_2 >= street2.y_1)){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}