
class A {
public:
	static int count;
	A() { count++; }
	A(int a) { count++; }
	virtual ~A() {
		cout << "A::destructor" << endl;
	}
	void operator delete(void *a) {
		count--;
	}
};
class B :public A {
public:
	B() :A() {}
	B(int b) :A() {}
	B &operator=(B &b) {
		return b;
	}
	virtual ~B() {
		cout << "B::destructor" << endl;
	}
};

