
template <class T> 
class CMyistream_iterator{
private:
	istream & is;
	T elem;
public:
	CMyistream_iterator(istream & _cin) : is(_cin) {
		is >> elem;
	}
	T operator * (){
		return elem;
	}
	CMyistream_iterator & operator ++ (int k) {
		is >> elem;
		return *this;
	}
};
