#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	unordered_map<int, int> hash;
	int N;
	cin >> N;
	int temp;
	for(int i=0; i<N; i++){
		cin >> temp;
		if(hash.find(temp) != hash.end()){
			hash[temp]++;
		} else {
			hash[temp] = 1;
		}
	}
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> temp;
		if(hash.find(temp) != hash.end()){
			cout << hash[temp];
		} else {
			cout << "0";
		}
		if(i != N-1){
			cout << " ";
		}
	}
	return 0;
}
