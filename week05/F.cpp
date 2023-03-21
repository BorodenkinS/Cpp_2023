#include <iostream>
#include <cstring>

using namespace std;

char *resize(const char *buf, size_t size, size_t new_size){
    char* puk = new char[new_size];
    for (int i = 0; i < min(size, new_size); i++){
        *(puk + i)  = *(buf + i);
    }
    return puk;
}

int main() {
    char* a = new char[10];
    resize(a, 10, 6);
    delete[] a;
}