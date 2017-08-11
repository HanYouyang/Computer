#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        if (n == 0) {
        	break;
		}
        int a[n];
        for(int i = 0; i < n; i++) {
        	cin >> a[i];
		}
            
        int tmp = 0, mid = 0;
        int flag = 0;        
        for(int i=0; i<n; i++){
            int cl = 0, cr = 0, cq = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] > a[j]) {
                	cl = cl + 1;
				} else if (a[i] <a [j]) {
					cr = cr + 1;
				} else {
					cq = cq + 1;
				}
            }
            if ((cl + cq > n / 2) && (cq + cr > n / 2)) {
        	    mid = a[i]; 
			    break;
		    } else if ((n % 2 == 0) && ((cl + cq == n / 2) || (cq + cr == n / 2))) {
                if(flag==0) {
                    tmp = tmp + a[i];
                    flag=1;
			    }   
                if (flag == 1 && tmp !=a [i]) {
            	    tmp = tmp + a[i];
            	    break;
			    }                
            }
        }
        cout << (mid ? mid : tmp / 2) << endl;
    }    
    return 0;
}
