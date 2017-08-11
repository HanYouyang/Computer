Number operator * (Number & n) const {
	return Number(num * n.num);
}
operator int() {
	return num;
}