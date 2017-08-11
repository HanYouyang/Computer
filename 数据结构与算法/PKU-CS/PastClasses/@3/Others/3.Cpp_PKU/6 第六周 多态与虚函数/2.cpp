#include <iostream>

using namespace std;

class A {

	public :

	virtual ~A() {cout<<"DestructA" <<endl; }

};

class B: public A {

	public:

	virtual ~B() {cout<<"DestructB" << endl;	}

};

class C: public B {

	public:

		~C() { cout <<"DestructC" << endl; }

};

int main() {

	A * pa = new C;

	delete pa; A a;
	return 0;

}