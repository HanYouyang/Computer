#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex & operator= (string s){
        
        r = double(s[0]- '0');
        i = double(s[2]- '0');
        
        return *this;
    }
};


                        
                        
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    Complex b;
    Complex c;
    c = b = a; c.Print();
    return 0;
}