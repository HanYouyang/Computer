#include <iostream.h>
#include <iomanip.h>
#include "AVLTree.h"


void main()
{
	char select;
	cout<<"ѡ��avl����������: i:���� c:���ַ� f:������ q:�˳�����"<<endl;
	cin>>select;
	for(;(select!='i'&&select!='c'&&select!='f'&&select!='q');)//�ų��������
	{
		cout<<"�����д���"<<endl;
		cin>>select;
	}
	switch (select)
	{	case 'i':
		{
			avlTree<int> treeint;
			int val;char temp;
			cout<<"������:�������ν��ֵ����-1000Ϊ��β"<<endl;
			cin>>val;
			for(;val!=-1000;)
			{
				treeint.add(val);
				cin>>val;
			}
			cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			do{
				cin>>select;
				for(;(select!='a'&&select!='d'&&select!='f'&&select!='n'&&select!='v'&&select!='q');)
				{
					cout<<"�����д���"<<endl;
					cin>>select;
				}
				switch (select)
				{
					case 'a':cout<<"�������ֵ:";cin>>val;treeint.add(val);break;
					case 'd':cout<<"����ɾ��ֵ:";cin>>val;treeint.remove(val);break;
					case 'f':cout<<"�������ֵ:";cin>>val;treeint.display(treeint.findValue(val));break;
					case 'n':cout<<"���ɾ��ȫ��ô(y/n)?";cin>>temp;if(temp=='y') treeint.deleteAllValue();else break;break;
					case 'v':treeint.display();break;
					case 'q':cout<<"Bye";return;
				}
				cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			}while (select!='q');
			return;
		}
		case 'c':
		{
			avlTree<char> treeint;
			char val;char temp;
			cout<<"������:���뵥���ַ����ֵ���� ~ Ϊ��β"<<endl;
			cin>>val;
			for(;val!='~';)
			{
				treeint.add(val);
				cin>>val;
			}
			cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			do{
				cin>>select;
				for(;(select!='a'&&select!='d'&&select!='f'&&select!='n'&&select!='v'&&select!='q');)
				{
					cout<<"�����д���"<<endl;
					cin>>select;
				}
				switch (select)
				{
					case 'a':cout<<"�������ֵ:";cin>>val;treeint.add(val);break;
					case 'd':cout<<"����ɾ��ֵ:";cin>>val;treeint.remove(val);break;
					case 'f':cout<<"�������ֵ:";cin>>val;treeint.display(treeint.findValue(val));break;
					case 'n':cout<<"���ɾ��ȫ��ô(y/n)?";cin>>temp;if(temp=='y') treeint.deleteAllValue();else break;break;
					case 'v':treeint.display();break;
					case 'q':cout<<"Bye";return;
				}
				cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			}while (select!='q');
			return;
		}
		case 'f':
		{
			avlTree<float> treeint;
			float val;char temp;
			cout<<"������:�������ν��ֵ����-1000Ϊ��β"<<endl;
			cin>>val;
			for(;val!=-1000;)
			{
				treeint.add(val);
				cin>>val;
			}
			cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			do{
				cin>>select;
				for(;(select!='a'&&select!='d'&&select!='f'&&select!='n'&&select!='v'&&select!='q');)
				{
					cout<<"�����д���"<<endl;
					cin>>select;
				}
				switch (select)
				{
					case 'a':cout<<"�������ֵ:";cin>>val;treeint.add(val);break;
					case 'd':cout<<"����ɾ��ֵ:";cin>>val;treeint.remove(val);break;
					case 'f':cout<<"�������ֵ:";cin>>val;treeint.display(treeint.findValue(val));break;
					case 'n':cout<<"���ɾ��ȫ��ô(y/n)?";cin>>temp;if(temp=='y') treeint.deleteAllValue();else break;break;
					case 'v':treeint.display();break;
					case 'q':cout<<"Bye";return;
				}
				cout<<"ѡ����: a:���ӽ�㣬d:ɾ����㣬f:���ҽ�㣬n:ɾ������ȫ����㣬v:��ʾ��ǰ����q:�˳�����"<<endl;
			}while (select!='q');
			return;
		}
		case 'q':cout<<"Bye."<<endl;return;
	}
}
