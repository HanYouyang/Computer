
	Number & operator = (const Number & a) {
		num = a.num;
		return *this;
	}

	int & value() {
		return num;
	}

	Number & operator +(const Number & a) {
		num += a.num;
		return *this;
	}
