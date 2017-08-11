#include "iostream"
#include <memory.h>
using namespace std;
int maze[7][7];  //保存迷宫
bool visited[7][7]; //保存是否访问过
int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
class Position {
public:
	int x_;
	int y_;
	void print() {
		cout << "(" << x_ - 1 << ", " << y_ - 1 << ")";  //转换成输出的样式
	}
	bool reach_end() {
		return (x_ == 5) && (y_ == 5);
	}
	Position move(int i, int j) {
		Position result;
		result.x_ = x_ + i;
		result.y_ = y_ + j;
		return result;
	}
	bool inbound() {
		if ((x_ < 1) || (x_ > 5) || (y_ < 1) || (y_ > 5))
			return false;
		if (maze[x_][y_] == 1)
			return false;
		return true;
	}
	Position(int x, int y) :x_(x), y_(y) {}
	Position() :x_(-1), y_(-1) {}
};

struct Step
{
	Position current_position;
	int previous_position_in_queue;
	Step(Position current_position_, int previous_position_in_queue_) :current_position(current_position_), previous_position_in_queue(previous_position_in_queue_) {}
	Step() {}
};
Step myqueue[20];
int qhead = 0, qtail = 1;
int main(int argc, char const *argv[])
{
	Position result[16];
	Position now(1, 1); //起点为(1,1)
	Position next;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j)
		{
			maze[i][j] = 1; //全部设为边界
			visited[i][j] = false;  //初始值
		}
	}
	for (int i = 1; i < 6; ++i) {  //读入数据
		for (int j = 1; j < 6; ++j)
		{
			cin >> maze[i][j];
		}
	}
	myqueue[qhead] = Step(now, -1); //第一个点是起点，前序点设为-1
	visited[1][1] = true;
	while (qhead != qtail) {
		now = myqueue[qhead].current_position;
		if (now.reach_end())  //找到终点了
		{
			int moves = 0;
			int index = qhead;
			do {
				result[moves++] = myqueue[index].current_position;
				index = myqueue[index].previous_position_in_queue;
			} while (index != -1);
			for (int i = moves - 1; i >= 0; --i)
			{
				result[i].print();
				cout << endl;
			}
			break;
		}
		else {
			for (int i = 0; i < 4; ++i)
			{
				next = now.move(direction[i][0], direction[i][1]);
				if (!next.inbound())
					continue;
				if (visited[next.x_][next.y_])
					continue;
				visited[next.x_][next.y_] = true;
				myqueue[qtail++] = Step(next, qhead);
			}
		}
		qhead++;
	}

	return 0;
}