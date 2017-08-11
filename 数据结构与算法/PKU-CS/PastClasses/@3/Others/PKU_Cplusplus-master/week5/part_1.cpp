#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// ??????е????
class MyString : public string{
public:
    MyString() {};
    MyString(const char * ch) :string(ch) {};
    MyString(const MyString& ms):string(ms){};
    MyString & operator()(int l, int r){
        string str = substr(l, r);
        return *new MyString(str.c_str());
    }
    MyString operator +(MyString & str){
        string str1 = *this;
        string str2 = str;
        string str3 = str1 + str2;
        return *new MyString(str3.c_str());
    }
    MyString & operator +(const char * ch){
        string str1 = *this;
        string str = str1 + ch;
        return *new MyString(str.c_str());
    }

};
MyString operator+(const char * ch1, MyString & ch2){
    string str = ch2;
    string s = ch1 + str;
    return *new MyString(s.c_str());
}



int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 ) return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3; s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1; s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //???s1???±?0????????4?????
    cout << s1(0,4) << endl;
    //???s1???±??5????????10?????
    cout << s1(5,10) << endl;
    return 0;
}