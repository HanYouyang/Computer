#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Student {
	private:
		string name, id;
		unsigned age, score[4];
	
	    friend inline ostream & operator <<(ostream &os, Student &st) {
		    unsigned sum = 0;
		    for (int i = 0; i < 4; i++){
			    sum += st.score[i];
		    }
		    os << st.name<<","<<st.age<<","<<st.id<<","<< sum/4;
		    return os;
	    }
	    
	    friend inline istream & operator >>(istream &is, Student &st) {
		    string tmp;
		    getline(is, st.name,',');
		    getline(is, tmp,',');
		    istringstream(tmp)>>st.age;
		    getline(is, st.id,',');

		    for (int i = 0; i < 3; i++) {
			    getline(is, tmp, ',');
			    istringstream(tmp) >> st.score[i];
		    }
			getline(is, tmp);
		    istringstream(tmp) >> st.score[3];
		    return is; 
	    }	
};

int main() {
	Student student;
	cin >> student;
	cout << student << endl;
	return 0;
}
