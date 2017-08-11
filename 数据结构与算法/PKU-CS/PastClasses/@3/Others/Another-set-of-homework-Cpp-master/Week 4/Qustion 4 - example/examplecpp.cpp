/*
question:       A:�������ļӼ��˳�;
��ʱ������: 1000ms �ڴ�����: 65536kB;
����;
���������������Լ����������������+ - * /������������;

����;
��һ�У�������a�����Ȳ�����100;
�ڶ��У����������o��o�ǡ�+������-������*������/���е�ĳһ��;
�����У�������b�����Ȳ�����100;

��֤���벻������Ŀո�������ַ�;
���;
һ�У����ʽ��a o b����ֵ��;

����˵����;
1. ��������п���Ϊ����;
2. �����������ȡ��;
3. ��������ճ���дϰ�ߣ������ж����0���ո�������ַ�;6
��������;
9876543210
+
9876543210
�������;
19753086420
description��    ���Գ���Ϊ0����������жϣ����������������Ƿ�Ϊ���������ж�;
author:         No.20;
time:           2014��3��24��17:33:18;
**/

#include <iostream>     
#include <fstream>  
#include <string>  
#include <cstring>  
using namespace std;

const static int MAXSIZE = 202;

class BigInteger
{
public:
	// ���캯��;  
	BigInteger(const char* str);

public:
	// ���������;  
	BigInteger operator+ (const BigInteger& bi);
	BigInteger operator- (const BigInteger& bi);
	BigInteger operator* (const BigInteger& bi);
	BigInteger operator/ (const BigInteger& bi);
	BigInteger& operator= (const BigInteger& bi);
	bool operator< (const BigInteger& bi);
	bool operator> (const BigInteger& bi);
	bool operator== (const BigInteger& bi);
	bool operator!= (const BigInteger& bi);
	friend ostream& operator<< (ostream& o, const BigInteger& bi);
	friend istream& operator>> (istream& i, BigInteger& bi);

private:
	// ��Ա����;  
	char str[MAXSIZE];              // �ַ�������;  
	int iVal[MAXSIZE];              // ��������;  
	bool bNeg;                      // ��Ǹ���;  
	int size;                       // ���λ��;  

private:
	// ��������;  
	void intToCahr(BigInteger* bi); // ��������ֵת��Ϊ�ַ���;  
};

BigInteger::BigInteger(const char* str = "")
{
	// ��ʼ����Ա����;  
	memset(this->str, 0, MAXSIZE*sizeof(char));
	memset(this->iVal, 0, MAXSIZE*sizeof(int));
	bNeg = false;
	this->size = strlen(str);
	if (str != "")   // str����ǿյľͲ��ø�ֵ��;  
	{
		// �洢�ַ�����;  
		memcpy(this->str, str, this->size);
		// ��ת�ַ����飬�洢������������;  
		for (int i = 0; i<size; i++)
		{
			this->iVal[i] = static_cast<int>(this->str[size - i - 1] - '0');
		}
	}

}

BigInteger BigInteger::operator+ (const BigInteger &bi)
{
	BigInteger biTemp;
	// �����������Ϊ0��ֱ�ӷ���0;  
	if (!strcmp(this->str, "0") && !strcmp(bi.str, "0"))
	{
		return "0";
	}

	// �������ĺ�Ϊ����,Ĭ��;  
	// ȡ������������󳤶�,���ܳ��ֽ�λ������ȡ���ֵ��1;  
	biTemp.size = (this->size > bi.size ? this->size : bi.size) + 1;

	// ִ����Ӳ���;  
	for (int i = 0; i<biTemp.size; i++)
	{
		biTemp.iVal[i] += iVal[i] + bi.iVal[i];
		// �Խ�λ���в���;  
		if (i + 1 != MAXSIZE)
		{
			// ��֤��λ��Խ��;  
			biTemp.iVal[i + 1] += biTemp.iVal[i] / 10;
		}
		// ����С��10�Ĳ���;  
		biTemp.iVal[i] = biTemp.iVal[i] % 10;
	}
	// ת��;  
	intToCahr(&biTemp);

	return biTemp;
}

BigInteger BigInteger::operator- (const BigInteger& bi)
{
	BigInteger biTemp;
	// ���ñ�־λ�����������Ĵ�С�����ж�;  
	int flag = 0;
	// ͨ�������ж�;  
	if (this->size > bi.size)
	{
		flag = 1;
	}
	else if (this->size < bi.size)
	{
		flag = -1;
	}
	else
	{
		// ͨ����С�ж�;  
		flag = strcmp(this->str, bi.str);
	}

	// ֵ���ʱֱ�ӷ���0;  
	if (0 == flag)
	{
		return "0";
	}
	// �������ȼ�����;  
	else if (flag > 0)
	{
		// ��ĳ������ٺͱ�������ͬ;  
		biTemp.size = this->size;
		// ���;  
		for (int i = 0; i<biTemp.size; i++)
		{
			biTemp.iVal[i] += this->iVal[i] - bi.iVal[i];
			// ������С��0����תΪ����,�����һλ��һ;  
			if (biTemp.iVal[i] < 0)
			{
				if (i + 1 != MAXSIZE)
				{
					biTemp.iVal[i + 1] -= 1;
				}

				biTemp.iVal[i] += 10;
			}
		}
	}
	// ������С�ڼ���;  
	else
	{
		// ȡ����;  
		biTemp.bNeg = true;
		biTemp.size = bi.size;
		// ���;  
		for (int i = 0; i<bi.size; i++)
		{
			biTemp.iVal[i] += bi.iVal[i] - this->iVal[i];
			// ������С��0����תΪ����,�����һλ��һ;  
			if (biTemp.iVal[i] < 0)
			{
				biTemp.iVal[i + 1] -= 1;
				biTemp.iVal[i] += 10;
			}
		}
	}
	// �����Ϊ0����ֱ�ӷ���;  
	// ��ΪbiTemp��δȷ�ϳ��ȣ�����ʹ��strcmp���бȽ�  
	if (!strcmp(biTemp.str, "0"))
	{
		return "0";
	}
	// ת��;  
	intToCahr(&biTemp);

	return biTemp;
}

BigInteger BigInteger::operator* (const BigInteger& bi)
{
	BigInteger biTemp;
	// �������һ����Ϊ0��ֱ�ӷ���0ֵ;  
	if (!strcmp(this->str, "0") || !strcmp(bi.str, "0"))
	{
		return "0";
	}
	// ���ĳ��ȿ���Ϊ���������ĳ��ȼ�1;  
	biTemp.size = this->size + bi.size + 1;
	// �õ�һ������ÿһλȥ���ϵڶ�������ÿһλ;  
	for (int i = 0; i<this->size; i++)
	{
		for (int j = 0; j<bi.size; j++)
		{
			biTemp.iVal[i + j] += this->iVal[i] * bi.iVal[j];
			if (i + j + 1 != MAXSIZE)
			{
				biTemp.iVal[i + j + 1] += biTemp.iVal[i + j] / 10;
			}
			biTemp.iVal[i + j] = biTemp.iVal[i + j] % 10;
		}
	}
	intToCahr(&biTemp);

	return biTemp;
}

BigInteger BigInteger::operator/ (const BigInteger& bi)
{
	BigInteger biTemp;
	// ���������Ϊ0��ֱ�ӷ���;  
	if (!strcmp(this->str, "0"))
	{
		return "0";
	}
	// �������Ϊ1�����ر�����  
	if (!strcmp(bi.str, "1"))
	{
		return *this;
	}

	// ȡ���̵ĳ���;  
	biTemp.size = this->size;

	// �жϱ������ͳ����Ĵ�С;  
	int flag = 0;
	if (this->size > bi.size)
	{
		flag = 1;
	}
	else if (this->size < bi.size)
	{
		flag = -1;
	}
	else
	{
		flag = strcmp(this->str, bi.str);
	}

	// ���������С�ڳ��������Ϊ0;  
	if (flag < 0)
	{
		return "0";
	}
	// ���������ڳ���;  
	else if (flag == 0)
	{
		return "1";
	}
	// ���������ڳ���,�ñ�������ȥ����;  
	else
	{
		BigInteger shang;
		BigInteger div = *this;
		BigInteger dr = bi;
		BigInteger tmp;
		while (div.size >= dr.size)
		{
			tmp = "1";
			if (div.str[0] >= dr.str[0] && strcmp(div.str, dr.str) > 0)
			{
				int k = div.size - dr.size;
				for (int i = 0; i<k; i++)
				{
					tmp = tmp * "10";
				}
				div = div - dr*tmp;
				shang = shang + tmp;
			}
			else if (div.str[0] >= dr.str[0] && div.size - dr.size >= 1)
			{
				int k = div.size - dr.size - 1;
				for (int i = 0; i<k; i++)
				{
					tmp = tmp * "10";
				}
				div = div - dr*tmp;
				shang = shang + tmp;
			}
			else if ((div.str[0] < dr.str[0] && div.size == dr.size) || (div.size == dr.size && strcmp(div.str, dr.str) < 0))
			{
				return shang;
			}
			else if (div.str[0] < dr.str[0] && div.size - dr.size >= 1)
			{
				int k = div.size - dr.size - 1;
				for (int i = 0; i<k; i++)
				{
					tmp = tmp * "10";
				}
				div = div - dr*tmp;
				shang = shang + tmp;
			}
			else
			{
				/*div = div - dr;
				shang = shang + "1";*/
			}
		}
		return shang;
	}

	// ��Ϊ0ʱֱ�ӷ���  
	if (!strcmp(biTemp.str, "0"))
	{
		return "0";
	}
	// ת��;  
	intToCahr(&biTemp);

	return biTemp;
}

BigInteger& BigInteger::operator= (const BigInteger& bi)
{
	// �ж��Ƿ��Ǳ���;  
	if (this == &bi)
	{
		return *this;
	}
	// ��ֵ;  
	memset(this->str, 0, MAXSIZE*sizeof(char));
	memset(this->iVal, 0, MAXSIZE*sizeof(int));
	this->size = bi.size;
	this->bNeg = bi.bNeg;
	memcpy(this->str, bi.str, bi.size);
	for (int i = 0; i<this->size; i++)
	{
		this->iVal[i] = bi.iVal[i];
	}

	return *this;
}

bool BigInteger::operator== (const BigInteger& bi)
{
	// �ж϶Աȵ��Ƿ��Ƕ�����;  
	if (this == &bi)
	{
		return true;
	}
	// �ж��ַ����Ƿ����;  
	if (this->size < bi.size || this->size > bi.size)
	{
		return false;
	}
	else
	{
		// ����һ��ʱ���ַ������ֵ��;  
		return strcmp(this->str, bi.str) == 0;
	}
}

bool BigInteger::operator!= (const BigInteger& bi)
{
	// == �ķ�;  
	return !(*this == bi);
}

ostream& operator<< (ostream& o, const BigInteger& bi)
{
	// ����Ǹ������������;  
	if (bi.bNeg)
	{
		o << "-";
	}
	// ����ַ���ֵ;  
	for (int i = 0; i<bi.size; i++)
	{
		// ��Ϊ������0��ʼ�������Բ��ܵ���ʹ��bi.str�������;  
		o << bi.str[i];
	}


	return o;
}

istream& operator>> (istream& i, BigInteger& bi)
{
	// ͨ��������ַ�������ֵbi;  
	string str;
	i >> str;
	bi = str.c_str();

	return i;
}

void BigInteger::intToCahr(BigInteger* biTemp)
{
	// ���������������λ����0����õ���������������;  
	while (biTemp->size > 0 && biTemp->iVal[biTemp->size - 1] == 0)
	{
		biTemp->size -= 1;
	}

	// ���������ݴ洢Ϊ�ַ���;  
	for (int i = 0; i<biTemp->size; i++)
	{
		biTemp->str[i] = static_cast<char>(biTemp->iVal[biTemp->size - 1 - i] + '0');
	}
}

bool BigInteger::operator< (const BigInteger& bi)
{
	if (this->size > bi.size)
	{
		return false;
	}
	else if (this->size < bi.size)
	{
		return true;
	}
	else
	{
		return strcmp(this->str, bi.str) < 0;
	}
}

bool BigInteger::operator> (const BigInteger& bi)
{
	if (this->size < bi.size)
	{
		return false;
	}
	else if (this->size > bi.size)
	{
		return true;
	}
	else
	{
		return strcmp(this->str, bi.str) > 0;
	}
}

int main(int argc, char* argv[])
{
	BigInteger b1, b2;
	string str;
	cin >> b1 >> str >> b2;

	if (str == "+")
	{
		cout << b1 + b2 << endl;
	}
	else if (str == "-")
	{
		cout << b1 - b2 << endl;
	}
	else if (str == "*")
	{
		cout << b1*b2 << endl;
	}
	else
	{
		cout << b1 / b2 << endl;
	}

	return 0;
}