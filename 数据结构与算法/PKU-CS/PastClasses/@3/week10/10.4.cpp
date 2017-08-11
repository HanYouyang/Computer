
class CType {
public:
	int num;
	int operator ++(int k) {
		int m = num;
		num = num * num;
		return m;
	}
	void setvalue(int n) {
		num = n;
	}
};

ostream & operator << (ostream & o, CType & c) {
	o << c.num;
	return o;
}


