#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class  A{
private:
    int getPrime(int num);
public:
    int origin, n;
    A(int num):origin(num){
        n = getPrime(num);
    }
    bool operator<(const A & a){
        if(n>a.n) return true;
        else if(n==a.n) return origin>a.origin;
        else return false;
    }

};

int A::getPrime(int num) {
    int tem, sum = 0;
    tem = num;
    for(int i = 2;i <= num;++i)
    {
        if(num % i == 0 && tem != i)
        {
            sum++;
            while(num % i == 0)
                num = num / i;
        }
    }
    return sum;
}


class MyLess{
public:
    bool operator()(const A& a1, const A& a2){
        if(a1.n>a2.n) return true;
        else if(a1.n==a2.n) return a1.origin>a2.origin;
        else return false;
    }
};


int main()
{
    deque<A> input;
    int n, num;
    cin >> n;
    for(int i = 0; i<n; i++){
        for (int j = 0; j<10; j++){
            cin >> num;
            input.push_back(A(num));
        }
        sort(input.begin(), input.end(), MyLess());
        cout << input.front().origin << " " <<input.back().origin << endl;
        input.pop_back();
        input.pop_front();
    }
    return 0;

}