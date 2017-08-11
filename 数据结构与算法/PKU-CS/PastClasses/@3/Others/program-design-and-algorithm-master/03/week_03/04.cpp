#include <iostream>
#include <iomanip>
using namespace std;

class Warrios {
public:
	virtual int getHP() = 0;
	virtual int getNum() = 0;
	virtual void incNum() = 0;
};

class Dragon: public Warrios {
public:
	static int hp;
	int num = 0;
	int getHP() {
		return hp;
	};
	int getNum() {
		return num;
	};
	void incNum() {
		num++;
	};
};
int Dragon::hp = 0;

class Ninja : public Warrios {
public:
	static int hp;
	int num = 0;
	int getHP() {
		return hp;
	};
	int getNum() {
		return num;
	};
	void incNum() {
		num++;
	};
};
int Ninja::hp = 0;

class Iceman : public Warrios {
public:
	static int hp;
	int num = 0;
	int getHP() {
		return hp;
	};
	int getNum() {
		return num;
	};
	void incNum() {
		num++;
	};
};
int Iceman::hp = 0;

class Lion : public Warrios {
public:
	static int hp;
	int num = 0;
	int getHP() {
		return hp;
	};
	int getNum() {
		return num;
	};
	void incNum() {
		num++;
	};
};
int Lion::hp = 0;

class Wolf : public Warrios {
public:
	static int hp;
	int num = 0;
	int getHP() {
		return hp;
	};
	int getNum() {
		return num;
	};
	void incNum() {
		num++;
	};
};
int Wolf::hp = 0;

void printRedWarrios(Warrios ** p, Warrios * w[]) {
	switch (p - w)
	{
	case 0:
		cout << " iceman ";
		break;
	case 1:
		cout << " lion ";
		break;
	case 2:
		cout << " wolf ";
		break;
	case 3:
		cout << " ninja ";
		break;
	case 4:
		cout << " dragon ";
		break;
	}
}

void printBlueWarrios(Warrios ** p, Warrios * w[]) {
	switch (p - w)
	{
	case 0:
		cout << " lion ";
		break;
	case 1:
		cout << " dragon ";
		break;
	case 2:
		cout << " ninja ";
		break;
	case 3:
		cout << " iceman ";
		break;
	case 4:
		cout << " wolf ";
		break;
	}
}

int main() {
	int n = 0;
	cin >> n;

	for (int z = 0; z < n; z++)
	{
		// initialize
		int m = 0, redM = 0, blueM = 0, minHP = 0, hp[5] = { 0 };
		bool redStop = false, blueStop = false;
		Dragon redDragon, blueDragon;
		Ninja redNinja, blueNinja;
		Iceman redIceman, blueIceman;
		Lion redLion, blueLion;
		Wolf redWolf, blueWolf;
		Warrios * redWarrios[5] = { &redIceman, &redLion, &redWolf, &redNinja, &redDragon };
		Warrios ** redP = redWarrios;
		Warrios * blueWarrios[5] = { &blueLion, &blueDragon, &blueNinja, &blueIceman, &blueWolf };
		Warrios ** blueP = blueWarrios;
		cin >> m;
		for (int i = 0; i < 5; i++)
		{
			cin >> hp[i];
			if (i == 0)
				minHP = hp[i];
			else if (hp[i] < minHP)
				minHP = hp[i];
		}
		redM = m;
		blueM = m;
		Dragon::hp = hp[0];
		Ninja::hp = hp[1];
		Iceman::hp = hp[2];
		Lion::hp = hp[3];
		Wolf::hp = hp[4];

		cout << "Case:" << z + 1 << endl;

		// loop print
		int n = 0;
		while (!redStop || !blueStop) 
		{
			// loop red
			if (redM < minHP)
			{
				if (!redStop)
				{
					cout << setw(3) << setfill('0') << n << " red headquarter stops making warriors" << endl;
					redStop = true;
				}
			} 
			else
			{
				// m > current warrios' hp
				bool print = false;
				while (!print)
				{
					if (redM >= (**redP).getHP())
					{
						redM -= (**redP).getHP();
						// warrios num++
						(*redWarrios[redP - redWarrios]).incNum();

						// print
						cout << setw(3) << setfill('0') << n << " red";
						printRedWarrios(redP, redWarrios);
						cout << n + 1 << " born with strength " << (**redP).getHP() << ',' << (**redP).getNum();
						printRedWarrios(redP, redWarrios);
						cout << "in red headquarter" << endl;

						// mark printed
						print = true;
					}
					// move pointer
					redP++;
					if (redP > &redWarrios[4])
						redP = redWarrios;
				}
			}


			// blue loop
			if (blueM < minHP)
			{
				if (!blueStop)
				{
					cout << setw(3) << setfill('0') << n << " blue headquarter stops making warriors" << endl;
					blueStop = true;
				}
			}
			else
			{
				// m > current warrios' hp
				bool print = false;
				while (!print)
				{
					if (blueM >= (**blueP).getHP())
					{
						blueM -= (**blueP).getHP();
						// warrios num++
						(*blueWarrios[blueP - blueWarrios]).incNum();

						// print
						cout << setw(3) << setfill('0') << n << " blue";
						printBlueWarrios(blueP, blueWarrios);
						cout << n + 1 << " born with strength " << (**blueP).getHP() << ',' << (**blueP).getNum();
						printBlueWarrios(blueP, blueWarrios);
						cout << "in blue headquarter" << endl;

						// mark printed
						print = true;
					}
					// move pointer
					blueP++;
					if (blueP > &blueWarrios[4])
						blueP = blueWarrios;
				}
			}

			n++;
		}
	}
	return 0;
};