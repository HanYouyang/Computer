#include <iostream>

using namespace std;

class A {

	public:

		A( ) { }

		virtual void func()

			{ cout << "A::func"<<endl; }

		virtual void fund( )

			{ cout << "A::fund" << endl; }

		void fun()

			{ cout << "A::fun" << endl;}

};

class B:public A {

	public:

		B ( ) { func( ) ; }

		void fun( ) { func( ) ; }

};

class C : public B {

	public :

		C( ) { }

		void func( )

			{cout << "C::func" << endl; }

		void fund()

			{ cout << "C::fund" << endl;}

};

int main()

{

	A * pa = new B();

	pa->fun();

	B * pb = new C();

	pb->fun();

	return 0;

}

