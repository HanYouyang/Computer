#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX_NUM_LEN = 201;
class BigInt
{
private:
    char num[MAX_NUM_LEN];
public:
    BigInt() {
        memset(num, 0, sizeof(num));
        num[0] = '0';
    }
    BigInt(const char * charNum) {
        memcpy(num, charNum, sizeof(strlen(charNum)) + 1);
    }
    friend bool operator == (const BigInt & n1, const BigInt & n2);
    friend bool operator < (const BigInt & n1, const BigInt & n2);
    friend BigInt & operator + (const BigInt & n1, const BigInt & n2);
    friend BigInt & operator - (const BigInt & n1, const BigInt & n2);
    friend BigInt & operator * (const BigInt & n1, const BigInt & n2);
    friend BigInt & operator / (const BigInt & oprand1, const BigInt & oprand2);
    friend BigInt & divideBy2(const BigInt & oprand1);
    friend istream & operator >>(istream & is, BigInt & bigInt);
    friend ostream & operator <<(ostream & os, const BigInt & bigInt);
    ~BigInt();
};
BigInt::~BigInt()
{
}
bool operator == (const BigInt & n1, const BigInt & n2) {
    bool isEqual = true;
    int len1 = strlen(n1.num);
    int len2 = strlen(n2.num);
    if (len1 != len2) {
        isEqual = false;
    }
    else {
        for (int i = 0; i < len1; i++) {
            if (n1.num[i] != n2.num[i]) {
                isEqual = false;
                break;
            }
        }
    }
    return isEqual;
}
bool operator <(const BigInt & n1, const BigInt & n2) {
    int len1 = strlen(n1.num);
    int len2 = strlen(n2.num);
    if (len1 < len2) { return true; }
    else if (len1>len2) { return false; }
    else {
        for (int i = 0; i < len1; i++) {
            if (n1.num[i] > n2.num[i]) {
                return false;
            }
            else if (n1.num[i] < n2.num[i]) {
                return true;
            }
        }
    }
    return false;
}
char * SetToLen(int A, int B, const char * originChars) {
    int d = A - B;
    char * newChars = new char[MAX_NUM_LEN];
    memset(newChars, '0', d);
    memcpy(newChars + d, originChars, B + 1);
    return newChars;
}
BigInt & operator + (const BigInt & n1, const BigInt & n2) {
    BigInt & result = *new BigInt;
    int len1 = strlen(n1.num);
    int len2 = strlen(n2.num);
    int maxlen = len1 > len2 ? len1 : len2;
    char * cn1 = SetToLen(maxlen, len1, n1.num);
    char * cn2 = SetToLen(maxlen, len2, n2.num);
    int ext = 0;
    for (int i = maxlen - 1; i >= 0; i--) {
        result.num[i] = (cn1[i] - '0' + cn2[i] - '0' + ext) % 10 + '0';
        ext = ((cn1[i] - '0' + cn2[i] - '0' + ext) / 10);
    }
    if (ext > 0) {
        char * tempR = new char[MAX_NUM_LEN];
        memcpy(tempR, result.num, MAX_NUM_LEN);
        memcpy(result.num + 1, tempR, maxlen);
        delete[] tempR;
        result.num[0] = '1';
    }
    return result;
}
BigInt & operator - (const BigInt & n1, const BigInt & n2) {
    BigInt & result = *new BigInt;
    int len1 = strlen(n1.num);
    int len2 = strlen(n2.num);
    int maxlen = len1 > len2 ? len1 : len2;
    char * cn1 = SetToLen(maxlen, len1, n1.num);
    char * cn2 = SetToLen(maxlen, len2, n2.num);
    bool symbol = false; //The plus-minus of the result, true for -, false for +
    if (n1 < n2) { symbol = true; }
    // �Ƚϴ�С����
    if (symbol) {
        char* tempChar;
        tempChar = cn1;
        cn1 = cn2;
        cn2 = tempChar;
    }
    //�����ֵ
    int ext = 0;
    for (int i = maxlen - 1; i >= 0; i--) {
        result.num[i] = (cn1[i] - cn2[i] + 10) % 10 + '0' - ext;
        if (cn1[i] < cn2[i] + ext) ext = 1;
        else ext = 0;
    }
    //ȥ��
    int zeroIndex = 0;
    for (int i = 0; i < maxlen - 1; i++) {
        if (result.num[i] != '0')
            break;
        zeroIndex++;
    }
    if (zeroIndex > 0) {
        char* tempR = new char[MAX_NUM_LEN];
        memcpy(tempR, result.num, MAX_NUM_LEN);
        memcpy(result.num, tempR + zeroIndex, maxlen - zeroIndex + 1);
        delete[] tempR;
    }
    //���2��,ǰ���-��
    if (symbol) {
        char* tempR = new char[MAX_NUM_LEN];
        memcpy(tempR, result.num, MAX_NUM_LEN);
        memcpy(result.num + 1, tempR, maxlen);
        delete[] tempR;
        result.num[0] = '-';
    }
    return result;
}
BigInt & operator * (const BigInt & n1, const BigInt & n2) {
    BigInt& result = *new BigInt;
    if (n1 == BigInt("0") || n2 == BigInt("0"))return *new BigInt("0");
    int len1 = strlen(n1.num);
    int len2 = strlen(n2.num);
    BigInt * bigInts[MAX_NUM_LEN];
    int bigIntsLen = len2;
    for (int i = len2 - 1; i >= 0; i--) {
        // ��ǰ�н��
        BigInt* oneLineResult = new BigInt;
        int ext = 0;
        // ��һλ���κ͵ڶ���������ĳһλ���
        for (int j = len1 - 1; j >= 0; j--) {
            char byteMul = (n1.num[j] - '0')*(n2.num[i] - '0') + ext;
            oneLineResult->num[j] = byteMul % 10 + '0';
            ext = byteMul / 10;
        }
        int lenAdd = 0;
        //���յĽ�λ
        if (ext > 0) {
            char* tempR = new char[MAX_NUM_LEN];
            memcpy(tempR, oneLineResult->num, MAX_NUM_LEN);
            memcpy(oneLineResult->num + 1, tempR, len1);
            delete[] tempR;
            oneLineResult->num[0] = ext + '0';
            lenAdd = 1;
        }
        //��󲹽�����־
        oneLineResult->num[len1 + lenAdd] = '\0';
        //׷��0000
        int oldLen = strlen(oneLineResult->num);
        int zeroLen = len2 - i - 1;
        int allLen = oldLen + zeroLen;
        memset(oneLineResult->num + oldLen, '0', zeroLen);
        oneLineResult->num[allLen] = '\0';
        bigInts[i] = oneLineResult;
    }
    // ���ÿλ����Ľ��
    for (int i = 0; i < bigIntsLen; i++) {
        result = result + *bigInts[i];
        delete bigInts[i];
    }
    return result;
}
BigInt & operator / (const BigInt & oprand1, const BigInt & oprand2) {
    if (oprand1 == oprand2)
        return *new BigInt("1");
    else if (oprand1 < oprand2)
        return *new BigInt("0");
    else if (oprand2 == BigInt("2")) {
        return divideBy2(oprand1);
    }
    else if (oprand2 == BigInt("1")) {
        BigInt* bigInt = new BigInt;
        *bigInt = oprand1;
        return *bigInt;
    }
    BigInt* realResult;
    BigInt mulResult;
    BigInt lastMulNum;
    BigInt& mulNum = *new BigInt("1");
    BigInt bigInt2("2");
    //mulNum = new BigInt("1");
    while (true) {
        lastMulNum = mulNum;
        //BigInt tempNum = mulNum;
        //mulNum = tempNum * bigInt2;
        mulNum = mulNum * bigInt2;
        mulResult = oprand2 * mulNum;
        if (mulResult == oprand1) {
            realResult = &mulNum;
            return *realResult;
        }
        else if (oprand1 < mulResult) {
            break;
        }
    }
    BigInt tooBig = mulNum;
    BigInt tooSmall = lastMulNum;
    BigInt dif;
    BigInt divided;
    while (true) {
        //lastMulNum = mulNum;
        dif = tooBig - tooSmall;
        divided = divideBy2(dif);
        mulNum = tooSmall + divided;
        mulResult = oprand2 * mulNum;
        if (mulResult == oprand1) {
            return mulNum;
        }
        else if (mulResult < oprand1)
        {
            tooSmall = mulNum;
            tooBig = tooBig;
        }
        else
        {
            tooSmall = tooSmall;
            tooBig = mulNum;
        }
        if (divided == BigInt("0")) {
            return mulNum;
        }
    }
}
BigInt & divideBy2(const BigInt & oprand1) {
    int len = strlen(oprand1.num);
    BigInt & result = *new BigInt;
    //�����ֵ
    char carry = 0;
    for (int i = 0; i < len; i++) {
        char toDivide = oprand1.num[i] - '0' + carry;
        char oneResult = toDivide / 2;
        result.num[i] = oneResult + '0';
        if (toDivide % 2 > 0)
            carry = 10;
        else
            carry = 0;
    }
    result.num[len] = '\0';
    //ȥ����ͷ�����0
    int zeroIndex = 0;
    for (int i = 0; i < len - 1; i++) {
        if (result.num[i] != '0')
            break;
        zeroIndex++;
    }
    if (zeroIndex > 0) {
        char* tempChars = new char[MAX_NUM_LEN];
        memcpy(tempChars, result.num, MAX_NUM_LEN);
        memcpy(result.num, tempChars + zeroIndex, len - zeroIndex + 1);
        delete[] tempChars;
        //memcpy(result.num, result.num + zeroIndex, len - zeroIndex + 1);
    }
    return result;
}
istream & operator >> (istream & is, BigInt & bigInt) {
    is >> bigInt.num;
    return is;
}
ostream & operator << (ostream & os, const BigInt & bigInt) {
    cout << bigInt.num;
    return os;
}
int main(int argc, char* argv[]) {
    BigInt a, b;
    char op;
    BigInt result;
    cin >> a >> op >> b;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a*b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        break;
    }
    cout << result;
}
