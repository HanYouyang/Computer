package frequency_2;

import javax.management.loading.PrivateClassLoader;

//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
//检查一个数独是否valid 可以没有填满
//数独是一个9x9的矩阵里面有9个小块 要求每行都有不重复的1~9 这题可以缺但是不可以重
//每列 也是不重复1~9  这题可以缺但是不可以重
//每个小矩阵里面也是 1~9 可以缺不能重

public class ValidSudoku {
//如果不编程这题怎么做   检查行 检查列 检查每个小矩阵就行了

	public boolean isValidSudoku(char[][] board) {
    return isValidRow(board)&&isValidColumn(board)&&isValidBox(board);     
 	}
	
	//检查 这个c是不是已经在flag里出现 如果重复出现返回false
 private boolean markFlag(boolean[] flag,char c){
	 if(c=='.'){
		 return true;
	 }
	 int index= c-'0';
	 if(flag[index]){  //如果之前已经出现过这个数了
		 return false;
	 }else{
		 flag[index]=true;
		 return true;
	 }
 }
 
   //横着遍历矩阵 每次检查每行充不重复
	private  boolean  isValidRow(char[][] board) {
	for(int i=0;i<9;i++){
		boolean[] flag= new boolean[10];
		for(int j=0;j<9;j++){
			if(!markFlag(flag,board[i][j])){
				return false;
			}
		}
	}
	return true;
	}
	 //竖着遍历矩阵 每次检查每列重不重复
	private boolean isValidColumn(char[][] board){
		for(int i=0;i<9;i++){
			boolean[] flag= new boolean[10];
			for(int j=0;j<9;j++){    //改成j i即可
				if(!markFlag(flag,board[j][i])){
					return false;
				}
			}
		}
		return true;
		}
	//遍历矩阵 检查所有小九宫格充不重复
	private boolean isValidBox(char[][] board){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				boolean[] flag=new boolean[10];
				for (int m = 0; m<3;m++) {
					for(int n=0;n<3;n++){
						if(!markFlag(flag, board[i*3+m][j*3+n])){
							return false;
						}
					}
					
				}
			}
		}
		return true;}}
