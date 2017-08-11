
class CMy_add {
public:
	int &my_sum;
	CMy_add(int &n) : my_sum(n) {};
	void operator() (int & v) {
		my_sum += (v % 8);
	}

};
