
	Number & operator* (Number & a) {
		Number * b = new Number();
		b->num = num * a.num;
		return *b;
	}

	operator int() {
		return num;
	}
