#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;
bool isprime(int a) {
    if(a <= 1){
    	return false;
	}
    int Sqrt = (int)sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++){
        if(a % i == 0)
            return false;
    }
    return true;
}
int main()
{
	int n, id;
	cin >> n;
	unordered_map<int, int> m;
	for(int i = 1; i <= n; i++){
		cin >> id;
		m[id] = i;
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> id;
		printf("%04d", id);
		if(m.find(id) != m.end()){
			if(m[id] == 0){
				//所有已查询过的ID排名设为0 
				cout << ": Checked" << endl;
			} else if(m[id] == 1){
				cout << ": Mystery Award" << endl;
			} else if(isprime(m[id])){
				cout << ": Minion" << endl;
			} else {
				cout << ": Chocolate" << endl;
			}
			m[id] = 0;
		} else {
			cout << ": Are you kidding?" << endl;
		}
	}
	return 0;
} 
