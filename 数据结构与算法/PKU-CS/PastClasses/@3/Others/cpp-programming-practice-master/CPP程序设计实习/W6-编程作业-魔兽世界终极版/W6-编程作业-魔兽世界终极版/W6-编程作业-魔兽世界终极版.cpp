// W6-�����ҵ-ħ�������ռ���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::ios_base;
//using namespace std;

int wrlf[5];//dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ
int wrgjl[5];//��ʿ�ĳ�ʼ������
//string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string wpname[3] = { "sword", "bomb", "arrow" };//������

//��������
class City
{
	int life;
	int flag;//������ɫ��0Ϊ���죬1Ϊ���죬2Ϊ����
public:
	City(int lf = 0, int fg = 0): life(lf), flag(fg){}

	void setlf(int lf)
	{
		life = lf;
	}

	void setfg(int fg)
	{
		flag = fg;
	}
};

//�������ඨ��
class Weapon
{

};

class Sword :public Weapon
{
	int gjl;
public:
	int getgjl()
	{
		return gjl;
	}
	void biandun()
	{
		gjl = gjl*0.8;
	}
	bool is_lost()//��������Ϊ0ʱ����Ϊʧȥsword
	{
		if (gjl <= 0) return true;
		else return false;
	}

	Sword(){}
	Sword(const Warrior &wr) :gjl()
	{

	}
};

class Arrow :public Weapon
{
	int gjl;
	int sytime;//��ʹ�ô�����ʹ��3�κ󼴱��ľ�
public:
	void increasetime()
	{//����ʹ�ô���
		sytime++;
	}
	bool is_lost()//�Ƿ�ʹ����3�Ρ�ʹ��3�κ󼴱��ľ�
	{
		if (sytime >= 3) return true;
		else return false;
	}
};

class Bomb :public Weapon
{

};

//��ʿ���ඨ��
class Warrior
{
protected:
	int bh;//���
	int life;//����ֵ
	string name;
	int gjl;//������

public:
	Warrior(int bianhao=0, int lf = 0, int gl=0,string nm = "wolf") :bh(bianhao),life(lf), name(nm), gjl(gl) {}

	string get_name()
	{
		return name;
	}

	int get_life()
	{
		return life;
	}

	virtual ~Warrior() {}
};

class Drag :public Warrior
{
	//int wpno;//�������
	Weapon *wpno;
	double morale;//ʿ��

public:
	Drag() {}

	Drag(int no,int lf,int gjl, double hd_sx_lf) :morale(hd_sx_lf / lf), Warrior(no,lf,gjl, "dragon") //��һ����������������Ԫ,�ڶ�����������ʿ���,������������˾�ʣ������Ԫ
	{
		switch (no % 3)
		{
		case 0:
			wpno = new Sword();
			break;
		case 1:
			wpno = new Bomb();
			break;
		case 2:
			wpno = new Arrow();
			break;
		}
	}

	virtual ~Drag()
	{
		delete wpno;
	}

	void increaseml()
	{
		morale += 0.2;
	}

	void decreaseml()
	{
		morale -= 0.2;
	}

	bool is_dead()//����ֵ������0ʱ����ʿ����
	{
		if (get_life() <= 0) return true;
		else return false;
	}

	bool is_huanhu()//�Ƿ񻶺�����������������ιս����ʿ��ֵ����0.8
	{
		if (is_dead() == false && morale > 0.8)  return true;
		else return false;
	}
};

class Nin :public Warrior   //�Ӳ�����
{
	//int wpno1;
	//int wpno2;
	Weapon * wpno[2];

public:
	Nin(){}
	Nin(int no,int lf,int gjl) : Warrior(no,lf,gjl, "ninja")//��һ����������ʿ������Ԫ���ڶ�������������
	{
		switch(no % 3)
		{
		case 0:
			wpno[0] = new Sword();
			wpno[1] = new Bomb();
			break;
		case 1:
			wpno[0] = new Bomb();
			wpno[1] = new Arrow();
			break;
		case 2:
			wpno[0] = new Arrow();
			wpno[1] = new Sword();
		}
	}

	virtual ~Nin()
	{
		delete [] wpno;
	}
};

class Ice :public Warrior
{
	//int wpno;
	Weapon *wp;

public:
	Ice(){}
	Ice(int no, int lf, int gjl) :Warrior(no, lf, gjl, "iceman")
	{
		switch (no%3)
		{
		case 0:
			wp = new Sword();
			break;
		case 1:
			wp = new Bomb();
			break;
		case 2:
			wp = new Arrow();
			break;
		}
	}

	void steptwo()
	{
		//int lf = get_life();
		if (life - 9 <= 0)
		{
			life = 1;
		}
		else{
			life -= 9;
		}
		gjl += 20;
	}
};

class Lion :public Warrior
{
	int loyalty;//�ҳ϶�

public:
	Lion(){}
	Lion(int no,int lf,int gjl,int hd_sx_lf) :loyalty(hd_sx_lf), Warrior(no,lf,gjl, "lion") {}

	void decreaselylt(int k)
	{
		loyalty -= k;
	}

	bool is_escape()//�Ƿ������ܡ��ҳ϶Ƚ���0��0���£�����ս����
	{
		if (loyalty <= 0) return true;
		else return false;
	}
};

class Wolf :public Warrior
{
	Weapon *wp[3];
public :
	Wolf(int no, int lf, int gjl) : Warrior(no, lf, gjl, "Wolf")
	{
		for (int i = 0; i < 3; ++i)
			wp[i] = NULL;
	}

	void jiaohuo(int n)//�ɻ���Ϊn������
	{
		if (wp[i] == NULL)//ֻ�е�û���������ʱ���Ż�ɻ�
		{
			wp[i]
		}
	}
};

class HeadQ
{
	int lifen;//����Ԫ
	int wno;//��ʿ�������
	int worrior[5];//5����ʿ���ε�����
	string name;
	//bool stop;//�Ƿ�ֹͣ������ʿ
	Warrior *wrs[100];//��˾�����ʿ,5000/60<=100
	int len;//���е���ʿ��������wrs�������Ч�±�

public:
	HeadQ(int lfn = 0,string snm = "") :lifen(lfn), wno(0), name(snm), len(0)
	{
		memset(worrior, 0, sizeof(worrior));
	}

	bool is_enough(int k)//����Ԫ�Ƿ��㹻���ɱ��Ϊk����ʿ
	{
		if (lifen < wrlf[k]) return false;
		else return true;
	}

	bool gen_wr(int time, int k)//�������Ϊk����ʿ
	{
		wno++;
		worrior[k]++;
		lifen = lifen - wrlf[k];//ʣ������Ԫ

		if (0 == k)
		{
			wrs[len++] = new Drag(wno,wrlf[k],wrgjl[k],lifen);
		}
		else if (1 == k)
		{
			wrs[len++]=new Nin(wno,wrlf[k],wrgjl[k]);
		}
		else if (2 == k)
		{
			wrs[len++] = new Ice(wno,wrlf[k],wrgjl[k]);
		}
		else if (3 == k)
		{
			wrs[len++] = new Lion(wno,wrlf[k],wrgjl[k],lifen);
		}
		else if (4 == k)
		{
			wrs[len++] = new Wolf(wno,wrlf[k],wrgjl[k]);
			//cout.fill('0');//��������ַ���һֱ��Ч
			//cout.width(3);//�����Ϊ3��һ����Ч
		}
	}

	bool is_stop(int time)
	{
		bool flag = 0;//��־�Ƿ���Լ���������ʿ
		for (int i = 0; i < 5; ++i)
		{
			if (lifen >= wlf[i]) { flag = 1; break; }//ֻҪ����������һ����ʿ
		}
		if (flag == 0)
		{
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout << time << " " << name << " headquarter stops making warriors" << endl;
			stop = true;
			return true;
		}
		return false;
	}

	bool getstopflag(void)
	{
		return stop;
	}
};

City cities[20 + 2];

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case:" << i << endl;
		int m, n, r, k, t;
		cin >> m >> n >> r >> k >> t;
		for (int j = 0; j < 5; ++j)
			cin >> wrlf[j];
		for (int j = 0; j < 5; ++j)
			cin >> wrgjl[j];
		
		HeadQ hdq[2] = {HeadQ(m,"red"),HeadQ(m,"blue")};
		int xhlen1 = 0, xhlen2 = 0;//����˾�������ʿ�����
		int xhxb1[] = { 2, 3, 4, 1, 0 };//������ʿ˳����±�����
		int xhxb2[] = { 3, 0, 1, 2, 4 };
		for(int j = 0; j <= t; j=j+5)//ʱ������
		{
			int minute = j % 60;//����
			if (0 == minute)
			{
				int k1 = xhxb1[xhlen1 % 5];
				if (hdq[0].is_enough(k1))
				{
					hdq[0].gen_wr(k1);
					xhlen1++;
				}
				int k2 = xhxb2[xhlen2 % 5];
				if (hdq[1].is_enough(k2))
				{
					hdq[1].gen_wr(k2);
					xhlen2++;
				}
			}
			else if (5 == minute)
			{
				for (int )
			}
		}
	}
	return 0;
}





