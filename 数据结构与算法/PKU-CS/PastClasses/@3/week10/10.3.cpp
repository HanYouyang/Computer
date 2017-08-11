

int sum(int * a, int n, int (*sqr) (int n) ) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += sqr(*(a + i));
	}
	return count;
}

