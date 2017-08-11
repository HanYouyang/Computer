package frequency_3;

import java.util.LinkedList;
import java.util.Queue;

import javax.management.loading.PrivateClassLoader;
//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//
//X X X X         xxxx
//X O O X         x  x
//X X O X         xx x  
//X O X X         x xx     这一块是封闭区间 
//
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X

public class SurroundedRegions {
//	 任何一个O如果它没有被X包围，那么它一定和最外面的边界的某个O是连通的。
//	反过来，也就是可以从最外面那层所有的O开始用广度搜索所有没有被包围的O。
	//先扫描四条边 然后 碰到O 就先改成'I' 再bfs扫描上下左右(防止bfs因为没改O重复扫描)
	//入queue 然后  然后把本O的上下左右查一遍 碰到O就先改成'I' 再bfs扫描上下左右
    //然后第二次 再扫描MATRIX 把 O变成 x 把I变成O
	
	//为什么要先改 i再bfs
//	NY-Kazami  17:08:07
//	因为是bfs 举个例子 有一个点距离为4 但是有多个路径 但是如果你在poll的时候没有判断的话 他会重复把这个点再做bfs
//	所以为什么我一开始说你Poll的时候要判断
//	猫  17:14:04
//	比方说有个中间点 是0 假设他上下左右都是0 然后他bfs调查到左点的时候 左点bfs 会上下左右然后扩展到中的上。。下。。右，。点 所以就会重复了

	
	public void solve(char[][] board) {
	if(board==null||board.length==0){
		return;
	}
	//检查左边和右边 
	for(int i=0;i<board.length;i++){
		if(board[i][0]=='O'){
		    board[i][0]='I';
			BFSReplace(board, i, 0);
	}
	if(board[i][board[0].length-1]=='O'){
	    board[i][board[0].length-1]='I';
		BFSReplace(board, i, board[0].length-1);
	}
}
	//检查上边和下边  四个角不用重复开2遍
		for(int i=1;i<board[0].length-1;i++){
		if(board[0][i]=='O'){
		    board[0][i]='I';
			BFSReplace(board, 0, i);
		}
		if(board[board.length-1][i]=='O'){
		    board[board.length-1][i]='I';
			BFSReplace(board, board.length-1, i);
		}
	}
	
	//bfs都完毕后 把O都变成X 把I都变成O
	for (int i = 0; i < board.length; i++) {
		for(int j=0;j<board[0].length;j++){
			if(board[i][j]=='O'){
				board[i][j]='X';
			}else if(board[i][j]=='I'){
				board[i][j]='O';
			}
		}
	}
	
	
	
	}
	//找到边上的o后bfs继续找
 private void BFSReplace(char[][] board,int x,int y){
	 Queue<Integer> queue= new LinkedList<Integer>();
	 int length=board[0].length;
    queue.add(x*length+y);// 这是一种 很巧妙的记录把举证坐标记录在一个int里的方法
    //“解压” 的时候 就x=cur/length  y=cur%length;
    while(queue.size()!=0){
    	int cur=queue.poll();
    	x=cur/length;
    	y=cur%length;
    	//解压出x y坐标后  上下左右bfs去找如果是 0 就入queue
    	if(x-1>=0&&board[x-1][y]=='O'){
    	    board[x-1][y]='I';
    		queue.add(length*(x-1)+y);
    	}
    	if(y-1>=0&&board[x][y-1]=='O'){
    	   board[x][y-1]='I';
    	queue.add(length*x+(y-1));
    	}
    	if(x+1<board.length&&board[x+1][y]=='O'){
    	    board[x+1][y]='I';
    		queue.add(length*(x+1)+y);
    	}
    	if(y+1<board[x].length&&board[x][y+1]=='O'){
    	    	  board[x][y+1]='I';
    	 	queue.add(length*x+(y+1));
    	}
        }    
  } 
 }
