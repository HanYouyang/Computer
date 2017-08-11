#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>//reverse����������ӵ�ͷ�ļ�
using namespace std;

class BigInt
{
private:
	string values;//��������λ�ϵ�����
	bool flag;//true��ʾ������false��ʾ������0Ĭ��Ϊ����
	inline int compare(string s1, string s2)
	{
		if (s1.size() < s2.size())
			return -1;
		else if (s1.size() > s2.size())
			return 1;
		else
			return s1.compare(s2);
	}
public:
	BigInt() :values("0"), flag(true) {};
	BigInt(string str)//����ת�����캯��(Ĭ��Ϊ������)
	{
		values = str;
		flag = true;
	}
public:
	friend ostream& operator << (ostream& os, const BigInt& bigInt);//�������������
	friend istream& operator >> (istream& is, BigInt& bigInt);//�������������
	BigInt operator+(const BigInt& rhs);//�ӷ���������
	BigInt operator-(const BigInt& rhs);//������������
	BigInt operator*(const BigInt& rhs);//�˷���������
	BigInt operator/(const BigInt& rhs);//������������
};
/*
��������ȡ�����'>>'�����һ������
*/
ostream& operator << (ostream& os, const BigInt& bigInt)
{
	if (!bigInt.flag)
	{
		os << '-';
	}
	os << bigInt.values;
	return os;
}
/*
���������������'>>'������һ��������
*/
istream& operator >> (istream& is, BigInt& bigInt)
{
	string str;
	is >> str;
	bigInt.values = str;
	bigInt.flag = true;
	return is;
}
/*
�������������
*/
BigInt BigInt::operator+(const BigInt& rhs)
{
	BigInt ret;
	ret.flag = true;//��������Ӻ�Ϊ����
	string lvalues(values), rvalues(rhs.values);
	//�����������
	if (lvalues == "0")
	{
		ret.values = rvalues;
		return ret;
	}
	if (rvalues == "0")
	{
		ret.values = lvalues;
		return ret;
	}
	//����s1��s2�ĳ���
	unsigned int i, lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	if (lsize < rsize)
	{
		for (i = 0; i < rsize - lsize; i++)//��lvalues��߲���
		{
			lvalues = "0" + lvalues;
		}
	}
	else
	{
		for (i = 0; i < lsize - rsize; i++)//��rvalues��߲���
		{
			rvalues = "0" + rvalues;
		}
	}
	//���������
	int n1, n2;
	n2 = 0;
	lsize = lvalues.size();
	string res = "";
	reverse(lvalues.begin(), lvalues.end());//�ߵ��ַ������Է���ӵ�λ�������
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < lsize; i++)
	{
		n1 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) % 10;//n1����ǰλ��ֵ
		n2 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) / 10;//n2�����λ
		res = res + char(n1 + '0');
	}

	if (n2 == 1)
	{
		res = res + "1";
	}
	reverse(res.begin(), res.end());

	ret.values = res;
	return ret;
}
/*
�������������
*/
BigInt BigInt::operator-(const BigInt& rhs)
{
	BigInt ret;
	string lvalues(values), rvalues(rhs.values);
	//�����������
	if (rvalues == "0")
	{
		ret.values = lvalues;
		ret.flag = true;
		return ret;
	}
	if (lvalues == "0")
	{
		ret.values = rvalues;
		ret.flag = false;
		return ret;
	}
	//����s1��s2�ĳ���
	unsigned int i, lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	if (lsize < rsize)
	{
		for (i = 0; i < rsize - lsize; i++)//��lvalues��߲���
		{
			lvalues = "0" + lvalues;
		}
	}
	else
	{
		for (i = 0; i < lsize - rsize; i++)//��rvalues��߲���
		{
			rvalues = "0" + rvalues;
		}
	}
	//����ʹ��-����ǰ�ߵ������ں�ߵ���
	int t = lvalues.compare(rvalues);//��ȷ���0��str1<str2���ظ�����str1>str2��������
	if (t < 0)
	{
		ret.flag = false;
		string tmp = lvalues;
		lvalues = rvalues;
		rvalues = tmp;
	}
	else if (t == 0)
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}
	else
	{
		ret.flag = true;
	}
	//���������
	unsigned int j;
	lsize = lvalues.size();
	string res = "";
	reverse(lvalues.begin(), lvalues.end());//�ߵ��ַ������Է���ӵ�λ�������
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < lsize; i++)
	{
		if (lvalues[i] < rvalues[i])//���㣬��ǰ��һά
		{
			j = 1;
			while (lvalues[i + j] == '0')
			{
				lvalues[i + j] = '9';
				j++;
			}
			lvalues[i + j] -= 1;
			res = res + char(lvalues[i] + ':' - rvalues[i]);
		}
		else
		{
			res = res + char(lvalues[i] - rvalues[i] + '0');
		}
	}
	reverse(res.begin(), res.end());
	res.erase(0, res.find_first_not_of('0'));//ȥ��ǰ����

	ret.values = res;
	return ret;
}
/*
�������������
*/
BigInt BigInt::operator*(const BigInt& rhs)
{
	BigInt ret;
	string lvalues(values), rvalues(rhs.values);
	//�����������
	if (lvalues == "0" || rvalues == "0")
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}

	unsigned int lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	string temp;
	BigInt res, itemp;
	//��lvalues�ĳ����
	if (lvalues < rvalues)
	{
		temp = lvalues;
		lvalues = rvalues;
		rvalues = temp;
		lsize = lvalues.size();
		rsize = rvalues.size();
	}
	//���������
	int i, j, n1, n2, n3, t;
	reverse(lvalues.begin(), lvalues.end());//�ߵ��ַ���
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < rsize; i++)
	{
		temp = "";
		n1 = n2 = n3 = 0;
		for (j = 0; j < i; j++)
		{
			temp = temp + "0";
		}
		n3 = rvalues[i] - '0';
		for (j = 0; j < lsize; j++)
		{
			t = (n3*(lvalues[j] - '0') + n2);
			n1 = t % 10;//n1��¼��ǰλ�õ�ֵ
			n2 = t / 10;//n2��¼��λ��ֵ
			temp = temp + char(n1 + '0');
		}
		if (n2)
		{
			temp = temp + char(n2 + '0');
		}
		reverse(temp.begin(), temp.end());
		itemp.values = temp;
		res = res + itemp;
	}

	ret = res;
	return ret;
}
/*
�������������
*/
BigInt BigInt::operator/(const BigInt& rhs)
{
	BigInt ret;
	string lvalues(values), rvalues(rhs.values);
	string quotient;
	//�����������
	if (rvalues == "0")
	{
		ret.values = "error";//�������
		ret.flag = true;
		return ret;
	}
	if (lvalues == "0")
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}

	if (compare(lvalues, rvalues) < 0)
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}
	else if (compare(lvalues, rvalues) == 0)
	{
		ret.values = "1";
		ret.flag = true;
		return ret;
	}
	else
	{
		//���������
		string temp;
		unsigned int lsize, rsize;
		lsize = lvalues.size();
		rsize = rvalues.size();
		int i;
		if (rsize > 1) temp.append(lvalues, 0, rsize - 1);
		for (i = rsize - 1; i < lsize; i++)
		{
			temp = temp + lvalues[i];
			//����
			for (char c = '9'; c >= '0'; c--)
			{
				BigInt t = (BigInt)rvalues * (BigInt)string(1, c);
				BigInt s = (BigInt)temp - t;

				if (s.flag == true)
				{
					temp = s.values;
					quotient = quotient + c;
					break;
				}
			}
		}
	}
	//ȥ��ǰ����
	quotient.erase(0, quotient.find_first_not_of('0'));
	ret.values = quotient;
	ret.flag = true;
	return ret;
}

int main()
{
	BigInt a, b, result;
	char op;
	cin >> a >> op >> b;
	switch (op)
	{
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a * b; break;
	case '/':result = a / b; break;
	default:break;
	}
	cout << result << endl;
	return 0;
}