bool operator< (const A& a1, const A &a2) {
	return a1.name.size() < a2.name.size();
};

template <class Iterator, class Function>
void Show(Iterator begin, Iterator end, Function print) {
	for (Iterator iterator1 = begin; iterator1 != end; iterator1++) {
		print(*iterator1);
	}
};

class Print {
public:
	void operator()(const A &a) {
		cout << a.get_name() << " ";
	}
};

template <class A>
struct MyLarge {
	bool operator()(const A &a1, const A &a2) {
		return a1.get_name() < a2.get_name();
	}
};