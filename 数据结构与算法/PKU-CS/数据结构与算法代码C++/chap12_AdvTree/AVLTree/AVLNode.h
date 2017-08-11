//this is avl tree node 



template <class T> class avlNode//ƽ������������
{
	public:
		avlNode(T val);//���캯��
		avlNode(T val,avlNode<T> *left,avlNode<T> *right,int bf);
		avlNode<T>* copy()const;//�����Ե�ǰ���Ϊ���Ķ����� ��(д���ˣ�û����)                           
		void release();//ɾ���Ե�ǰ���Ϊ������������									
		void left(avlNode *);//�ѵ�ǰ������ָ���޸�Ϊ�����Ĳ���
		avlNode<T>* left()const;//���ӽ����ʣ����������ָ��
		void right(avlNode *v);//�ѵ�ǰ������ָ���޸�Ϊ�����Ĳ���
		avlNode<T>* right()const;//���ӽ����ʣ������ҽ���ָ��
		int add(avlNode<T>* &p,T val);//����һ��ֵ�������µ�avl���ĸ�����ָ��
		void preorderview(avlNode<T> *current,int i=-1);//ǰ������
		avlNode<T>* remove(T val,avlNode<T>* &waste,int &flag);//ɾ���Ե�ǰ����Ϊ����avl���е�val���
		avlNode<T>* findNodeValue(T val);//����val���
		T value;//��ֵ
	private:
		int bf;// balance factor
		avlNode<T>* leftptr;//����ָ��
		avlNode<T>* rightptr;
		//avlNode<T>* restoreLeftBalance(int oldbf);//ɾ��ʱ������ʧ���ʱ������������µ�������ָ��
		//avlNode<T>* restoreRightBalance(int oldbf);//ɾ��ʱ������ʧ���ʱ������������µ�������ָ��
		avlNode<T>* removeLeftmostElement(avlNode<T>* &childptr,int &flag);//�ҵ�����Ľ��
		//avlNode<T>* removeBalanceLeft();//��������ɾ����ʱ���жϲ����ĸı�
		//avlNode<T>* removeBalanceRight();//��������ɾ����ʱ���жϲ����ĸı�
		avlNode<T>* LL_singleRotation();//�ڲ���ʱ��������LLʧ���ʱ������������µ�������ָ��
		avlNode<T>* RR_singleRotation();//�ڲ���ʱ��������RRʧ���ʱ������������µ�������ָ��
		avlNode<T>* LR_doubleRotation();//�ڲ���ʱ��������LRʧ���ʱ������������µ�������ָ��
		avlNode<T>* RL_doubleRotation();//�ڲ���ʱ��������RLʧ���ʱ������������µ�������ָ��
	
};


template <class T> avlNode<T>::avlNode(T val)
{
	value=val;
	leftptr=NULL;
	rightptr=NULL;
	bf=0;
}
template <class T> avlNode<T>::avlNode(T val,avlNode<T> *left,avlNode<T> *right,int bf=0)
{
	value=val;
	leftptr=left;
	rightptr=right;
	bf=bf;
}
template <class T> avlNode<T>* avlNode<T>::copy()const
{
	avlNode<T> *nl,*nr;
	nl=(leftptr==NULL?NULL:leftptr->copy());//�ݹ���ø���������
	nr=(rightptr==NULL?NULL:rightptr->copy());//�ݹ���ø���������
	avlNode<T>* node=new avlNode<T>(value,nl,nr,bf);
	if(node!=NULL)   //?? ==NULL
		cout<<"error"<<endl;
	else
		return node;
}
template <class T> void avlNode<T>::release()
{
	if (leftptr)
	{//ɾ���������еĽ��
		leftptr->release();//�ݹ����
		delete leftptr;
		leftptr=0;
	}
	if (rightptr)
	{//ɾ���������еĽ��
		rightptr->release();//�ݹ����
		delete rightptr;
		rightptr=0;
	}
}
template <class T> avlNode<T>* avlNode<T>::left()const
{
	return leftptr;
}
template <class T> void avlNode<T>::left(avlNode<T>* v)
{
	leftptr=v;
}
template <class T> avlNode<T>* avlNode<T>::right()const
{
	return rightptr;
}
template <class T> void avlNode<T>::right(avlNode<T>* v)
{
	rightptr=v;
}
template <class T> int avlNode<T>::add(avlNode<T>* &rp,T val)
{//����ֵ�����Ե�ǰ���Ϊ�������Ƿ��ٲ���֮�����ߣ�0:�����ߣ���0:����
	if (val<value)
	{//����������
		if (rp->left()==NULL)
			rp->left(new avlNode<T>(val));
		else if(rp->left()->add(rp->leftptr,val)==0)//���������û������
			return 0;
		if (rp->bf==-1)
		{//ԭ���Ѿ���б�����ʧ�⣬��Ҫ��ƽ�⴦��
	       if (rp->left()->bf<0)  //��������࣬����ת
	             rp = LL_singleRotation();
	       else rp = LR_doubleRotation();	//�������Ҳ࣬˫��ת
		   return 0;
		}
		return --bf;   // bf=(0, +1)�����������Ҫ��������ֻҪ�޸�bf
	}
	else
	{
		if (rp->right()==NULL)
			rp->right(new avlNode<T>(val));
		else if (rp->right()->add(rp->rightptr,val)==0)//���������û������ 
			return 0;
		if(rp->bf==1)
		{//ԭ���Ѿ���б����Ҫ��ƽ�⴦��
	       if (rp->right()->bf>0)    //�������Ҳ࣬����ת
	           rp = RR_singleRotation();
	       else rp = RL_doubleRotation();  //��������Ҳ�.˫��ת
		   return 0;
		}
		return ++bf; // bf=(0, -1)�����������Ҫ��������ֻҪ�޸�bf
	}
}


template <class T> avlNode<T>* avlNode<T>::remove(T val,avlNode<T>* &waste,int &flag)
{
	if (val==value)
	{
		waste=this;
		//��û����������ʱ�򷵻�������
		if(right()==NULL)
		{
			flag=1;
			return left();
		}
		//ɾ���������е���С���
		int oldbf=right()->bf;
		avlNode* newroot;
		right(right()->removeLeftmostElement(newroot,flag));//�ҵ��󷵻��Ѿ�ƽ���avl���ĸ�ָ��
		newroot->left(left());
		newroot->right(right());
		if((flag==1)&&(bf==1))
			flag=1;
		else flag=0;
		if(flag==1)
		{
			newroot->bf=bf--;
		}
		else newroot->bf=bf;
        //������ƽ��
		avlNode<T>* rightchild=newroot->right();
	    if (rightchild==NULL) 
		    bf--;
	    else if((rightchild->bf!=oldbf)&&(rightchild->bf==0))
		    bf--;
    	if (bf<-1)
		{
		    int newoldbf=newroot->left()->bf;
	        if (newoldbf>0)
			{//˫��ת
    	       return newroot->LR_doubleRotation();
			}
	        else
			{//����ת
		       return newroot->LL_singleRotation();
           	}
		}
	    return newroot;
		
	}
	else if(val<value)
	{//����������ɾ��
		if(left()==NULL)
			return this;
		//ִ��ɾ��
		int oldbf=left()->bf;
		left(left()->remove(val,waste,flag));//�ݹ����
        //����������
        avlNode<T>* leftchild=left();
	//	if(flag==1)
	//		bf++;
	    //����ɾ����������Ե�ǰ�ĸ�����ƽ�����ӵ�Ӱ��
	    if (leftchild==NULL)
		   bf++;
	    else if((leftchild->bf!=oldbf)&&(leftchild->bf==0))
		   bf++;
	    if (bf>1)//ʧ��
		{//����
		   int newoldbf=right()->bf;
	       if (newoldbf<0)//˫��ת
		   {
	           return RL_doubleRotation();
		   }
	       else
		   {//����ת
		       avlNode* temp= RR_singleRotation();
			   if(flag==1)
				   bf++;
			   return temp;
		   }
		}
    	return this;
	}
	else
	{//����������ɾ��
		if(right()==NULL)
			return this;
		//ִ��ɾ��
		int oldbf=right()->bf;
		right(right()->remove(val,waste,flag));//�ݹ����
		//����������
		avlNode<T>* rightchild=right();
    	if (rightchild==NULL) 
		  bf--;
	    else if((rightchild->bf!=oldbf)&&(rightchild->bf==0))
		  bf--;
	    if (bf<-1)
		{
		  int newoldbf=left()->bf;
	      if (newoldbf>0)
		  {//˫��ת
    	      return LR_doubleRotation();
		  }
	      else
		  {//����ת
			  avlNode* temp= LL_singleRotation();
			  if(flag==1)
			    bf--;
			   return temp;
		   }
		} 
	    return this;
	}
}

template <class T> avlNode<T>* avlNode<T>::removeLeftmostElement(avlNode<T>* &childptr,int &flag)
{//flag ��ʾ�����߶��Ƿ�仯
	avlNode* leftchild=left();
	//�ҵ���С��ֵ�����أ�����ݹ����
	if (leftchild==NULL)
	{
		childptr=this;
		flag=1;
		return right();
	}
	int oldbf=leftchild->bf;
	left(leftchild->removeLeftmostElement(childptr,flag));//�ݹ����
	//����������ƽ��
	avlNode<T>* newleftchild=left();
	//����ɾ����������ĸ߶ȱ仯
	if((newleftchild==NULL)&&(right()==NULL))
		flag=1;
	//����ɾ����������Ե�ǰ�ĸ�����ƽ�����ӵ�Ӱ��
	if (newleftchild==NULL)
		bf++;
	else if((newleftchild->bf!=oldbf)&&(newleftchild->bf==0))
		bf++;
	if (bf>1)//ʧ��
	{//����
		int newoldbf=right()->bf;
	    if (newoldbf<0)//˫��ת
		{
	       return RL_doubleRotation();
		}
	    else
		{//����ת
		   return RR_singleRotation();
		}
	}
	return this;
}


template <class T> avlNode<T>* avlNode<T>::findNodeValue(T val)
{
	if (val==value)
	{
		return this;
	}
	else if (val>value)
	{//���ڵĻ����������в���
		if (right()!=NULL)
			return right()->findNodeValue(val);//�ݹ����
		else 
			return NULL;
	}
	else
	{//С�ڵĻ����������в���
		if (left()!=NULL)			
			return left()->findNodeValue(val);//�ݹ����
		else
			return NULL;
	}
}
template <class T> void avlNode<T>::preorderview(avlNode<T> *current,int i)
{
	i++;//�������
	if (current)
	{
		cout<<setw(8)<<current->value<<setw(10)<<current->bf<<" "<<setw(6)<<i<<endl;
		preorderview(current->left(),i);//�ݹ����
		preorderview(current->right(),i);//�ݹ����
	}
}

template <class T> avlNode<T>* avlNode<T>::LL_singleRotation()
{
	avlNode<T> *p;
	p=left();
	left(p->right());
	bf=0;
	p->right(this);
    if(p->bf==0)
	  p->bf=1;
	else p->bf=0;
	return p;
}

template <class T> avlNode<T>* avlNode<T>::LR_doubleRotation()
{
	avlNode<T> *p,*q;
	q=left();
	p=q->right();
	q->right(p->left());
	left(p->right());
	p->left(q);
	bf=q->bf=0;
	if(p->bf==-1) bf=1;
	if(p->bf==1) q->bf=-1;
	p->right(this);
	p->bf=0;
	return p;
}

template <class T> avlNode<T>* avlNode<T>::RR_singleRotation()
{
	avlNode<T> *p;
	p=right();
	right(p->left());
	bf=0;
	p->left(this);
    if(p->bf==0) 
	  p->bf=-1;
	else p->bf=0;
	return p;
}

template <class T> avlNode<T>* avlNode<T>::RL_doubleRotation()
{
	avlNode<T> *p,*q;
	q=right();
	p=q->left();
	q->left(p->right());
	right(p->left());
	p->right(q);
	bf=q->bf=0;
	if(p->bf==-1) q->bf=1;
	if(p->bf==1) bf=-1;
	p->left(this);
	p->bf=0;
	return p;
}

