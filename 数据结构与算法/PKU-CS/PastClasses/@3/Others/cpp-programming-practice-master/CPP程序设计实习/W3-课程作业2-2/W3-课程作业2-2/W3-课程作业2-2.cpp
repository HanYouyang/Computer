//�����������Ľ���ǣ�0��5
#include <iostream>
using namespace std;
class A {
public:
	int val;
	// �ڴ˴�������Ĵ���
	//��ȱ�������������ʽ��
	//A(_________________){ val = n; }
	//________________ GetObj() {
	//	return _________________;
	//}
	A(int n = 0){ val = n; }
	int& GetObj(){
		return val;
	}
};
int main()  {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
	system("pause");
	return 0;
}