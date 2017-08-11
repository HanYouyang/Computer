package frequency_2;
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place?
public class RotateImage {
	
//要将矩阵旋转90度，最简单的做法是一层层旋转，对每一层执行换装旋转
	//上边移到右边，右边移到下边，下边移到左边，左边移到上边
	//你可以把边复制到一个数组中，然后移边，但是这要O（N） 更好的做法是按照索引进行交换
	//eg for i=0 to n
//	  temp=top[i];
//	  top[i]=left[i];
//	  left[i]=bottom[i];
//	  bottom[i]=right[i];
//	  right[i]=temp;
//从外面的层逐渐向里,在每一层上执行上述交换	
	  public void rotate(int[][] matrix) {
		 //在leetcode里这题是NxN的矩阵
		  int n= matrix.length;
		 //一个4x4的矩阵是内外2层 那么一个NxN的矩阵 layer的数量是N/2
		  for(int layer=0;layer<n/2;++layer){ //外循环 层数变大
			  int first=layer;
			  int last=n-1-layer;//下标 -layer
		  for(int i=first;i<last;++i){   //first是层数,i是本层中的位置
			  int offset=i-first;//offset是位移的意思
		      //储存上边
			  int top=matrix[first][i];
		      //左到上 
			  matrix[first][i]=matrix[last-offset][first];
			  //下到左
			  matrix[last-offset][first]=matrix[last][last-offset]; 
			  //右到下
			  matrix[last][last-offset]=matrix[i][last];
			  //上到右
			   matrix[i][last]=top;
		  
		  
		  }
		  
		  }
		  
		  
	  }
	  
}
