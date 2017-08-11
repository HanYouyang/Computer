package frequency_4;
//
//Given an integer, convert it to a roman numeral.
//(eg:2123=MMCXXIII)
//Input is guaranteed to be within the range from 1 to 3999.

//把integer变成罗马数字
//这题和之前把integer变成英语来表述一样
//1.先准备词库（数字和string都从大到小）
 
public class IntegerToRoman {

	 public String intToRoman(int num) {
		 //罗马词库里 不靠组合 和单独字符对应的就这些数字
		 int[] values={1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
		 String[] numerals={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		 StringBuilder resultBuilder=new StringBuilder();
		 //2.因为value是从到大到小的 所以可以这么比 当num比词库里的最大值大的时候 减去这个最大值然后
		 //stringbuilder里面append这个string 然后循环 直到减成0
		 for(int i=0;i<values.length;i++){
				while(num>=values[i]){
					num=num-values[i];
					resultBuilder.append(numerals[i]);
			} 
		 }
		 return resultBuilder.toString();}
		 
		 
	public static void main(String[] args) {
	System.out.print((new IntegerToRoman()).intToRoman(2123));
}
	
	
}
