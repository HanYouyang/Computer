#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct mooncake{
    double mount;
    double price;
    double unit;
};

bool comp(mooncake a, mooncake b){
    return b.unit < a.unit;
}

int main()
{
	int N;//月饼种类数<1000
	int D;//市场需求<500
	cin >> N >> D;
	mooncake *m = new mooncake [N];
	
	for(int i=0; i<N; i++){
		cin >> m[i].mount;
	}
		
	for(int i=0; i<N; i++){
		cin >> m[i].price;
	}
	for(int i=0; i<N; i++){
		m[i].unit = m[i].price / m[i].mount;
	}
	sort(m, m+N, comp);
	
	double sum = 0.0;
	for(int i=0; i<N; i++){
		if(m[i].mount < D){
			sum += m[i].price;
		} else {
			sum += m[i].unit * D;
			break;
		}
		D -= m[i].mount;
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << sum << endl;
	
	return 0;
} 
