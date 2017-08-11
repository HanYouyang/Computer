#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int g_cityNum = 0;
int g_arrowAtt = 0;
int g_lionLoyaltyDecrease = 0;
int g_blueInRed = 0;
int g_redInBlue = 0;
int g_redM = 0;
int g_blueM = 0;
bool g_gameOver = false;
ofstream outfile("mine.txt");

void logTime(int h, int m) {
	cout << setw(3) << setfill('0') << h << ":" << setw(2) << m << " ";
	outfile << setw(3) << setfill('0') << h << ":" << setw(2) << m << " ";
}

class Warriors {
public:
	int color;
	string colorText;
	string type;
	int no;
	int hp;
	int att;
	int swordAtt;
	bool hasBomb;
	int arrowNum;
	int city;
	int loyalty;
	bool stop;

	Warriors() {};
	Warriors(int c, int n);
	virtual void born() {
		cout << colorText << " " << type << " " << no << " born" << endl;
	 outfile << colorText << " " << type << " " << no << " born" << endl;
	}
	void attack(Warriors * enemy, bool ifPassive, int h, int m) {
		// print event
		logTime(h, m);
		if (!ifPassive)
		{
			cout << colorText << " " << type << " " << no << " attacked " << enemy->colorText << " " << enemy->type << " " << enemy->no << " in city " << city << " with " << hp << " elements and force " << att << endl;
		 outfile << colorText << " " << type << " " << no << " attacked " << enemy->colorText << " " << enemy->type << " " << enemy->no << " in city " << city << " with " << hp << " elements and force " << att << endl;
		}
		else
		{
			cout << colorText << " " << type << " " << no << " fought back against " << enemy->colorText << " " << enemy->type << " " << enemy->no << " in city " << city << endl;
		 outfile << colorText << " " << type << " " << no << " fought back against " << enemy->colorText << " " << enemy->type << " " << enemy->no << " in city " << city << endl;
		}

		int enemyHP = (enemy->type == "lion") ? enemy->hp : 0;
		// attack
		enemy->defence(this, ifPassive, h, m);

		// if has sword, blunt it
		if (swordAtt > 0)
			swordAtt *= 0.8;

		// after attack, if die
		if (hp <= 0)
			return;
		// if enemy die, get enemy's hp
		if (enemy->hp <= 0)
			hp += enemyHP;
	};
	void defence(Warriors * enemy, bool ifPassive, int h, int m) {
		// attacked
		int harm = enemy->att + enemy->swordAtt;
		if (ifPassive)
			harm = enemy->att / 2 + enemy->swordAtt;

		hp = (hp - harm > 0) ? hp - harm : 0;

		// if die
		if (hp == 0)
		{
			logTime(h, m);
			cout << colorText << " " << type << " " << no << " was killed in city " << city << endl;
		 outfile << colorText << " " << type << " " << no << " was killed in city " << city << endl;
			return;
		}

		// beat back, when back is false
		if (!ifPassive && type != "ninja")
			attack(enemy, true, h, m);
	};
	virtual void triumph(Warriors * enemy, bool ifPassive, int h, int m) {};
	virtual void fail(bool passive, int h, int m) {};
	virtual void flee(int h, int m) {};
	virtual void move(int c) {
		city = c;
	}
	void getCityM(int cityM, int h, int m) {
		if (color == 0)
			g_redM += cityM;
		else
			g_blueM += cityM;

		logTime(h, m);
		cout << colorText << " " << type << " " << no << " earned " << cityM << " elements for his headquarter" << endl;
	 outfile << colorText << " " << type << " " << no << " earned " << cityM << " elements for his headquarter" << endl;
	}
	void fireArrow(Warriors * enemy) {
		arrowNum = (arrowNum - 1 > 0) ? --arrowNum : 0;
		if (enemy->hp == 0)
		{
			cout << colorText << " " << type << " " << no << " shot and killed " << enemy->colorText << " " << enemy->type << " " << enemy->no << endl;
		 outfile << colorText << " " << type << " " << no << " shot and killed " << enemy->colorText << " " << enemy->type << " " << enemy->no << endl;
		}
		else
		{
			cout << colorText << " " << type << " " << no << " shot" << endl;
		 outfile << colorText << " " << type << " " << no << " shot" << endl;
		}
	}
	void useBomb(Warriors * enemy, int h, int m) {
		logTime(h, m);
		cout << colorText << " " << type << " " << no << " used a bomb and killed " << enemy->colorText << " " << enemy->type << " " << enemy->no << endl;
	 outfile << colorText << " " << type << " " << no << " used a bomb and killed " << enemy->colorText << " " << enemy->type << " " << enemy->no << endl;
		delete this;
		delete enemy;
	}
	void reportWeapon(int h, int m) {
		int weaponNum = 0;
		if (swordAtt > 0)
			weaponNum++;
		if (hasBomb)
			weaponNum++;
		if (arrowNum > 0)
			weaponNum++;

		logTime(h, m);
		cout << colorText << " " << type << " " << no << " has ";
	 outfile << colorText << " " << type << " " << no << " has ";
		if (weaponNum == 0)
		{
			cout << "no weapon";
		 outfile << "no weapon";
		}
		else if (weaponNum == 1)
		{
			if (arrowNum > 0)
			{
				cout << "arrow(" << arrowNum << ")";
			 outfile << "arrow(" << arrowNum << ")";
			}
			else if (hasBomb)
			{
				cout << "bomb";
			 outfile << "bomb";
			}
			else
			{
				cout << "sword(" << swordAtt << ")";
			 outfile << "sword(" << swordAtt << ")";
			}
		}
		else
		{
			if (arrowNum > 0)
			{
				cout << "arrow(" << arrowNum << "),";
			 outfile << "arrow(" << arrowNum << "),";
			}
			if (hasBomb)
			{
				cout << "bomb";
			 outfile << "bomb";
			}
			if (swordAtt > 0)
			{
				if (hasBomb)
				{
					cout << ",";
				 outfile << ",";
				}
				cout << "sword(" << swordAtt << ")";
			 outfile << "sword(" << swordAtt << ")";
			}
		}
		cout << endl;
	 outfile << endl;
	}
};
Warriors::Warriors(int c, int n) {
	color = c;
	colorText = (c == 0) ? "red" : "blue";
	no = n;
	hp = 0;
	att = 0;
	swordAtt = 0;
	hasBomb = false;
	arrowNum = 0;
	city = (color == 0) ? 0 : g_cityNum + 1;
	loyalty = 0;
	stop = false;
}

class Dragon : public Warriors {
private:
	static int HP;
	static int ATT;
public:
	double morale;

	Dragon(int c, int n);
	static void initHP(int l) { HP = l; };
	static void initATT(int a) { ATT = a; };
	void born() {
		cout << colorText << " " << type << " " << no << " born" << endl;
	 outfile << colorText << " " << type << " " << no << " born" << endl;
		cout << "Its morale is " << fixed << setprecision(2) << morale << endl;
	 outfile << "Its morale is " << fixed << setprecision(2) << morale << endl;
	}
	void triumph(Warriors * enemy, bool passive, int h, int m) {
		morale += 0.2;
		if (!passive && morale > 0.8)
		{
			logTime(h, m);
			cout << colorText << " " << type << " " << no << " yelled in city " << city << endl;
		 outfile << colorText << " " << type << " " << no << " yelled in city " << city << endl;
		}
	}
	void fail(bool passive, int h, int m) {
		morale = (morale - 0.2 > 0) ? morale - 0.2 : 0;
		if (!passive && morale > 0.8)
		{
			logTime(h, m);
			cout << colorText << " " << type << " " << no << " yelled in city " << city << endl;
		 outfile << colorText << " " << type << " " << no << " yelled in city " << city << endl;
		}
	};
};
int Dragon::HP = 0;
int Dragon::ATT = 0;
Dragon::Dragon(int c, int n) : Warriors(c, n) {
	hp = HP;
	att = ATT;
	type = "dragon";
	morale = ((c == 0) ? (double)g_redM : (double)g_blueM) / (double)HP;
	switch (no % 3)
	{
	case 0:
		swordAtt = ATT * 0.2;
		break;
	case 1:
		hasBomb = true;
		break;
	case 2:
		arrowNum = 3;
		break;
	};
}

class Ninja : public Warriors {
private:
	static int HP;
	static int ATT;
public:
	Ninja(int c, int n);
	static void initHP(int l) { HP = l; };
	static void initATT(int a) { ATT = a; };
};
int Ninja::HP = 0;
int Ninja::ATT = 0;
Ninja::Ninja(int c, int n) : Warriors(c, n) {
	hp = HP;
	att = ATT;
	type = "ninja";
	switch (no % 3)
	{
	case 0:
		swordAtt = ATT * 0.2;
		break;
	case 1:
		hasBomb = true;
		break;
	case 2:
		arrowNum = 3;
		break;
	};
	switch ((no + 1) % 3)
	{
	case 0:
		swordAtt = ATT * 0.2;
		break;
	case 1:
		hasBomb = true;
		break;
	case 2:
		arrowNum = 3;
		break;
	};
}

class Iceman : public Warriors {
private:
	static int HP;
	static int ATT;
	int step = 0;
public:
	Iceman(int c, int n);
	static void initHP(int l) { HP = l; };
	static void initATT(int a) { ATT = a; };
	void move(int c) {
		step++;
		if (step > 0 && step % 2 == 0)
		{
			hp = (hp - 9 > 0) ? hp - 9 : 1;
			att += 20;
		}
		city = c;
	}
};
int Iceman::HP = 0;
int Iceman::ATT = 0;
Iceman::Iceman(int c, int n) : Warriors(c, n) {
	hp = HP;
	att = ATT;
	type = "iceman";
	switch (no % 3)
	{
	case 0:
		swordAtt = ATT * 0.2;
		break;
	case 1:
		hasBomb = true;
		break;
	case 2:
		arrowNum = 3;
		break;
	};
}

class Lion : public Warriors {
private:
	static int HP;
	static int ATT;
public:
	Lion(int c, int n);
	static void initHP(int l) { HP = l; };
	static void initATT(int a) { ATT = a; };
	void born() {
		cout << colorText << " " << type << " " << no << " born" << endl;
	 outfile << colorText << " " << type << " " << no << " born" << endl;
		cout << "Its loyalty is " << loyalty << endl;
	 outfile << "Its loyalty is " << loyalty << endl;
	}
	void fail(bool passive, int h, int m) {
		loyalty -= g_lionLoyaltyDecrease;
		loyalty = (loyalty > 0) ? loyalty : 0;
	};
	void flee(int h, int m) {
		logTime(h, m);
		cout << colorText << " lion " << no << " ran away" << endl;
	 outfile << colorText << " lion " << no << " ran away" << endl;
	};
};
int Lion::HP = 0;
int Lion::ATT = 0;
Lion::Lion(int c, int n) : Warriors(c, n) {
	hp = HP;
	att = ATT;
	type = "lion";
	loyalty = (c == 0) ? g_redM : g_blueM;
}

class Wolf : public Warriors {
private:
	static int HP;
	static int ATT;
public:
	Wolf(int c, int n);
	static void initHP(int l) { HP = l; };
	static void initATT(int a) { ATT = a; };
	void triumph(Warriors * enemy, bool passive, int h, int m) {
		if (swordAtt == 0)
			swordAtt = enemy->swordAtt;
		if (!hasBomb)
			hasBomb = enemy->hasBomb;
		if (arrowNum == 0)
			arrowNum = enemy->arrowNum;
	}
};
int Wolf::HP = 0;
int Wolf::ATT = 0;
Wolf::Wolf(int c, int n) : Warriors(c, n) {
	hp = HP;
	att = ATT;
	type = "wolf";
}

class City {
private:
	int m;
	int lastWinner;
public:
	int no;
	int color;
	Warriors * w0;
	Warriors * w1;

	City() : no(-1), color(-1), m(0), lastWinner(-1), w0(NULL), w1(NULL) {};
	void renewCityM() { m += 10; }
	int giveCityM() {
		int tmp = m;
		m = 0;
		return tmp;
	}
	void fireArrow(int h, int m) {
		if (w0 != NULL && no < g_cityNum && w0->arrowNum > 0 && (this + 1)->w1 != NULL)
		{
			logTime(h, m);
			(this + 1)->sufferArrow(0);
			w0->fireArrow((this + 1)->w1);
		}
		if (w1 != NULL && no > 1 && w1->arrowNum > 0 && (this - 1)->w0 != NULL)
		{
			logTime(h, m);
			(this - 1)->sufferArrow(1);
			w1->fireArrow((this - 1)->w0);
		}
	}
	void sufferArrow(int c) {
		if (c == 0 && w1 != NULL)
			w1->hp = (w1->hp - g_arrowAtt > 0) ? w1->hp - g_arrowAtt : 0;
		if (c == 1 && w0 != NULL)
			w0->hp = (w0->hp - g_arrowAtt > 0) ? w0->hp - g_arrowAtt : 0;
	}
	void bomb(int h, int m) {
		// no enemy
		if (w0 == NULL || w1 == NULL || w0->hp == 0 || w1->hp == 0)
			return;

		// red turn
		if (w0 != NULL && w0->hasBomb)
		{
			// red attack
			if (color == 0 || (color == -1 && no % 2 == 1))
			{
				if (w1->hp > (w0->att + w0->swordAtt) && w1->type != "ninja" && w0->hp < (w1->att / 2 + w1->swordAtt))
				{
					w0->useBomb(w1, h, m);
					w0 = NULL;
					w1 = NULL;
					return;
				}
			}
			// blue attack
			else if (w0->hp <= (w1->att + w1->swordAtt))
			{
				w0->useBomb(w1, h, m);
				w0 = NULL;
				w1 = NULL;
				return;
			}
		}

		// blue turn
		if (w1 != NULL && w1->hasBomb)
		{
			// blue attack
			if (color == 1 || (color == -1 && no % 2 == 0))
			{
				if (w0->hp > (w1->att + w1->swordAtt) && w0->type != "ninja" && w1->hp < (w0->att / 2 + w0->swordAtt))
				{
					w1->useBomb(w0, h, m);
					w0 = NULL;
					w1 = NULL;
					return;
				}
			}
			// red attack
			else if (w1->hp <= (w0->att + w0->swordAtt))
			{
				w1->useBomb(w0, h, m);
				w0 = NULL;
				w1 = NULL;
				return;
			}
		}
	}
	void fight(int h, int m) {
		// no enemy, no fight
		if (w0 == NULL || w1 == NULL)
			return;
		// both died
		if (w0->hp == 0 && w1->hp == 0)
		{
			w0 = NULL;
			w1 = NULL;
			return;
		}

		// who is passive
		bool w0Pass = true, w1Pass = true;
		if (color == 0 || (color == -1 && no % 2 == 1))
			w0Pass = false;
		else
			w1Pass = false;

		// both alive, fight
		if (w0->hp > 0 && w1->hp > 0)
		{
			if (!w0Pass)
				w0->attack(w1, w0Pass, h, m);
			else
				w1->attack(w0, w1Pass, h, m);
		}

		// blue died
		if (w1->hp == 0)
		{
			w0->triumph(w1, w0Pass, h, m);
			w0->getCityM(giveCityM(), h, m);
			if (lastWinner == 0 && color != 0)
				riseFlag(0, h, m);
			lastWinner = 0;
		}
		// red died
		else if (w0->hp == 0)
		{
			w1->triumph(w0, w1Pass, h, m);
			w1->getCityM(giveCityM(), h, m);
			if (lastWinner == 1 && color != 1)
				riseFlag(1, h, m);
			lastWinner = 1;
		}
		// no one died
		else
		{
			w0->fail(w0Pass, h, m);
			w1->fail(w1Pass, h, m);
			lastWinner = -1;
		}
	}
	void riseFlag(int color, int h, int m) {
		this->color = color;
		string colorText = (color == 0) ? "red" : "blue";
		logTime(h, m);
		cout << colorText << " flag raised in city " << no << endl;
	 outfile << colorText << " flag raised in city " << no << endl;
	}
	void handleRedWarriorsMove(int h, int m) {
		City * last = this - 1;
		if (last->w0 != NULL)
		{
			//logTime(h, m);
			w0 = last->w0;
			last->w0 = NULL;
			w0->move(no);

			if (this->no == g_cityNum + 1)
				g_redInBlue++;
		}
	}
	void handleBlueWarriorsMove(int h, int m) {
		City * last = this + 1;
		if (last->w1 != NULL)
		{
			w1 = last->w1;
			last->w1 = NULL;
			w1->move(no);

			if (this->no == 0)
				g_blueInRed++;
		}
	}
	void reportM(int color) {
		if (color == 0)
		{
			cout << g_redM << " elements in red headquarter" << endl;
		 outfile << g_redM << " elements in red headquarter" << endl;
		}
		else
		{
			cout << g_blueM << " elements in blue headquarter" << endl;
		 outfile << g_blueM << " elements in blue headquarter" << endl;
		}
	}
};

void clock(int add, int & t, int & h, int & m) {
	t += add;
	h = t / 60;
	m = t % 60;
}

int main() {
	int n = 0, c = 1;
	cin >> n;

	while (c <= n)
	{
		// reset global variable
		g_cityNum = 0;
		g_arrowAtt = 0;
		g_lionLoyaltyDecrease = 0;
		g_blueInRed = 0;
		g_redInBlue = 0;
		g_redM = 10;
		g_blueM = 10;
		g_gameOver = false;

		// initialize
		int M = 0, tm = 0, hp[5] = { 0 }, att[5] = { 0 };
		string Warriors[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
		int redOrder[5] = { 2, 3, 4, 1, 0 }, blueOrder[5] = { 3, 0, 1, 2, 4 };
		int *redP = redOrder, *blueP = blueOrder;
		// input M, N, R, K, T
		cin >> M >> g_cityNum >> g_arrowAtt >> g_lionLoyaltyDecrease >> tm;
		g_redM = M;
		g_blueM = M;
		City * cities = new City[g_cityNum + 2];
		for (int i = 0; i <= g_cityNum + 1; i++)
		{
			cities[i].no = i;
		}
		// input Warriors' hp
		for (int i = 0; i < 5; i++)
		{
			cin >> hp[i];
		}
		// input Warriors' attack
		for (int i = 0; i < 5; i++)
		{
			cin >> att[i];
		}

		Dragon::initHP(hp[0]);
		Ninja::initHP(hp[1]);
		Iceman::initHP(hp[2]);
		Lion::initHP(hp[3]);
		Wolf::initHP(hp[4]);
		Dragon::initATT(att[0]);
		Ninja::initATT(att[1]);
		Iceman::initATT(att[2]);
		Lion::initATT(att[3]);
		Wolf::initATT(att[4]);

		City & redHQ = cities[0];
		City & blueHQ = cities[g_cityNum + 1];
		redHQ.color = 0;
		blueHQ.color = 1;

		cout << "Case " << c << ":" << endl;
	 outfile << "Case " << c << ":" << endl;

		// loop print, time cycle
		int h = 0, m = 0, t = 0, redRound = 1, blueRound = 1;
		while (true)
		{
			// get hour and minutes
			clock(0, t, h, m);

			// 00 generate Warriors
			if (m == 0)
			{
				// red headquarter
				if (g_redM >= hp[*redP])
				{
					logTime(h, m);
					// decrease red m
					g_redM -= hp[*redP];
					// generate warrio
					switch (*redP)
					{
					case 0:
						cities[0].w0 = new Dragon(0, redRound);
						cities[0].w0->born();
						break;
					case 1:
						cities[0].w0 = new Ninja(0, redRound);
						cities[0].w0->born();
						break;
					case 2:
						cities[0].w0 = new Iceman(0, redRound);
						cities[0].w0->born();
						break;
					case 3:
						cities[0].w0 = new Lion(0, redRound);
						cities[0].w0->born();
						break;
					case 4:
						cities[0].w0 = new Wolf(0, redRound);
						cities[0].w0->born();
						break;
					}
					redRound++;
					// move redP
					*redP++;
					if (redP > &redOrder[4])
						redP = redOrder;
				}
				// blue headquarter
				if (g_blueM >= hp[*blueP])
				{
					logTime(h, m);
					// decrease red m
					g_blueM -= hp[*blueP];
					// generate warrio
					switch (*blueP)
					{
					case 0:
						cities[g_cityNum + 1].w1 = new Dragon(1, blueRound);
						cities[g_cityNum + 1].w1->born();
						break;
					case 1:
						cities[g_cityNum + 1].w1 = new Ninja(1, blueRound);
						cities[g_cityNum + 1].w1->born();
						break;
					case 2:
						cities[g_cityNum + 1].w1 = new Iceman(1, blueRound);
						cities[g_cityNum + 1].w1->born();
						break;
					case 3:
						cities[g_cityNum + 1].w1 = new Lion(1, blueRound);
						cities[g_cityNum + 1].w1->born();
						break;
					case 4:
						cities[g_cityNum + 1].w1 = new Wolf(1, blueRound);
						cities[g_cityNum + 1].w1->born();
						break;
					}
					blueRound++;
					// move redP
					*blueP++;
					if (blueP > &blueOrder[4])
						blueP = blueOrder;
				}
			}
			
			clock(5, t, h, m);
			if (t > tm)
				break;

			// 05 lion flee
			if (m == 5)
			{
				if (redHQ.w0 != NULL && redHQ.w0->type == "lion" && redHQ.w0->loyalty == 0)
				{
					redHQ.w0->flee(h, m);
					redHQ.w0 = NULL;
				}
				if (blueHQ.w1 != NULL && blueHQ.w1->type == "lion" && blueHQ.w1->loyalty == 0)
				{
					blueHQ.w1->flee(h, m);
					blueHQ.w1 = NULL;
				}
				for (int i = 1; i <= g_cityNum; i++)
				{
					if (cities[i].w0 != NULL && cities[i].w0->type == "lion" && cities[i].w0->loyalty == 0)
					{
						cities[i].w0->flee(h, m);
						cities[i].w0 = NULL;
					}
					if (cities[i].w1 != NULL && cities[i].w1->type == "lion" && cities[i].w1->loyalty == 0)
					{
						cities[i].w1->flee(h, m);
						cities[i].w1 = NULL;
					}
				}
			}

			clock(5, t, h, m);
			if (t > tm)
				break;

			// 10 move
			if (m == 10)
			{
				for (int i = g_cityNum + 1; i > 0; i--)
					cities[i].handleRedWarriorsMove(h, m);
				for (int i = 0; i < g_cityNum + 1; i++)
					cities[i].handleBlueWarriorsMove(h, m);

				// print
				if (redHQ.w1 != NULL)
				{
					if (!redHQ.w1->stop)
					{
						logTime(h, m);
						cout << redHQ.w1->colorText << " " << redHQ.w1->type << " " << redHQ.w1->no << " reached red headquarter with " << redHQ.w1->hp << " elements and force " << redHQ.w1->att << endl;
					 outfile << redHQ.w1->colorText << " " << redHQ.w1->type << " " << redHQ.w1->no << " reached red headquarter with " << redHQ.w1->hp << " elements and force " << redHQ.w1->att << endl;
						redHQ.w1->stop = true;
					}
					// if taken, game over
					if (g_blueInRed == 2)
					{
						logTime(h, m);
						cout << "red headquarter was taken" << endl;
					 outfile << "red headquarter was taken" << endl;
						g_gameOver = true;
					}
				}
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					if (cities[i].w0 != NULL)
					{
						logTime(h, m);
						cout << cities[i].w0->colorText << " " << cities[i].w0->type << " " << cities[i].w0->no << " marched to city " << cities[i].w0->city << " with " << cities[i].w0->hp << " elements and force " << cities[i].w0->att << endl;
					 outfile << cities[i].w0->colorText << " " << cities[i].w0->type << " " << cities[i].w0->no << " marched to city " << cities[i].w0->city << " with " << cities[i].w0->hp << " elements and force " << cities[i].w0->att << endl;
					}
					if (cities[i].w1 != NULL)
					{
						logTime(h, m);
						cout << cities[i].w1->colorText << " " << cities[i].w1->type << " " << cities[i].w1->no << " marched to city " << cities[i].w1->city << " with " << cities[i].w1->hp << " elements and force " << cities[i].w1->att << endl;
					 outfile << cities[i].w1->colorText << " " << cities[i].w1->type << " " << cities[i].w1->no << " marched to city " << cities[i].w1->city << " with " << cities[i].w1->hp << " elements and force " << cities[i].w1->att << endl;
					}
				}
				if (blueHQ.w0 != NULL)
				{
					if (!blueHQ.w0->stop)
					{
						logTime(h, m);
						cout << blueHQ.w0->colorText << " " << blueHQ.w0->type << " " << blueHQ.w0->no << " reached blue headquarter with " << blueHQ.w0->hp << " elements and force " << blueHQ.w0->att << endl;
					 outfile << blueHQ.w0->colorText << " " << blueHQ.w0->type << " " << blueHQ.w0->no << " reached blue headquarter with " << blueHQ.w0->hp << " elements and force " << blueHQ.w0->att << endl;
						blueHQ.w0->stop = true;
					}
					// if taken, game over immediatelly
					if (g_redInBlue == 2)
					{
						logTime(h, m);
						cout << "blue headquarter was taken" << endl;
					 outfile << "blue headquarter was taken" << endl;
						g_gameOver = true;
					}
				}
			}

			clock(10, t, h, m);
			if (t > tm || g_gameOver)
				break;

			// 20 renew m
			if (m == 20)
			{
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					cities[i].renewCityM();
				}
			}

			clock(10, t, h, m);
			if (t > tm)
				break;

			// 30 take m
			if (m == 30)
			{
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					if (cities[i].w0 != NULL && cities[i].w1 == NULL)
						cities[i].w0->getCityM(cities[i].giveCityM(), h, m);
					else if (cities[i].w1 != NULL && cities[i].w0 == NULL)
						cities[i].w1->getCityM(cities[i].giveCityM(), h, m);
				}
			}

			clock(5, t, h, m);
			if (t > tm)
				break;

			// 35 fire and suffer arrow
			if (m == 35)
			{
				for (int i = 0; i <= g_cityNum + 1; i++)
				{
					cities[i].fireArrow(h, m);
				}
			}

			clock(3, t, h, m);
			if (t > tm)
				break;

			// 38 use bomb
			if (m == 38)
			{
				for (int i = 1; i <= g_cityNum; i++)
				{
					cities[i].bomb(h, m);
				}
			}

			clock(2, t, h, m);
			if (t > tm)
				break;

			// 40 fight
			if (m == 40)
			{
				int redM = g_redM, blueM = g_blueM;
				// fight
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					cities[i].fight(h, m);
				}
				// red winner hp award
				for (int i = g_cityNum; i > 0; i--)
				{
					if (cities[i].w0 == NULL || cities[i].w1 == NULL)
						continue;
					if (cities[i].w1->hp == 0 && redM >= 8)
					{
						cities[i].w0->hp += 8;
						redM -= 8;
						g_redM -= 8;
					}
				}
				// blue winner hp award
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					if (cities[i].w0 == NULL || cities[i].w1 == NULL)
						continue;
					if (cities[i].w0->hp == 0 && blueM >= 8)
					{
						cities[i].w1->hp += 8;
						blueM -= 8;
						g_blueM -= 8;
					}
				}
				// clear died
				for (int i = 1; i < g_cityNum + 1; i++)
				{
					if (cities[i].w0 != NULL && cities[i].w0->hp == 0)
						cities[i].w0 = NULL;
					if (cities[i].w1 != NULL && cities[i].w1->hp == 0)
						cities[i].w1 = NULL;
				}
			}

			clock(10, t, h, m);
			if (t > tm)
				break;

			// 50 city reports
			if (m == 50)
			{
				logTime(h, m);
				redHQ.reportM(0);
				logTime(h, m);
				blueHQ.reportM(1);
			}

			clock(5, t, h, m);
			if (t > tm)
				break;

			// 55 Warriors report
			if (m == 55)
			{
				for (int i = 0; i <= g_cityNum + 1; i++)
				{
					if (cities[i].w0 != NULL)
						cities[i].w0->reportWeapon(h, m);
				}
				for (int i = 0; i <= g_cityNum + 1; i++)
				{
					if (cities[i].w1 != NULL)
						cities[i].w1->reportWeapon(h, m);
				}
			}

			t += 5;
			if (t > tm)
				break;
		}

		// case count
		c++;
	}


	outfile.close();
	return 0;
};