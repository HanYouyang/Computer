#include<iostream>
using namespace std;

class Base {

	public:

		int val;

		Base()

			{ cout << "Base Constructor" << endl; }

		~Base()

			{ cout << "Base Destructor" << endl;}

};
class Base1:virtual public Base { };

class Base2:virtual public Base { };

class Derived:public Base1, public Base2 { };
int main(){
	Derived d;
	return 0;
}
