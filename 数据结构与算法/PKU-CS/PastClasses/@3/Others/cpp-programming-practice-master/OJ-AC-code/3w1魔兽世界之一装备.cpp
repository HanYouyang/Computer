// W3-�����ҵ-ħ������֮1-��ս.cpp : Defines the entry point for the console application.
//

#include <cstdio> 
#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;
//using namespace std;

int wlf[5];//dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ
string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };

class HeadQ
{
	int lifen;//����Ԫ
	int wno;//��ʿ�������
	int worrior[5];//5����ʿ���ε�����
	string name;
	bool stop;//�Ƿ�ֹͣ������ʿ

public :
	HeadQ(int lfn = 0, string snm = "") :lifen(lfn), wno(0), name(snm), stop(0)
	{
		memset(worrior,0,sizeof(worrior));
	}

	bool gen_wr(int time, int k)//���ɱ��Ϊk����ʿ
	{
		if (lifen < wlf[k])
		{
			return false;
		}
		wno++;
		worrior[k]++;
		lifen = lifen - wlf[k];
		cout.fill('0');//��������ַ���һֱ��Ч
		cout.width(3);//�����Ϊ3��һ����Ч
		cout << time << " " << name <<" "<<wrname[k]<< " " << wno << " born with strength " << wlf[k] << ","
			<< worrior[k] << " " << wrname[k] << " in " << name << " headquarter" << endl;
		//������һֱ�����nameʱ������Ϊû��#include<string>����ֱ��using std::string����ȻҲ��������string
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

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;++i)
	{
		cout << "Case:" << i << endl;
		int m;
		cin >> m;
		cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
		HeadQ redhq(m,"red");//�췽��iceman��lion��wolf��ninja��dragon˳��:2,3,4,1,0
		HeadQ bluehq(m,"blue");//������lion��dragon��ninja��iceman��wolf˳��:3,0,1,2,4
		int redsx[5] = {2,3,4,1,0};
		int bluesx[5] = { 3, 0, 1, 2, 4 };

		int time = 0;
		int redk = 0;
		int bluek = 0;
		while (redhq.getstopflag() == false || bluehq.getstopflag() == false)
		{
			while (redhq.getstopflag()==false && redhq.is_stop(time)==false && redhq.gen_wr(time, redsx[redk]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ
			{
				redk = (redk + 1) % 5;
			}
			redk = (redk + 1) % 5;

			while (bluehq.getstopflag()==false && bluehq.is_stop(time)==false && bluehq.gen_wr(time, bluesx[bluek]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ
			{
				bluek = (bluek + 1) % 5;
			}
			bluek = (bluek + 1) % 5;

			time++;
		}
	}
	return 0;
}

