#include <iostream>
using namespace std;

template <class T>
class CArray3D{
public:
    const int x, y, z;
    T *** array;

    CArray3D(const int a=0, const int b=0, const int c=0):x(a),y(b),z(c){
        if((a||b||c) == 0){
            array = NULL;
            return;
        }
        array =  new T ** [a];
        for (int i=0; i<a; i++){
            array[i] = new T * [b];
            for (int j=0; j<b; j++){
                array[i][j] = new T[c];
            }
        }
        return ;
    }
    T ** & operator[](int a){
        return array[a];
    }

    ~CArray3D(){
        delete array;
    }

};



int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}