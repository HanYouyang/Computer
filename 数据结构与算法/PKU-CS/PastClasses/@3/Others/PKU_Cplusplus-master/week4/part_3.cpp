#include <iostream>
#include <cstring>
using namespace std;
class Array2{
    int row;
    int column;
    int ** pArray1;
public:
    Array2(int r=0, int c=0);
    int * & operator[](int r);
    Array2(Array2 & a);
    int &operator()(int r, int c);
    ~Array2();
};

Array2::Array2(int r, int c):row(r),column(c){
    if((r||c) == 0){
        pArray1 = NULL;
        return;
    }
    pArray1 = new int *[r];
    for(int i=0; i<r; ++i){
        pArray1[i] = new int[c];
    }
    return;
}

int* & Array2::operator[](int r) {
    return pArray1[r];
}

Array2::Array2(Array2 &a) {
    if(a.pArray1==NULL){
        pArray1==NULL; row = 0; column = 0;
        return;}
    pArray1 = new int* [a.row];
    for(int i=0; i<a.row; ++i){
        pArray1[i] = new int[a.column];
        memcpy(pArray1[i], a.pArray1[i], sizeof(int)*a.column);
    }
    row = a.row;
    column = a.column;
}

Array2::~Array2() {
    if(pArray1){
        for(int i=0; i<=row; ++i){
            delete [] pArray1[i];
        }
        delete [] pArray1;
    }
}

int& Array2::operator()(int r, int c) {
    if(pArray1){
        return this->operator[](r)[c];
    }
}


int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}