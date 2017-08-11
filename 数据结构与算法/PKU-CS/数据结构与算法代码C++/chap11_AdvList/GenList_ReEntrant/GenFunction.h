// ��������ʵ��
#include "GenList.h"



//GenListNode�Ĺ��캯��


template <class T>
GenListNode<T>::GenListNode()
{
	    type=LIST;
		child=NULL;
		next=NULL;
		mark=0;
		headNode.VisitTimes=0;
}
//GenListNode����������
template <class T>
GenListNode<T>::~GenListNode()
{
	//free all the memery 

}

//�ͷ��ڴ�
template <class T>
void GenListNode<T>::Destory(GenListNode<T> *node)
{
	if(node->next!=NULL)
		Destory(node->next);
	if(node->child!=NULL)
		Destory(node->child);

	  delete node;
}

template <class T>
void GenListNode<T>::Insert(GenListNode<T>*node,GenListNode<T>*current)
{
	GenListNode<T>*tail=this;
	GenListNode<T>*temp=new GenListNode<T>();
	temp->type=LIST;
	temp->child=node;
	node->headNode.ref++;
	while(tail->next!=NULL)
		tail=tail->next;
	tail->next=temp;
	current=temp;
	temp->next=NULL;
	
}

template <class T>
void GenListNode<T>::Insert(T element,GenListNode<T>*current)
{
	GenListNode<T>*tail=this;
	GenListNode<T>*temp=new GenListNode<T>();
	temp->type=ATOM;
	temp->element=element;
	while(tail->next!=NULL)
		tail=tail->next;
	tail->next=temp;
	temp->next=NULL;
	temp->child=NULL;
	
	current=temp;
}

template <class T>
void GenListNode<T>::Search(GenListNode<T> *node,GenListNode<T> *prenode,int VisitTime) 
{   //
	if (node->type==HEAD)	
	{//����һ����ͷ��㣬׼�����������ӱ�
		node->mark=VISITED;
		if(node->headNode.VisitTimes>VisitTime)
			cout<<node->headNode.Name;
		else
		{
			cout<<node->headNode.Name<<":(";
			node->headNode.VisitTimes++;
			if(node->next!=NULL)
				Search(node->next,node,VisitTime);
			else node->mark=UNVISITED;
			cout<<")";
		}
	}
	else	
	{//�Ǳ�ͷ��㣬����ÿһ��element���
      if (node->type==ATOM) {
		cout<<node->element;
		node->mark=VISITED;
	    } 
      else if(node->type==LIST) 
	  {
		
		Search(node->child,node,VisitTime);
	  }
      if((node->next!=NULL)&&(node->next->mark!=VISITED)) 
	  {//û�з��ʹ������������
		  cout<<",";
		  node->mark=VISITED;
		  Search(node->next,node,VisitTime);
	  }

	}
	//���ղŽ���������markֵ������ΪUNVISITED
	GenListNode<T>*temp=node;
	while(temp!=NULL)	{
		temp->mark=UNVISITED;
		temp=temp->next;
	}
	
}


template <class T>
GenListNode<T>* GenListNode<T>::SearchDelete(char *Name,GenListNode<T>* node)
{
	GenListNode<T>* retval=NULL;
	GenListNode<T>* pre;
	GenListNode<T>* curr;
	GenListNode<T>* temp;
	if(node->mark!=VISITED)//δ���ʹ�����Ȼδɾ����
	{
		node->mark=VISITED;
		pre=node;
		curr=node;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			if(curr->type==LIST)
			{
				if(strcmp((curr->child->headNode).Name,Name)==0)
				{
					retval=curr->child;
					curr->child=NULL;
					pre->next=curr->next;
					temp=curr;
					curr=pre;
					delete temp;
				}
				else
					retval=SearchDelete(Name,curr->child);
			}
			pre=curr;
		}
	}
    node->mark=UNVISITED;
	return retval;
}

template <class T>
void GenListNode<T>::Delete(char *Name)
{
	GenListNode<T>* node;
	if(strcmp(Name,(this->headNode).Name)==0)
	{//�Ǹ����
		Destory(this);
	}
	else
	{
		node=SearchDelete(Name,this);
		if(node!=NULL)
		  Destory(node);
	}
}

	
template <class T>
GenListNode<T>* GenListNode<T>::SearchInsert(char *Name,GenListNode<T>* node)
{
	GenListNode<T>* pre;
	GenListNode<T>* curr;
    GenListNode<T>* result=NULL;
	if(node->mark!=VISITED)//������ʹ�,��˵��Ҫ����Ľڵ㲻�ٴ˴�
	{
		node->mark=VISITED;
		pre=node;
		curr=node;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			if(curr->type==LIST)
			{
				if(strcmp((curr->child->headNode).Name,Name)==0)
				{
					
					result=curr->child;
					
				}
				else
				{
					result= SearchInsert(Name,curr->child);
				}
			}
			pre=curr;
		}
	}
	node->mark=UNVISITED;
	return result;
}

template <class T>
void GenListNode<T>::ViewAll()
{
	
	Search(this,NULL,this->headNode.VisitTimes);
	cout<<endl;

}
//�����Ĺ��캯��

template <class T>
GenList<T>::GenList(char *Name)
{
	head= new GenListNode<T>();
	head->next=NULL;
	head->child=NULL;
	head->type=HEAD;
	head->element=NULL;
	head->headNode.ref=0;
	head->headNode.Name = Name;
	current=head;
}


//�����Ĳ��뺯��
template <class T>
void GenList<T>::Insert(T element)
{
	GenListNode<T> *temp=current;
	current=new GenListNode<T>();
	current->type=ATOM;
	current->next=NULL;
	current->child=NULL;
	current->element=element;
	current->mark=0;
	temp->next=current;



}

template <class T>
void GenList<T>::Insert(GenList<T> *genlist)
{
	GenListNode<T> *temp=current;
	GenListNode<T> *n=genlist->GetHead();
	n->mark=0;
	n->headNode.ref++;
   	current=new GenListNode<T>();
	current->child=n;
	current->next=NULL;
	current->type=LIST;
	temp->next=current;
}

template <class T>
void GenList<T>::Insert(GenListNode<T> *node)
{
	GenListNode<T> *temp=current;
	node->mark=0;
	node->headNode.ref++;
   	current=new GenListNode<T>();
	current->child=node;
	current->next=NULL;
	current->type=LIST;
	temp->next=current;
}

//�õ�ͷָ��
template <class T>
GenListNode<T>* GenList<T>::GetHead()
{
	return head;
}

//�õ���һ�����
template <class T>
GenListNode<T>* GenList<T>::GetNext()
{
	if(current->next!=NULL)
	{
		current=current->next;
		return current;
	}
	else return NULL;
}
//�õ���ǰ����ǰһ�����
template <class T>
GenListNode<T>* GenList<T>::GetPrev()
{
	GenListNode<T> *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->next==current)
			return temp;
	}
	return NULL;
}
//ɾ����ǰ���,��ǰ���ָ��ָ����һ�����
template <class T>
int GenList<T>::Remove()
{
	if(current==NULL)
		return -1;
	if(current==head)
		return -2;
	GenListNode<T> *prev=GetPrev();
	GenListNode<T> *next=GetNext();
	prev->next=next;
    GenListNode<T> *temp=current;
	if(next==NULL)
		current=prev;
	else current=next;
	temp->Destory();

}
//move current point to head point
template <class T>
void GenList<T>::MoveFirst()
{
	current=head;
}


//��������
template <class T>
GenList<T>::~GenList()
{
    current=head->next;
	while(current!=head)
		Remove();
    delete head;
}

template <class T>
void GenList<T>::View()
{

    head->ViewAll();

}

template <class T>
bool GenList<T>::Insert(char *ListName, char*NodeName,char*ErrorMsg)
{//��NodeName�в���ListName����
	if(strcmp(NodeName,(head->headNode).Name)==0)
	{//���������м���һ������
		if(strcmp(ListName,(head->headNode).Name)==0)
		{//�������������Լ�
			Insert(this);
		}
		else
		{
			GenListNode<T>* tobeInsert=head->SearchInsert(ListName,head);
			if(tobeInsert==NULL)
			{//�µ�����
					tobeInsert=new GenListNode<T>();
			    	tobeInsert->type=HEAD;
			    	tobeInsert->headNode.Name=ListName;
			    	tobeInsert->headNode.ref++;
			    	tobeInsert->next=NULL;
			    	tobeInsert->child=NULL;
			    	tobeInsert->mark=0;
					Insert(tobeInsert);
			}
			else
			{//���е�����
			    	Insert(tobeInsert);
			}
		}
	}
	else
	{
		GenListNode<T>* WhichtoInsert=head->SearchInsert(NodeName,head);
		if(WhichtoInsert==NULL)
			return false;

		if(strcmp(ListName,(head->headNode).Name)==0)
		{//�������������Լ�
			WhichtoInsert->Insert(head,current);
		}
		else
		{
			GenListNode<T>* tobeInsert=head->SearchInsert(ListName,head);
			if(tobeInsert==NULL)
			{//�µ�����
				tobeInsert=new GenListNode<T>();
				tobeInsert->type=HEAD;
				tobeInsert->headNode.Name=ListName;
				tobeInsert->headNode.ref++;
				tobeInsert->next=NULL;
				tobeInsert->child=NULL;
				tobeInsert->mark=0;
				Insert(tobeInsert);
			}
			else
			{//���е�����
			    WhichtoInsert->Insert(tobeInsert,current);
			}
		}
	}
	return true;
}


template <class T>
bool GenList<T>::Insert(T element, char*NodeName)
{//��NodeName�в���element
	if(strcmp(NodeName,(head->headNode).Name)==0)
	{//���������м���
		Insert(element);
	}
	else
	{
		GenListNode<T>* WhichtoInsert=head->SearchInsert(NodeName,head);
		if(WhichtoInsert==NULL)
			return false;
		WhichtoInsert->Insert(element,current);
	}
	return true;
}

template <class T>
void GenList<T>::DeleteList(char *LName)
{
	head->Delete(LName);
}

	
