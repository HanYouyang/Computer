//ʹ�ù�����������
//

#include "GenFunction.h"

void main()
{



// ����� (L1:(L2:(a, L1)), Lx:(L2, L3:b), Ly:(L3,c,d), L4:(L4))
	GenList<char*> *List=new GenList<char*>("List");
	cout<<"Ĭ�ϵı����ɣ�����:List ����: List:()"<<endl;
	int operation;
	while(1)
	{
	
		operation=-1;
		cout<<"��ѡ����Ĳ��� 0:���� 1:ɾ�� 2:�鿴������ ����:�˳�"<<endl;
		cin>>operation;
		if((operation!=0)&&(operation!=1)&&(operation!=2))
			return;
		switch(operation)
		{
		case 0:
			{
				int type=-1;
				char*name=new char[10];
				cout<<"������Ҫ�������ݵı���:"<<endl;
				cin>>name;
				cout<<"��ѡ����Ҫ��������� 0:Ԫ�� 1:�ӱ�"<<endl;
				cin>>type;
			
				if(type==0)
				{
					char* element=new char[10];
					cout<<"������Ԫ��ֵ"<<endl;
					cin>>element;
					bool flag=List->Insert(element,name);
					if(!flag)
						cout<<"����ʧ�ܣ������Ƿ��и��ӱ�"<<endl;
				}
				else
				{
					char* newlist=new char[10];
					cout<<"�����������ӱ���"<<endl;
					cin>>newlist;
					char* error=new char[10];
					bool flag=List->Insert(newlist,name,error);
					if(!flag)
						cout<<"����ʧ�ܣ�������ӱ��Ƿ����"<<endl;
				
				}
				delete []name;
				break;
			}
		case 1:
			{
				char * name=new char[10];
				cout<<"�������ɾ�����ӱ�����"<<endl;
				cin>>name;
				List->DeleteList(name);
				if(strcmp(name,"List")==0)
				{
					cout<<"������ɾ���������˳�"<<endl;
					delete []name;
					return;
				}
				break;
			}
		case 2:
			{
		
				List->View(); 
		
			}

		}
	}

}
