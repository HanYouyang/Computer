//this is avl tree class
#include "AVLNode.h"

template <class T> class avlTree//ƽ���������
{
	public:
		avlTree();//���캯��
		avlTree(const avlTree<T> &source);
		~avlTree();//��������
		void add(T value);
		void remove(T value);
		void deleteAllValue();
		void display();
		void display(avlNode<T>* found);
		avlNode<T>* findValue(T val);
	private:
		avlNode<T> *root;
};


template <class T>avlTree<T>::avlTree<T>():root(0)
{}//��������
template <class T>avlTree<T>::avlTree<T>(const avlTree<T> &source)
{//���ƹ��캯��
	root=(source.root==NULL?NULL:source.root->copy());
}
template <class T> avlTree<T>::~avlTree()
{
	if (root!=NULL) deleteAllValue();
}
template <class T> void avlTree<T>::add(T value)
{//��ƽ���avl�����Ԫ��
	if(root==NULL)
		root=new avlNode<T>(value);
	else
		root->add(root,value);
}

template <class T> void avlTree<T>::remove(T val)
{//��avl����ɾ��һ��Ԫ��
	avlNode<T>* eNode=NULL;
	int flag=0;
	if (root)
		root=root->remove(val,eNode,flag);
	if (eNode)
		delete eNode;
	else cout<<"The avlTree doesn't contain the value"<<endl;
}

template <class T> void avlTree<T>::deleteAllValue()
{//ɾ��avl����ȫ��Ԫ��
	if(root!=NULL)
	{
		root->release();
		delete root;
		root=NULL;
	}
}
template <class T> void avlTree<T>::display()
{
	if (root) 
	{
		cout<<setw(8)<<"�ڵ�ֵ"<<setw(10)<<"ƽ������"<<" "<<setw(6)<<"����"<<endl;
		root->preorderview(root);
	}
	else cout<<"��ǰ����!"<<endl;
}
template <class T> avlNode<T>* avlTree<T>::findValue(T val)
{//����val�Ľڵ�ֵ
	avlNode<T>* found=root->findNodeValue(val);
	if (found==NULL)
		return NULL;
	else
		return found;
}
template <class T> void avlTree<T>::display(avlNode<T>* found)
{//��ʾָ���ָ�����ֵ
	if(found==NULL) 
		cout<<"Sorry,û�ҵ� :("<<endl;
	else
		cout<<"�ҵ�:"<<found->value<<endl;
}

