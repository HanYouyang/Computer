package frequency_4;

//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

//DP做法 参考135硬币组成N分 第一个方法用了1个会怎么样 第一个方法用了2个会怎么样
//or参考 CC8_2
//注意有一点业务逻辑上的限制 就是 26可以算2和6 B+F 或者Z 26 但是27 就只能算2+7了
//还有单单一个0是不可以被decode的要被忽略，比方说9 0 9 
//---------------------第二种做法 
public class DecodeWays {

	public int numDecodings(String s) {
		int n = s.length();
		if (n == 0) {
			return 0;
		}
		//f是存当String到第几char位的时候 此时有多少种decoding方法
		int[] f = new int[n + 1];// 多加一个防止溢出
		f[0] = 1;
		if (isValidDecoding(s.substring(0, 1))) {
			f[1] = 1;
		} else {
			f[1] = 0;
		}
		
		//因为要i-1,又不能 
		for (int i = 2; i <= n; i++) {
			if (isValidDecoding(s.substring(i - 1, i))) {
				//假如只有1位是valid的 那么解法没有变多 
				f[i] = f[i - 1];
			}
			if (isValidDecoding(s.substring(i - 2, i))) {
				//假如2也可以的的话 f[i]=f[i-1]+f[i-2]
				//但是2可以1也肯定 可以 又 1已经f[i]=f[i-1]了
				//所以			f[i] = f[i] + f[i - 2];
				//深入理解    为何说是f[i-1]+f[i-2]
				//因为 假如说i-2,i是合法的话 那么 到i位为止--(毕竟F[i]是f是存当String到第几char位的时候 此时有多少种decoding方法)
				//那么f【i】的数量此时应该是 当到f[i-2]时候  有decode了2个单位数字 和在f[i-2]时候 又decode了一个.所以是f[i] + f[i - 2]
				f[i] = f[i] + f[i - 2];
			}
		}

		return f[n];

	}

	// 判断当前iterator到的这1位或者2位是否能被合法的decoding
	// 比方说 光有一个‘0’是肯定不可以被decode的 要被|忽略|
	private boolean isValidDecoding(String s) {
		if (s.charAt(0) == '0') {
			return false;
		}
		int code = Integer.parseInt(s);
		// 不管是1位还是2位换成int了之后在1～26之间就能正常decode
		return (code >= 1 && code <= 26);
	}

	public static void main(String[] args) {
		System.out.print((new DecodeWays())
				.numDecodings("12303232434343212121222"));
	}

}
