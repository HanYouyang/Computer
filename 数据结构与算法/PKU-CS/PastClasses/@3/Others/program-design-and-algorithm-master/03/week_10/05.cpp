class CMy_add {
private:
	int & sum;
public:
	CMy_add(int & n) : sum(n) {};
	void operator()(int x) {
		while (x >= 8) {
			x -= 8;
		}
		sum += x;
	}
};