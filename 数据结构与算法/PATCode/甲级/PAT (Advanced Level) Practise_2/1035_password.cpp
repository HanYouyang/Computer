//2016年2月12日10时16分47秒
//2016年2月12日10时55分12秒
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1010;

struct patinfo{
	string username;
	string password;
	bool modified;
}user[maxn];

bool modifying(struct patinfo &user){
	for(string::iterator it = user.password.begin(); it != user.password.end(); it++){
		if(*it == '1'){ *it = '@'; user.modified = true;}
		else if(*it == '0'){ *it = '%'; user.modified = true;}
		else if(*it == 'l'){ *it = 'L'; user.modified = true;}
		else if(*it == 'O'){ *it = 'o'; user.modified = true;}
	}
	return user.modified;
}

int main()
{
	int n = 0, modifiedNum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> user[i].username >> user[i].password;
		user[i].modified = false;
		if(modifying(user[i])) modifiedNum++;
	}
	if(modifiedNum){
		cout << modifiedNum << endl;
		for(int i = 0; i < n; i++){
			if(user[i].modified)
				cout << user[i].username << ' ' << user[i].password << endl;
		}
	}
	else{
		if(1 == n) cout << "There is 1 account and no account is modified";
		else cout << "There are " << n << " accounts and no account is modified";
	}
	return 0;
}
