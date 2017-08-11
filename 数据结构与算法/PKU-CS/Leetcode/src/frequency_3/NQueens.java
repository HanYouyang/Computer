package frequency_3;

import java.util.ArrayList;

import javax.naming.spi.DirStateFactory.Result;
import javax.swing.RowFilter;

// N皇后 cc原题 要求1维数组输出 
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
public class NQueens {
 //这个就是棋盘格的列数  Nqueen就是N列
	
  
////先写一个检查当前位置是否可以 放queen的方法    
public boolean checkPosotion(int[] queenList,int row,int col){
	for(int preRow=0;preRow<row;preRow++){
		int preCol=queenList[preRow];
    //这里的preRow和PreCol就是以前放queen的row和col的位置 我们loop检查 
	
		//检查行和列
		if(preRow==row||preCol==col){
    	 return false;
     } 
		//  反对角线
		if(row-preRow==col-preCol){
			return false;
		}
		//正对角线
		if(preRow+preCol==row+col){
		 return false;
		}
	}
	
	return true;
}
	
	
public ArrayList<String[]> solveNQueens(int n) {
	ArrayList<String[]> result=new ArrayList<String[]>();
	//用一维数祖建立棋盘
	int[] queenList=new int[n];
	placeQueen(queenList,0,n,result);
	return result;
	}

public void placeQueen(int[] queenList,int row,int n,ArrayList<String[]> result){
	//终止条件,此时建造棋盘 放置queen sol 和queenlist的大小是一样的
	if(row==n){
		StringBuilder[] sol=new StringBuilder[n];
		for(int i=0;i<n;i++){
			sol[i]= new StringBuilder();
			for(int j=0;j<n;j++){
				sol[i].append('.');
			}
		}
		
		for(int i=0;i<n; i++){
			               //queenList[i]是在棋盘上第i row queen的位置（在第几列）
			                 //sol里也要在第i行把这queenList[i]列改成queen
			//i是row number sol[i] 和queenList[i]的值是列号
			sol[i].setCharAt(queenList[i], 'Q');
		}
String[] ss=new String[n];
for(int i=0;i<n;i++)
{              //把StringBuffer数组 换成string数组（之所以之前要buffer是因为放queen方便）
	ss[i]=sol[i].toString();
	}
	result.add(ss);
 return;
	}
	
	for (int col = 0; col < n; col++) {// 这个for遍历的是column
		if(checkPosotion(queenList, row,col)){
			queenList[row]=col; //能pass这个插位置 就说明 可以在这个row的i位置可以放
		placeQueen(queenList, row+1, n,result);
		}
		}
	}	

    }

