
	
	Big(int n) :v(n), b(n) {}
	
	Big(const Big& a) :v(a.v), b(a.b)
	{
		v = a.v;
		b = a.b;
	}

