#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Warrios {
public:
	virtual int getHP() = 0;
};

class Dragon : public Warrios {
private:
	int hp;
	int weapon1;
	double morale;
public:
	Dragon(int h, int w1, double m) : hp(h), weapon1(w1), morale(m) {};
	int getHP() {
		return hp;
	};
};

class Ninja : public Warrios {
private:
	int hp;
	int weapon1;
	int weapon2;
public:
	Ninja(int h, int w1, int w2) : hp(h), weapon1(w1), weapon2(w2) {};
	int getHP() {
		return hp;
	};
};

class Iceman : public Warrios {
private:
	int hp;
	int weapon1;
public:
	Iceman(int h, int w1) : hp(h), weapon1(w1) {};
	int getHP() {
		return hp;
	};
};

class Lion : public Warrios {
private:
	int hp;
	int loyalty;
public:
	Lion(int h, int l) : hp(h), loyalty(l) {};
	int getHP() {
		return hp;
	};
};

class Wolf : public Warrios {
private:
	int hp;
public:
	Wolf(int h) : hp(h) {};
	int getHP() {
		return hp;
	};
};

int main() {
	int n = 0;
	cin >> n;

	string weapon[3] = {"sword", "bomb", "arrow"};

	for (int z = 0; z < n; z++)
	{
		// initialize
		int m = 0, minHP = 0, hp[5] = { 0 };
		int redM = 0, blueM = 0;
		bool redStop = false, blueStop = false;

		string warrios[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
		int redOrder[5] = { 2, 3, 4, 1, 0 }, blueOrder[5] = { 3, 0, 1, 2, 4 };
		int *redP = redOrder, *blueP = blueOrder;
		int redNum[5] = { 0 }, blueNum[5] = { 0 };
		vector <Warrios *> redWarrios, blueWarrios;

		cin >> m; // initial life

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

		cout << "Case:" << z + 1 << endl;

		// loop print
		int n = 1;
		while (!redStop || !blueStop)
		{
			// loop red
			if (redM < minHP)
			{
				if (!redStop)
				{
					cout << setw(3) << setfill('0') << n - 1 << " red headquarter stops making warriors" << endl;
					redStop = true;
				}
			}
			else
			{
				// m > current warrios' hp
				bool print = false;
				while (!print)
				{
					// M > ph, generate new warriot
					if (redM >= hp[*redP])
					{
						// decrease M
						redM -= hp[*redP];
						// increase corresponding warriots' num
						redNum[*redP]++;

						// print warriot
						cout << setw(3) << setfill('0') << n - 1 << " red " << warrios[*redP] << " " << n << " born with strength " << hp[*redP] << ',' << redNum[*redP] << " " << warrios[*redP] << " in red headquarter" << endl;
						
						// create warriot
						double morale = (double)redM / (double)hp[*redP];
						int weapon1 = n % 3;
						int weapon2 = (n + 1) % 3;
						int loyalty = redM;
						switch (*redP)
						{
						case 0:
//							redWarrios.push_back(&Dragon(hp[*redP], weapon1, morale));
							cout << "It has a " << weapon[n % 3] << ",and it's morale is " << setiosflags(ios::fixed) << setprecision(2) << morale << endl;
							break;
						case 1:
//							redWarrios.push_back(&Ninja(hp[*redP], weapon1, weapon2));
							cout << "It has a " << weapon[weapon1] << " and a " << weapon[weapon2] << endl;
							break;
						case 2:
//							redWarrios.push_back(&Iceman(hp[*redP], weapon1));
							cout << "It has a " << weapon[weapon1] << endl;
							break;
						case 3:
//							redWarrios.push_back(&Lion(hp[*redP], loyalty));
							cout << "It's loyalty is " << loyalty << endl;
							break;
						case 4:
//							redWarrios.push_back(&Wolf(hp[*redP]));
							break;
						}

						// mark printed
						print = true;
					}
					// move pointer
					redP++;
					if (redP > &redOrder[4])
						redP = redOrder;
				}
			}


			// blue loop
			if (blueM < minHP)
			{
				if (!blueStop)
				{
					cout << setw(3) << setfill('0') << n - 1 << " blue headquarter stops making warriors" << endl;
					blueStop = true;
				}
			}
			else
			{
				// m > current warrios' hp
				bool print = false;
				while (!print)
				{
					// M > ph, generate new warriot
					if (blueM >= hp[*blueP])
					{
						// decrease M
						blueM -= hp[*blueP];
						// increase corresponding warriots' num
						blueNum[*blueP]++;

						// print warriot
						cout << setw(3) << setfill('0') << n - 1 << " blue " << warrios[*blueP] << " " << n << " born with strength " << hp[*blueP] << ',' << blueNum[*blueP] << " " << warrios[*blueP] << " in blue headquarter" << endl;

						// create warriot
						double morale = (double)blueM / (double)hp[*blueP];
						int weapon1 = n % 3;
						int weapon2 = (n + 1) % 3;
						int loyalty = blueM;
						switch (*blueP)
						{
						case 0:
//							blueWarrios.push_back(&Dragon(hp[*blueP], weapon1, morale));
							cout << "It has a " << weapon[n % 3] << ",and it's morale is " << setiosflags(ios::fixed) << setprecision(2) << morale << endl;
							break;
						case 1:
//							blueWarrios.push_back(&Ninja(hp[*blueP], weapon1, weapon2));
							cout << "It has a " << weapon[weapon1] << " and a " << weapon[weapon2] << endl;
							break;
						case 2:
//							blueWarrios.push_back(&Iceman(hp[*blueP], weapon1));
							cout << "It has a " << weapon[weapon1] << endl;
							break;
						case 3:
//							blueWarrios.push_back(&Lion(hp[*blueP], loyalty));
							cout << "It's loyalty is " << loyalty << endl;
							break;
						case 4:
//							blueWarrios.push_back(&Wolf(hp[*blueP]));
							break;
						}

						// mark printed
						print = true;
					}
					// move pointer
					blueP++;
					if (blueP > &blueOrder[4])
						blueP = blueOrder;
				}
			}

			n++;
		}
	}
	return 0;
};