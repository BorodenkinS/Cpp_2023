#include <iostream>

using namespace std;

struct Segment{
    int start;
    int end;
};

void check(int N, Segment segments[]){
    for (int i = 0; i < N; i++){
        if (((segments[i].end < segments[i+1].start) | (segments[i].start > segments[i+1].end)) & (N > 1)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
    int N;
    cin >> N;
    Segment segments[N];
    for (int i = 0; i < N; i++){
        cin >> segments[i].start >> segments[i].end;
    }
    check(N, segments);
    return 0;
}