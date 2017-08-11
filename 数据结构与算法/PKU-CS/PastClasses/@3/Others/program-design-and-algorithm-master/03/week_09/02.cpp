template<class T>
class CMyistream_iterator {
private:
	T val;
	istream & c;
public:
	CMyistream_iterator(istream & _cin) : c(_cin) {
		c >> val;
	};
	void operator ++(int) {
		c >> val;
	}
	T operator *() {
		return val;
	}
};