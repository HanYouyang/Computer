// W5-�����ҵ-ħ������֮����װ��.cpp : Defines the entry point for the console application.
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

int wlf[5];//dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ
//string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string wpname[3] = { "sword","bomb","arrow" };//������

class Warrior
{
	int life;
	string name;

public:
	Warrior(int lf = 0, string nm="wolf") :life(lf),name(nm) {}

	string get_name()
	{
		return name;
	}

	int get_life()
	{
		return life;
	}
};

class Drag :public Warrior
{
	int wpno;//�������
	double morale;//ʿ��

public:
	Drag() {}

	Drag(int lf, int no, double hd_sx_lf) :wpno(no%3), morale(hd_sx_lf/lf), Warrior(lf, "dragon") //��һ����������������Ԫ,�ڶ��������Ǳ��,������������˾�ʣ������Ԫ
	{}

	void show()
	{
		cout << "It has a " << wpname[wpno] << ",and it's morale is ";
		cout.setf(ios_base::fixed, ios_base::floatfield);//����ʹ�ö����ʾ��
		cout.precision(2);//���ڶ����ʾ��������Ϊ2��ʾС�������2λ��һֱ��Ч
		cout<< morale << endl;
	}

};

class Nin :public Warrior
{
	int wpno1;
	int wpno2;

public:
	Nin(){}
	Nin(int lf, int no) :wpno1(no%3), wpno2((no+1)%3), Warrior(lf, "ninja") {}//��һ����������ʿ������Ԫ���ڶ�������������

	void show()
	{
		cout << "It has a "<<wpname[wpno1]<<" and a "<<wpname[wpno2] << endl;
	}
};

class Ice :public Warrior
{
	int wpno;

public:
	Ice(){}
	Ice(int lf, int no) :wpno(no%3), Warrior(lf, "iceman") {}

	void show()
	{
		cout << "It has a "<<wpname[wpno] << endl;
	}
};

class Lion :public Warrior
{
	int loyalty;//�ҳ϶�

public:
	Lion(){}
	Lion(int lf, int hd_sx_lf) :loyalty(hd_sx_lf), Warrior(lf, "lion") {}

	void show()
	{
		cout << "It's loyalty is "<<loyalty << endl;
	}
};

class HeadQ
{
	int lifen;//����Ԫ
	int wno;//��ʿ�������
	int worrior[5];//5����ʿ���ε�����
	string name;
	bool stop;//�Ƿ�ֹͣ������ʿ

public:
	HeadQ(int lfn = 0, string snm = "") :lifen(lfn), wno(0), name(snm), stop(0)
	{
		memset(worrior, 0, sizeof(worrior));
	}

	bool gen_wr(int time, int k)//�������Ϊk����ʿ
	{
		if (lifen < wlf[k])
		{
			return false;
		}
		wno++;
		worrior[k]++;
		lifen = lifen - wlf[k];//ʣ������Ԫ
		
		if (0 == k)
		{
			Drag drg(wlf[k],wno,lifen);
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout <<time << " " << name << " " << drg.get_name() << " " << wno << " born with strength " << drg.get_life()
				<<","<<worrior[k] <<" "<<drg.get_name()<<" in "<<name<<" headquarter" << endl;
			drg.show();
		}
		else if (1 == k)
		{
			Nin nnj(wlf[k],wno);
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout << time << " " << name << " " << nnj.get_name() << " " << wno << " born with strength " << nnj.get_life()
				<< "," << worrior[k] << " " << nnj.get_name() << " in " << name << " headquarter" << endl;
			nnj.show();
		}
		else if (2 == k)
		{
			Ice icm(wlf[k],wno);
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout << time << " " << name << " " << icm.get_name() << " " << wno << " born with strength " << icm.get_life()
				<< "," << worrior[k] << " " << icm.get_name() << " in " << name << " headquarter" << endl;
			icm.show();
		}
		else if (3 == k)
		{
			Lion lon(wlf[k],lifen);
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout << time << " " << name << " " << lon.get_name() << " " << wno << " born with strength " << lon.get_life()
				<< "," << worrior[k] << " " << lon.get_name() << " in " << name << " headquarter" << endl;
			lon.show();
		}
		else if (4 == k)
		{
			//û���ر��
			Warrior wlf(wlf[k]);
			cout.fill('0');//��������ַ���һֱ��Ч
			cout.width(3);//�����Ϊ3��һ����Ч
			cout << time << " " << name << " " << wlf.get_name() << " " << wno << " born with strength " << wlf.get_life()
				<< "," << worrior[k] << " " << wlf.get_name() << " in " << name << " headquarter" << endl;
		}
		return true;
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

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cout << "Case:" << i << endl;
		int m;
		cin >> m;
		cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
		HeadQ redhq(m, "red");//�췽��iceman��lion��wolf��ninja��dragon˳��:2,3,4,1,0
		HeadQ bluehq(m, "blue");//������lion��dragon��ninja��iceman��wolf˳��:3,0,1,2,4
		int redsx[5] = { 2, 3, 4, 1, 0 };
		int bluesx[5] = { 3, 0, 1, 2, 4 };

		int time = 0;
		int redk = 0;
		int bluek = 0;
		while (redhq.getstopflag() == false || bluehq.getstopflag() == false)
		{
			while (redhq.getstopflag() == false && redhq.is_stop(time) == false && redhq.gen_wr(time, redsx[redk]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ
			{
				redk = (redk + 1) % 5;
			}
			redk = (redk + 1) % 5;

			while (bluehq.getstopflag() == false && bluehq.is_stop(time) == false && bluehq.gen_wr(time, bluesx[bluek]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ
			{
				bluek = (bluek + 1) % 5;
			}
			bluek = (bluek + 1) % 5;

			time++;
		}
	}
	return 0;
}



