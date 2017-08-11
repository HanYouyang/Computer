package frequency_3;
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//                         任意的
//Note: The numbers can be arbitrarily large and are non-negative.


public class MultiplyStrings {
//本位 进位思想 比如385 * 97, 就是个位=5 * 7，十位=8 * 7 + 5 * 9 ，百位=3 * 7 + 8 * 9 …
//	可以每一位用一个Int表示，存在一个int[]里面。

	
	
	//	1 翻转string
//	2 建立数组，双层循环遍历两个string，把单位的乘积累加到数组相应的位置
//	3 处理进位并输出
//	4 注意前导零的corner case
//	
//  一般乘法    21×31
//   反转后     12
//           13
//  ---------------
//           36
//          12
// --------------------
//          156 
//  又 d[i+j]=d[i+j]+(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
//      所以 d[1]=d[1][0]+d[0][1]=3×1+1×2=5
 // d[i]=正常乘法后第i本位之和  (没有进位)	
	
	public String multiply(String num1, String num2) {
//反转后 个位在最前 便于计算 
 num1=new StringBuilder(num1).reverse().toString();
 num2=new StringBuilder(num2).reverse().toString();
//even 99*99 is <10000, so 所以乘积的length肯定是 length1+length2就够用了;
 int[] d= new int[num1.length()+num2.length()];
for(int i=0;i<num1.length();i++){
	for(int j=0;j<num2.length();j++){
		d[i+j]=d[i+j]+(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
	}

} 
		
StringBuilder sb = new StringBuilder();  
for(int i=0; i<d.length; i++){  
    int digit = d[i]%10;        // 当前本位  
    int carry = d[i]/10;        // 进位 .如果d[i]>0的话 会有进到前面位去 
    if(i+1<d.length){  
        d[i+1] += carry; 
    }  
    sb.insert(0, digit);        // 因为前面反转了 num1,2 所以 每次都把当本位  插入stringbuilder的第0位 然后越后面的插到最前面
}  
		//到这里似乎完成了
//但是比方说100×100我们前面准备了6位做len3 但是只用了10000 5位
//所以会成为 010000 所以要去掉前面的0
while(sb.charAt(0)=='0'&&sb.length()>1){
	sb.deleteCharAt(0);
}
		return sb.toString();
		
}
	
}
