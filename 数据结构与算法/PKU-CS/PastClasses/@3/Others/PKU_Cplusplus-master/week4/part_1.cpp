#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex & operator=(const string s){
        int index = s.find("+", 0);
        string s_real = s.substr(0, index);
        r = atof(s_real.c_str());
        string s_imagine = s.substr(index+1, s.length()-index-2);
        i = atof(s_imagine.c_str());
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
