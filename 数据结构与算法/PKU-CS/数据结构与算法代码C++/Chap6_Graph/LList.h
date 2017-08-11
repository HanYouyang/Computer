//��������������ͷ��������û���κβ���������

//����Ԫ��
template<class Elem>
class Link
{
public:
	Elem element;      //��Ŀ������
	Link *next;        //��Ŀָ�룬ָ����һ����Ŀ
	Link(const Elem& elemval,Link *nextval=NULL)  //���캯��
	{ element=elemval; next=nextval; }
	Link(Link *nextval=NULL) { next=nextval; }    //���캯��
};

//����
template<class Elem>
class LList
{
public:
	Link<Elem>* head;  //headָ�벢�������κ�ʵ��Ԫ�أ������ֻ��Ϊ�˲�������
	
	LList()            //���캯��
	{
		head=new Link<Elem>();
	}

	void removeall()        //�ͷű߱����б�Ŀռ�ݵĿռ�
	{
		Link<Elem> *fence;
		while(head!=NULL)   //���ͷ�ÿ����Ŀռ�ݵĿռ�
		{  
			fence=head;
			head=head->next;
			delete fence;
		}
	}

	~LList() { removeall(); } //��������
};