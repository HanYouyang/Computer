#include <iostream>
using namespace std;
 
int main() {
    char s1[80], s2[80];
    cin.getline(s1,80);
    cin.getline(s2,80);
    
    int i = 0;
    while (s1[i] != '\0') {
    	if (s1[i] >= 'A' && s1[i] <= 'Z') {
    		s1[i] = s1[i] + 'a' - 'A';
		}  
		i = i + 1;  	
	}
	i = 0;
	while (s2[i] != '\0') {
    	if (s2[i] >= 'A' && s2[i] <= 'Z') {
    		s2[i] = s2[i] + 'a' - 'A';
		} 
		i = i + 1;   	
	}
	
    i = 0;
    char result;
    while (s1[i] != '\0' && (s1[i] == s2[i])){
        i = i + 1;
    }
    if (s1[i] > s2[i]) {
        result = '>';
    } else if (s1[i] < s2[i]) {
        result = '<';
    } else{
        result = '=';
    }
    
    cout << result << endl;
    
    return 0;
}
