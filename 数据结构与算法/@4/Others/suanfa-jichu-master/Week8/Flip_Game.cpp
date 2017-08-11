#include "iostream"
#include <queue> 
using namespace std;
struct Node
{
	int status;
	int move;
	Node(int status_, int move_):status(status_),move(move_){}
	Node():status(-1),move(-1){}
};
queue <Node> que;
bool visited[1 << 16];
int flip(int before_flip, int flip_pos){
	int after_flip;
	after_flip = before_flip;
	after_flip = after_flip ^ (1 << flip_pos);
	if(flip_pos > 3){  //下方的格子
		after_flip = after_flip ^ (1 << (flip_pos - 4));
	}
	if(flip_pos < 12){  //上方的格子
		after_flip = after_flip ^ (1 << (flip_pos + 4));
	}
	if(flip_pos % 4 != 3){  //左边的格子
		after_flip = after_flip ^ (1 << (flip_pos + 1));
	}
	if(flip_pos % 4 != 0){  //右边的格子
		after_flip = after_flip ^ (1 << (flip_pos - 1));
	}
	return after_flip;
}


int main(int argc, char const *argv[])
{
	int start_status = 0;
	char input_char;
	Node current_node;
	int next_status;
	for (int i = 0; i < 16; ++i)
	{
		cin >> input_char;
		start_status = (start_status << 1) + (input_char == 'b' ? 1 : 0);  //白色为0，黑色为1
	}
	que.push(Node(start_status, 0));
	visited[start_status] = true;
	while(!que.empty()){
		current_node = que.front();
		que.pop();
		if (current_node.status == 0 || current_node.status == (1 << 16) - 1)
		{
			cout << current_node.move << endl;
			return 0;
		}else{
			for (int i = 0; i < 16; ++i) //分别尝试翻16个格子
			{
				next_status = flip(current_node.status, i);
				if(!visited[next_status]){
					visited[next_status] = true;
					que.push(Node(next_status, current_node.move + 1));
				}
			}
		}
	}
	cout << "Impossible" << endl;
	return 0;
}