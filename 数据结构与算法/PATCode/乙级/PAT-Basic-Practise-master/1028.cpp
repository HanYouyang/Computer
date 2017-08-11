#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string name;
	int yy, mm, dd, num = 0;
	int maxyear = 0, maxmonth = 0, maxday = 0;
	int minyear = 9999, minmonth = 9999, minday = 9999;
	string maxname, minname;
	for(int i = 0; i < n; i++){
		cin >> name;
		scanf("%d/%d/%d", &yy, &mm, &dd);
		if((yy < 2014 || (yy == 2014 && mm < 9) || (yy == 2014 && mm == 9 && dd <= 6)) &&
            (yy > 1814 || (yy == 1814 && mm > 9) || (yy == 1814 && mm == 9 && dd >= 6))) {
        	++num;
        	if(yy > maxyear || (yy == maxyear && mm > maxmonth) || (yy == maxyear && mm == maxmonth && dd > maxday)) {
                maxyear = yy;
                maxmonth = mm;
                maxday = dd;
                maxname = name;
            }
            if(yy < minyear || (yy == minyear && mm < minmonth) || (yy == minyear && mm == minmonth && dd < minday)) {
                minyear = yy;
                minmonth = mm;
                minday = dd;
                minname = name;
            }
		}
	}
	cout << num;
	if(num != 0)
		cout << " " << minname << " " << maxname;
	cout << endl;
	return 0;
}
