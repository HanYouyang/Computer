#include<iostream>
#include<fstream>
using namespace std;

int puzzle[6][8], press[6][8];
bool guess(){
	int c, r;
	for (r = 1; r<5; r++)
		for (c = 1; c<7; c++)
			press[r + 1][c] = (puzzle[r][c] + press[r][c]\
			+ press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
	for (c = 1; c<7; c++)//check row 5 status
		//if((press[5][c-1]+press[5][c]+press[5][c+1]\
						//	+press[4][c])%2 != puzzle[5][c])
						if ((puzzle[5][c] + press[5][c] + press[4][c]\
							+ press[5][c - 1] + press[5][c + 1]) % 2 != 0)
							return(false);
	return(true);
}

void enumerate() {
	int c;
	bool success;
	for (c = 1; c<7; c++) //first enumerate cases
		press[1][c] = 0;
	while (guess() == false) {//transverse all first row status
		press[1][1]++;
		c = 1;
		while (press[1][c]>1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}
	return;
}

int main(int argc, char* argv[]){
	if (argc != 3) {
		cout << "File name missing!" << endl;
		return 0;
	}
	int cases, i, r, c,s;
	ifstream inFile(argv[1], ios::binary | ios::in);
	if (!inFile){
		cout << "Source file open error." << endl;
		return 0;
	}
	else
		cout << "Open Source file successfully"<<endl;

	ofstream outFile(argv[2], ios::binary | ios::out);
	if (!outFile){
		cout << "Out file open error." << endl;
		//inFile.close();
		return 0;
	}
	else
		cout << "Open Out file successfully" << endl;
	
	//5*6 -> padded -> 6*8
	cout << "Start reading inputdata" << endl;
	for (r = 0; r<6; r++) //padding column 0 and 7;
		press[r][0] = press[r][7] = 0;
	for (c = 1; c<7; c++) //padding row 0;
		press[0][c] = 0;
	for (r = 1; r < 6; r++) {// read puzzle
		for (c = 1; c < 7; c++){
			inFile >> puzzle[r][c];
			cout<<puzzle[r][c]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Start enumerating..." << endl;
	enumerate();
	cout << "Close inputfile" << endl;
	inFile.close();
	cout << "Start outputing data..." << endl;
	for (r = 1; r<6; r++){
		for (c = 1; c < 7; c++) {
			outFile << press[r][c]<<" ";
			cout << press[r][c] << " ";
		}
		outFile << endl;
		cout << endl;
	}
	cout << "Start outputing data..." << endl;
	outFile.close();
	return 0;
	}
	

