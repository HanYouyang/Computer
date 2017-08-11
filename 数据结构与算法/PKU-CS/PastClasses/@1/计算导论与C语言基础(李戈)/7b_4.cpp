#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int n100 = n / 100; n100 >= 0; n100--) {
		for (int n50 = (n - n100 * 100) / 50; n50 >= 0; n50--) {
			for (int n20 = (n - n100 * 100 - n50 * 50) / 20; n20 >= 0; n20--) {
				for (int n10 = (n - n100 * 100 - n50 * 50 - n20 * 20) / 10; n10 >= 0; n10--) {
					for (int n5 = (n - n100 * 100 - n50 * 50 - n20 * 20 - n10 * 10); n5 >= 0; n5--) {
						for (int n1 = n - n100 * 100 - n50 * 50 - n20 * 20 - n10 * 10 - n5; n1 >= 0; n1--) {
							if (100 * n100 + 50 * n50 + 20 * n20 + 10 * n10 + 5 * n5 + n1 == n) {
							    cout << n100<< endl;
								cout << n50 << endl;
								cout << n20 << endl;
								cout << n10 << endl;
								cout << n5 << endl;
								cout << n1 << endl;
							    goto here;					
						    }
					    } 				 
					}
				}
			}
		}
	}
	here:
	return 0;	
}
