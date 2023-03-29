#include <iostream>

using namespace std;

struct Student{
    string name;
    int avpoint;
};

int main(){
    Student students[10];
    int M;
    for (int i = 0; i < 10; i++){
        Student s;
        cin >> s.name >> s.avpoint;
        students[i] = s;
    }
    cin >> M;
    for (int i = 0; i < 10; i++){
        if (students[i].avpoint >= M){
            cout << students[i].name << ' ';
        }
    }
    cout << endl;
    return 0;
}
