//并查集
//Miibotree
//2015.1.22

int Tree[N];

//查找结点x所在树的根节点(没有优化)
int findRoot(int x)
{
	if (Tree[x] == -1)
		return x;
	else
		return findRoot(Tree[x]);
}

//压缩优化
int findRoot(int x)
{
	if (Tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);//tmp里面存的是根节点
		Tree[x] = tmp;
		return tmp;
	}
}

