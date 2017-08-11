//ʹ��ʮ������ʵ��ϡ�����
#include <iostream.h>
#include <afxtempl.h>


class Element //(�С��С�Ԫ��)
{
public:
	int row;
	int col;
	int data;
};

//���ȶ���ڵ���.T�ǽڵ�洢����������
//�����ͷ����򲻴洢�κ���ֵ
template<class T> class SMatrix;

template<class T>
class OLNode
{
	friend SMatrix<T>;
    private:
		int row,col;//������к���
		T element;//�����д洢������
        OLNode<T>* right,*down;//ָ����һ���ڵ��ָ��
	public:
		OLNode(){right=NULL;down=NULL;};
};

//ϡ�����
template<class T>
class SMatrix
{
	private:
		int rownum,colnum;//������
		void CreateMatrix(CArray<Element,Element>&Data);//only for local use 
	public:
		OLNode<T> **rowhead,**colhead;//����ĵ�һ������Ԫ��
		SMatrix();
		void MallocMem(int row,int col); //Ϊ�����ռ��ڴ�
		int GetRownum();
		int GetColnum();
		void CreateMatrix();//��������
        void PrintAll();
		void FreeMem();
		SMatrix<int> * MatrixMutil(SMatrix<int> *left,SMatrix<int>*right);
};

template<class T>
SMatrix<T>::SMatrix()
{
	rowhead=colhead=NULL;
}

template<class T>
int SMatrix<T>::GetRownum()
{
	return rownum;
}

template<class T>
int SMatrix<T>::GetColnum()
{
	return colnum;
}

template<class T>
void SMatrix<T>::MallocMem(int row,int col)
{
	rownum=row;
	colnum=col;
	rowhead=new OLNode<T>*[row+1];
    colhead=new OLNode<T>*[col+1];
    for(int count=0;count<=row;count++)
	{//��ʼ��Ϊͷ���
		rowhead[count]=new OLNode<T>();
		rowhead[count]->row=-1;
		rowhead[count]->col=-1;
	}
    for(count=0;count<=col;count++)
	{
        colhead[count]=new OLNode<T>();
		colhead[count]->row=-1;
        colhead[count]->col=-1;
	}
}

template<class T>
void SMatrix<T>::CreateMatrix()
{
	//����
    if((rowhead!=NULL)||(colnum!=NULL))
	   FreeMem();
	cout<<"������������:";
	cin>>rownum;
	cout<<endl;
	cout<<"������������:";
	cin>>colnum;
    cout<<endl;
	//Ϊ����ָ���ռ��ռ�
    MallocMem(rownum,colnum);
	

	cout<<"����������Ԫ�أ���ʽ<�У��У�����>+�س�,��������������-1"<<endl;
    int i,j;
	T ele;
	while(1)
	{
		cin>>i;
        if(i==-1) break;
		cin>>j;
		cin>>ele;
		if((i>rownum)||(j>colnum)||(i<1)||(j<1))
		{
			cout<<"����ȷ���У��к�"<<endl;
			continue;
		}
		OLNode<T>* temp=new OLNode<T>();
		temp->row=i;
		temp->col=j;
		temp->element=ele;
		//������ָ��
		//����λ�� 
		OLNode<T>* t2=rowhead[i];
        OLNode<T>* t1=NULL;
		while((t2!=NULL)&&(j>t2->col))
		{
			t1=t2;
			t2=t2->right;
		}
		if((t2!=NULL)&&(t2->col==j))
		{//�޸�ֵ
			t2->element=temp->element;
		}
		else
		{
		 //�����µ�ָ��
		    t1->right=temp;
		    temp->right=t2;
		}
		
		//������ָ��
		//����λ�� 
		t2=colhead[j];
        t1=NULL;
		while((t2!=NULL)&&(i>t2->row))
		{
			t1=t2;
			t2=t2->down;
		}
		if((t2!=NULL)&&(t2->row==i))
		{//�޸�ֵ
			t2->element=temp->element;
		}
		else
		{	 //�����µ�ָ��
	        t1->down=temp;
	        temp->down=t2;
		}
	
	}//end of while
}



template<class T>
void SMatrix<T>::PrintAll()
{
	int i,j;
	for(i=1;i<=rownum;i++)
	{
		OLNode<T>*temp= rowhead[i]->right;
		for(j=1;j<=colnum;j++)
		{
			if((temp!=NULL)&&(temp->col==j))
			{
				cout<<" "<<temp->element<<" ";
				temp=temp->right;
			}
			else
				cout<<" 0 ";
		}
		cout<<endl;
	}
}
			
template<class T>
void SMatrix<T>::FreeMem()
{
	int i,j;
	for(i=1;i<=rownum;i++)
	{
		OLNode<T>*temp= rowhead[i];
		for(j=1;j<=colnum;j++)
		{
			if((temp!=NULL)&&(temp->col==j))
			{
				delete temp;
			}
		}
	}
	delete rowhead;
	delete colhead;
}

template <class T>
SMatrix<int>* SMatrix<T>::MatrixMutil(SMatrix<int>*left,SMatrix<int>*right)
{
   	if(left->GetColnum()!=right->GetRownum())
		return NULL;//���в�ƥ�䲻�����

	int I=0; //��һ�����������
	int J=0; //�ڶ������������
    SMatrix<T> *ResultMatrix=new SMatrix<T>();
    ResultMatrix->MallocMem(left->GetRownum(),right->GetColnum());
	for(I=1;I<=left->GetRownum();I++)
	{
		OLNode<T>* RowNext=ResultMatrix->rowhead[I];

		for(J=1;J<=right->GetColnum();J++)
		{
			OLNode<T>* ColNext=ResultMatrix->colhead[J];
			int result=0;
			OLNode<int> * rows=left->rowhead[I]->right;
			OLNode<int>* cols=right->colhead[J]->down;
			if((rows==NULL)||(cols==NULL))
				break;//����û�з���Ԫ��
            
			while((rows!=NULL)&&(cols!=NULL))
			{
				if(rows->col<cols->row)
				{
					rows=rows->right;
				}
				else
					if(rows->col>cols->row)
					{
						cols=cols->down;
					}
					else
					{//����Ԫ�ؿ������
						result=result+cols->element*rows->element;
						cols=cols->down;
                        rows=rows->right;
					}
			}
			if(result==0) continue;
			//���뵽���������
			OLNode<T>* temp=new OLNode<T>();
		    temp->row=I;
		    temp->col=J;
		    temp->element=result;
		
			//����һ���µ�Ԫ�ص���һ��λ��
			RowNext->right=temp;
			RowNext=RowNext->right;
		    //��ת�����ʵ�λ��
			while(ColNext->down!=NULL)
				ColNext=ColNext->down;
			ColNext->down=temp;
			ColNext=ColNext->down;
			
		}//�����һ��Ԫ�أ�����ResultMatrix
	
	}
	/////////////////�˷����꣬�����µľ���
    return ResultMatrix;
}


    


