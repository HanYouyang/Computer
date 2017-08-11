//2017年1月30日11时01分37秒
//2016年1月30日14时41分50秒

//注意一： 在使用cin输入一个整数n再使用getline输入行的情况下
	// 必须使用cin.get()等方法来吸收输入n后的回车
	//这个问题花了三小时
//注意二：string很慢，sstream更慢，最后一组数据差点超时

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct person{
  string name;
  int year;
  int month;
  int day;
}temp;

struct person youngest = {"example", 1814, 9, 6};
struct person oldest = {"example", 2014, 9, 6};

bool isValid(person temp)
{
  int subDay = (2014-temp.year)*360 + (9 - temp.month)*30 + 6 - temp.day;
  int maxDay = (2014-1814)*360;
  return ((subDay >= 0) && (subDay <= maxDay));
}

bool isOlder(person temp)
{
  int subDay = (oldest.year-temp.year)*360 + (oldest.month-temp.month)*30 + oldest.day - temp.day;
  return subDay > 0;
}

bool isYounger(person temp)
{
  int subDay = (youngest.year-temp.year)*360 + (youngest.month-temp.month)*30 + youngest.day - temp.day;
  return subDay < 0;
}

int main()
{
  int n, count = 0;
  string s;
  cin >> n;
  cin.get();//************************************************important
  for(int i = 0; i < n; i++){
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '/')
        s[i] = ' ';
    }
    stringstream ss(s);
    ss >> temp.name;
    ss >> temp.year;
    ss >> temp.month;
    ss >> temp.day;
    if(isValid(temp)){
      count++;
      if(isOlder(temp)){
        oldest = temp;
      }
      if(isYounger(temp)){
        youngest = temp;
      }
    }
  }
  if(count == 0)
  	cout << '0' << endl;
  else
  	cout << count << ' ' << oldest.name << ' ' << youngest.name;
  return 0;
}


// #include <cstdio>
// struct person{
// 	char name[15];
// 	int yy, mm, dd;
// }oldest, youngest, left, right, temp;

// // a <= b return true;
// bool lessEqu(person a, person b){
// 	if(a.yy != b.yy) return a.yy < b.yy;
// 	else if(a.mm != b.mm) return a.mm < b.mm;
// 	else return a.dd <= b.dd;
// }

// // a >= b retrun true;
// bool moreEqu(person a, person b){
// 	if(a.yy != b.yy) return a.yy > b.yy;
// 	else if(a.mm != b.mm) return a.mm > b.mm;
// 	else return a.dd >= b.dd;
// }

// void init(){
// 	youngest.yy = left.yy = 1814;
// 	oldest.yy = right.yy = 2014;
// 	youngest.mm = oldest.mm = left.mm = right.mm = 9;
// 	youngest.dd = oldest.dd = left.dd = right.dd = 6;
// }

// int main(){
// 	init();
// 	int n, num = 0;
// 	scanf("%d", &n);
// 	for(int i = 0; i < n; i++){
// 		scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
// 		if(moreEqu(temp, left) && lessEqu(temp, right)){
// 			num++;
// 			if(lessEqu(temp, oldest))
// 				oldest = temp;
// 			if(moreEqu(temp, youngest))
// 				youngest = temp;
// 		}
// 	}
// 	if(num == 0)
// 		printf("0\n");
// 	else
// 		printf("%d %s %s\n", num, oldest.name, youngest.name);
// 	return 0;
// }
