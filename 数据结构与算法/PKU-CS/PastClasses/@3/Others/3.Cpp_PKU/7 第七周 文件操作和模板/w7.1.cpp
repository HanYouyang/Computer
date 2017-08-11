#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
class CStudent {
public:
	char szName[20];
	int nScore;
};

int main(int argc, char * argv[]) {
	CStudent s;
	ofstream OutFile("F:\\Moocs\\程序设计实习  Practice on Programming\\Cpp-codes-and-projects-PKU\\Courseware\\7 第七周 文件操作和模板\\data.dat", ios::out | ios::binary);
	while (cin >> s.szName >> s.nScore){
		if (stricmp(s.szName, "exit") == 0)
			break;
		OutFile.write((char*)&s, sizeof(s));
	}
	OutFile.close();

	ifstream inFile("F:\\1.dat", ios::in | ios::binary);
	if (!inFile){
		cout << "error" << endl;
		return 0;
	}
	while (inFile.read((char*)&s, sizeof(s))){
		int nReadBytes = inFile.gcount();
		cout << s.szName << " " << s.nScore << endl;
	}
	inFile.close();
	return 0;
}