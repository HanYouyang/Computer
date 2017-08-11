class MyString : public string {
public:
	MyString() : string() {};
	MyString(const string s) : string(s) {};
	MyString(MyString & ms) : string(ms) {};
	MyString(const char * chr) : string(chr) {};
	string operator () (int n1, int n2) {
		return this->substr(n1, n2);
	}
};