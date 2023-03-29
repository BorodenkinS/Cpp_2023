#include <iostream>

using namespace std;

struct Student{
    string name;
    int avpoint;
};

void swap(Student &stud1, Student &stud2){
    Student buffer = stud1;
    stud1 = stud2;
    stud2 = buffer;
}

void sort_students(int N, Student (&students)[]){
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-i; j++){
            if (students[j].avpoint > students[j+1].avpoint){
                swap(students[j], students[j+1]);
            } else if ((students[j].avpoint == students[j+1].avpoint) & (students[j].name.compare(students[j+1].name))){
                swap(students[j], students[j+1]);
            }
        }
    }
}

int main(){
    int N, M;
    int n = 0;
    cin >> N;
    Student students[N], good_students[N];;
    for (int i = 0; i < N; i++){
        Student s;
        cin >> s.name >> s.avpoint;
        students[i] = s;
    }
    cin >> M;
    for (int i = 0; i < N; i++){
        if (students[i].avpoint >= M){
           good_students[n] = students[i];
        }
        n++;
    }
    sort_students(n, good_students);
    for (int i = 0; i < n; i++){
        cout << good_students[i].name << ' ';
    }
    cout << endl;
    return 0;
}
