class MyString : public string {
public:
	MyString() :string() {};
	MyString(const char *s) :string(s) {};
	MyString(const string &s) :string(s) {};
	MyString operator()(int i, int j) {
		return this->substr(i, j);
	}
};