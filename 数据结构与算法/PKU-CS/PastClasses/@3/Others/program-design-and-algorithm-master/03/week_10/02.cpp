int & value() {
	return num;
}
void operator + (Number & n) {
	num = num + n.num;
}