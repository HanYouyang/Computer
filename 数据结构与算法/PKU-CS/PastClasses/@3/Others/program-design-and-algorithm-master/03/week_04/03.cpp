#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
	int **p;
public:
	Array2(const int & a, const int & b) {
		p = new int *[a];
		for (int i = 0; i < b; i++)
		{
			p[i] = new int[b];
		}
	};
	Array2() {

	};
	int * operator [](const int & i) {
		return p[i];
	};
	Array2 & operator = (const int & n) {
		return *this;
	};
	Array2 & operator = (const Array2 & a) {
		p = a.p;
		return *this;
	};
	int operator () (const int & i, const int & j) {
		return p[i][j];
	};
};

ostream & operator << (ostream & o, const Array2 & a) {
	o << a;
	return o;
}

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;
	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
};