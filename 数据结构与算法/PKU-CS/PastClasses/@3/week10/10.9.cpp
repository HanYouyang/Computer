
class A {
public:
	int age;
	string s;
	A(int a) :age(a), s("A") {}
	A(int a, string str) :age(a), s(str) {}
};

class B :public A {
public:
	B(int b) :A(b, "B") {}
};

struct Comp {
	bool operator()(const A* a1, const A* a2) const {
		return a1->age < a2->age;
	}
};

void Print(const A *a) {
	cout << a->s << " " << a->age << endl;
}


