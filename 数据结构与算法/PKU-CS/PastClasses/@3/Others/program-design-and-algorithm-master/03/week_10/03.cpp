int sum(int a[], int n, int(*sqr)(int)) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += sqr(a[i]);
	}
	return sum;
}