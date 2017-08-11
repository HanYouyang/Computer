#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class A {
    private:
        int n;
    public:
        A(int n_){n = n_;}
        friend bool operator < (const A & a1, const A & a2);
        friend bool operator == (const A & a1, const A & a2)
        friend ostream & operator << (ostream & o, const A & a);
};
bool operator <(const A & a1, const A & a2){
    return a1.n < a2.n;
}
bool operator == (const A & a1, const A & a2){
    return a1.n == a2.n;
}
ostream & operator << (ostream & o, const A & a){
    o << a.n;
    return o;
}
template <class T>
void Print (T first, T last)
{
    for(; first != last; ++first)
        cout << *first << " ";
    cout << endl;
}
int main(){
    A a[5] = {1,3,2,4,2};
    A b[7] = {10, 30, 20, 30, 30, 40, 40};
    list<A>lst1(a, a+5), lst2(b, b+7);
    lst1.sort();
    cout << "1)";Print(lst1.begin(), lst1.end());
    lst1.remove(2);
    cout << "2)";Print(lst1.begin(), lst1.end());
    lst2.pop_front();
    cout << "3)";Print(lst2.begin(), lst2.end());
    lst2.unique();
    cout << "4)";Print(lst2.begin(), lst2.end());
    lst2.sort();
    lst1.merge(lst2);
    cout << "5)";Print(lst1.begin(), lst1.end());
    cout << "6)";Print(lst2.begin(), lst2.end());
    lst1.reverse();
    cout << "7)";Print(lst1.begin(), lst1.end());
    lst2.insert(lst2.begin(), a+1, a+4);
    list<A>::iterator p1, p2, p3;
    p1 = find(lst1.begin(), lst1.end(), 30);
    p2 = find(lst2.begin(), lst2.end(), 2);
    p3 = find(lst2.begin(), lst2.end(), 4);
    lst1.splice(p1, lst2, p2,p3);
    cout << "8)";Print(lst1.begin(), lst1.end());
    cout << "9)";Print(lst2.begin(), lst2.end());
    return 0;
}