

bool operator < (const class A& a1, const class A &a2) {
	return a1.get_size() < a2.get_size();
}

template <class T>
class MyLarge{
public:
	bool operator() (const class A& a1, const class A &a2) {
		return a1.get_name() < a2.get_name();
	}
};

template <class Iterator, class Function>
void Show(Iterator b, Iterator e, Function print) {
	for (Iterator i = b; i != e; i++) {
		print(*i);
	}
}
class Print {
public:
	void operator() (const A &a) {
		cout << a.get_name() << ' ';
	}
};

