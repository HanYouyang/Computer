#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

#define N 32

int postOrder[N];
int inOrder[N];

struct node
{
    int val;
    node *left;
    node *right;
    node(const int &v);
};

node::node(const int &v)
{
    val = v;
    left = right = NULL;
}

void build(node * &r, int post[],int in[],int postLeft,int postRight, int inLeft, int inRight)
{//������rΪ���Ķ�����
    if(inLeft > inRight)
    {//�������޽�㣬�ն�����
        r = NULL;
    }
    else
    {
        r = new node(post[postRight]);
        int mid = inLeft;
        while(in[mid] != post[postRight])
        {//�ҳ���������и���λ��
            mid++;
        }
        //cout << "����" << post[postRight] << endl;
        //cout << "��" << postLeft << " " <<  postLeft+(mid-1) << " " <<  inLeft << " " <<  mid-1 << endl;
        //cout << "�ң�" << postLeft+mid << " " <<   postLeft+mid-inLeft << " " <<  mid+1 << " " <<  inRight << endl;
        //system("pause");
        build(r->left, post, in, postLeft, postLeft+(mid-1-inLeft), inLeft, mid-1);
        build(r->right, post, in, postLeft+mid-inLeft, postRight-1, mid+1, inRight);
    }
}

int main()
{
    int n,i;
    while(cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> postOrder[i];
        }
        for(i = 0; i < n; i++)
        {
            cin >> inOrder[i];
        }
        node *root;
        build(root, postOrder, inOrder, 0, n-1, 0, n-1);

        vector<int> ans;
        queue<node*> q;

        if(root != NULL)
        {
            q.push(root);
        }

        while(!q.empty())
        {
            node *cur = q.front();
            ans.push_back(cur->val);
            q.pop();
            if(cur->left != NULL)
            {
                q.push(cur->left);
            }
            if(cur->right != NULL)
            {
                q.push(cur->right);
            }
        }
        for(i = 0; i < ans.size()-1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[i] << endl;
    }
    return 0;
}
