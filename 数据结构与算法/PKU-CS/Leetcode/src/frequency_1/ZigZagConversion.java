package frequency_1;
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
/*输入是  123456789 3层
 * 1   5   9
 * 2 4 6 8 10
 * 3   7   11 
 * 
 * 输出 1592468103711
 *  
 */
public class ZigZagConversion {
/*一个数学题 面试不太会考 
 * 直观的算法，写一下不同行数下的例子就能找到规律了。

 nRows = 2
0 2 4 6 ...    一个zig可以认为是0 1  or  2 3
1 3 5 7

 nRows = 3
0   4   8  ...   一个zig可以人认为 0123
1 3 5 7 9
2   6   10

 nRows = 4
0     6       12 ...  一个zig可以认为是012345
1   5 7    11
2 4   8 10  
3     9
 * 
 * 观察可知 zigSize = nRows + nRows – 2
 * 然后因为一共有1～n行 
 * 第一行就只放每个zig的第一个字符 最后一行也只放每个zag的
 * 当中的那些行 (假设为i行) 那么第一个字符就是 每个zig的第i个字符
 * 第二个在ir行的字符 在每个zig第一个字符在String里位置 +zigSize – 2*ir
 * 
 * 
 */
	
	
	
public String convert(String s, int nRows) {
   int length=s.length();
   if(length<=nRows||nRows==1){
	   return s;
   }
char[] chars=new char[length];
int step=2*nRows-2;
int count=0;
for(int i=0;i<nRows;i++){
	int interval=step-2*i;//这个interval指的是 在一个zig里 在1～n-1行里 同一行同一个zig里2个字母在string里的位置 
//	 nRows = 3   eg  1和3的差距 就是step-2×i
//			 0   4   8  ...   一个zig可以人认为 0123
//			 1 3 5 7 9
//			 2   6   10
	                        //每次循环下一次都就是到下一个zip里了
	                        //一次for循环是一个zip
	for(int j=i;j<length;j=j+step){
		chars[count]=s.charAt(j);  //eg 这里如果输入1
		count++; //每次插入之后 count就++了
		//如果大于step就不在本zig内了                      //输入都在合法位置
		if(interval<step&&interval>0&&j+interval<length&&count<length){
			//count已经移到下一位 
			chars[count]=s.charAt(j+interval);//eg：这里就是输入3
			count++;
		}
	}
}
return new String(chars);







}
}
