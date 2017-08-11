#include "iostream"
#include <memory.h>
#include <stdio.h>
using namespace std;
const int N = 25;
int map[6][N][N]; //存放地图
int color[6][N][N]; //是否染色的标志
int max_room_area = 0;
int room_number = 0;
int size_of_face = 0; //存放每组数据的单面大小
int room_area;
int direction[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
void reset() {
	memset(map, 0, sizeof(map));
	memset(color, 0, sizeof(color));
	max_room_area = 0;
	room_number = 0;
	room_area = 0;
	size_of_face = 0;
}

int max(int i, int j) {
	if (i > j)
		return i;
	else
		return j;
}

void dfs(int face, int i, int j) {
	if (color[face][i][j]) //如果已经被访问过了，直接返回
	{
		return;
	}
	int next_face, next_i, next_j;
	room_area++;  //没有被访问过，房间数++
	color[face][i][j] = room_number;
	for (int dir = 0; dir < 4; ++dir)
		//0:往上，1：往下，2：往左，3：往右
	{
		next_face = face; //默认不变
		next_i = i + direction[dir][0];
		next_j = j + direction[dir][1];
		//穷举寻路
		if (face == 0)
		{
			if (next_i < 0) //上越界
			{
				next_face = 4;
				next_i = size_of_face - 1;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 5;
				next_i = size_of_face - 1;
			}
			if (next_j < 0) //左越界
			{
				next_face = 3;
				next_j = size_of_face - 1;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 1;
				next_j = 0;
			}
		}
		if (face == 1)
		{
			if (next_i < 0) //上越界
			{
				next_face = 4;
				next_i = size_of_face - 1 - next_j;
				next_j = size_of_face - 1;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 5;
				next_i = size_of_face - 1 - next_j;
				next_j = size_of_face - 1;
			}
			if (next_j < 0) //左越界
			{
				next_face = 0;
				next_j = size_of_face - 1;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 2;
				next_j = 0;
			}
		}
		if (face == 2)
		{
			if (next_i < 0) //上越界
			{
				next_face = 4;
				next_i = 0;
				next_j = size_of_face - 1 - next_j;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 5;
				next_i = 0;
				next_j = size_of_face - 1 - next_j;
			}
			if (next_j < 0) //左越界
			{
				next_face = 1;
				next_j = size_of_face - 1;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 3;
				next_j = 0;
			}
		}
		if (face == 3)
		{
			if (next_i < 0) //上越界
			{
				next_face = 4;
				next_i = next_j;
				next_j = 0;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 5;
				next_i = next_j;
				next_j = 0;
			}
			if (next_j < 0) //左越界
			{
				next_face = 2;
				next_j = size_of_face - 1;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 0;
				next_j = 0;
			}
		}
		if (face == 4)
		{
			if (next_i < 0) //上越界
			{
				next_face = 2;
				next_i = 0;
				next_j = size_of_face - 1 - next_j;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 0;
				next_i = 0;
			}
			if (next_j < 0) //左越界
			{
				next_face = 3;
				next_j = next_i;
				next_i = 0;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 1;
				next_j = size_of_face - 1 - next_i;
				next_i = 0;
			}
		}
		if (face == 5)
		{
			if (next_i < 0) //上越界
			{
				next_face = 2;
				next_i = size_of_face - 1;
				next_j = size_of_face - 1 - next_j;
			}
			if (next_i > size_of_face - 1) //下越界
			{
				next_face = 0;
				next_i = size_of_face - 1;
			}
			if (next_j < 0) //左越界
			{
				next_face = 3;
				next_j = next_i;
				next_i = size_of_face - 1;
			}
			if (next_j > size_of_face - 1) //右越界
			{
				next_face = 1;
				next_j = size_of_face - 1 - next_i;
				next_i = size_of_face - 1;
			}
		}
		if (map[next_face][next_i][next_j] == 0) //可以走
		{
			dfs(next_face, next_i, next_j);
		}
	}
}


int main(int argc, char const *argv[])
{
	int set; //set是数据组数，size_of_face是一面的大小,size_of_face最大为N。
	scanf("%d", &set);
	while (set--) {
		//输入数据
		reset();
		scanf("%d", &size_of_face);
		for (int face = 0; face < 6; ++face)  //ABDC，BFHD，FEGH，EACG，EFBA，GHDC
		{
			for (int i = 0; i < size_of_face; ++i)
			{
				for (int j = 0; j < size_of_face; ++j)
				{
					scanf("%d", &map[face][i][j]);
				}
			}
		}
		//------------结束输入数据-----------
		for (int face = 0; face < 6; ++face)  //ABDC，BFHD，FEGH，EACG，EFBA，GHDC
		{
			for (int i = 0; i < size_of_face; ++i)
			{
				for (int j = 0; j < size_of_face; ++j)
				{
					//如果某个点还没有被访问过并且可以访问，说明是一个新的房间，就从该点开始遍历地图，直到找到所有与之连通的点
					if (!color[face][i][j] && !map[face][i][j])
					{
						room_number++;
						room_area = 0;
						dfs(face, i, j);
						max_room_area = max(room_area, max_room_area);//比较该点所在房间大小和当前保存的最大房间大小哪个大
					}
				}
			}
		}
		printf("%d %d\n", room_number, max_room_area);
	}
	return 0;
}