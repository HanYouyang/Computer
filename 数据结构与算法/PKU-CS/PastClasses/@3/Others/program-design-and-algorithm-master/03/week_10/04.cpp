class CType {
public:
	int value;
	CType() : value(0) {};
	void setvalue(int n) {
		value = n;
	}
	CType & operator ++ (int) {
		static CType tmp = CType();
		tmp.value = value;
		value *= value;
		return tmp;
	}
};

ostream & operator << (ostream & out, const CType & ct) {
	out << ct.value;
	return out;
};