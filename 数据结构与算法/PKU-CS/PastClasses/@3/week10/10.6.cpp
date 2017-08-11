
class MyString {
public:
	string s;
	bool operator < (MyString & a) {
		return (s < a.s);
	}
	bool operator == (MyString & a) {
		return (s == a.s);
	}
	bool operator > (MyString & a) {
		return (s > a.s);
	}
	MyString(const char * c) {
		s = c;
	}
	MyString() {
		s = "";
	}
	MyString & operator + (MyString & a) {
		MyString * c = new MyString;
		c->s = s + a.s;
		return *c;
	}
	MyString & operator += (MyString & a) {
		s += a.s;
		return *this;
	}
	char & operator[] (int n) {
		return s[n];
	}
	string & operator() (int a, int b) {
		string * c = new string;
		*c = s.substr(a, b);
		return *c;
	}
};

ostream & operator << (ostream & o, MyString & m) {
	o << m.s;
	return o;
}
MyString & operator + (MyString & m, char * c) {
	MyString * a = new MyString;
	MyString * b = new MyString;
	*a = c;
	b->s = m.s + a->s;
	return *b;
}
MyString & operator += (MyString & m, char * c) {
	m = m + c;
	return m;
}
MyString & operator + (char * c, MyString & m) {
	MyString * a = new MyString;
	MyString * b = new MyString;
	*a = c;
	b->s = a->s + m.s;
	return *b;
}

