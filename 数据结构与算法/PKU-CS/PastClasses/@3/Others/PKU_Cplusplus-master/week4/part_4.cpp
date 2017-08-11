Number & operator *(const Number & n){
    num = num * n.num;
    return *this;
}
operator int(){
    return num;
}