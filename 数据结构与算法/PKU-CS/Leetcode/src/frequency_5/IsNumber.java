package frequency_5;
import java.util.Arrays;
//注意. Arrays.toString(char) 会返回带括号和逗号的数组形式的string 所以要，而不是一个正常string
//s = new String(temp);

//检查一个string是不是number
//题目觉得第一位可以是.但不可以是e
//题目觉得最后一位可以.但不可以是e
//string|当中|不可以有空格
//".e1"  "1e."这种也不可以 .和e不能连在一起
//"+.8" 可以
// 	"6e6.5" 不可以  e后面不能有小数点 和 但是e后面可以有标点符号

public class IsNumber {

	public boolean isNumber(String s) {
		                                              //这在double.valueOf里是可以的 但是题意不可以 所以提前去除
				if (s == null || "".equals(s) || s.endsWith("f") || s.endsWith("D")|| s.endsWith("d")|| s.endsWith("F")) {
					return false;
				}
				String source = s.trim();
				try {
					Double.valueOf(source);
					return true;
				} catch (Exception e) {
					return false;
				}
			}



	public static void main(String[] args) {
		System.out.print((new IsNumber().isNumber(" 005047e+6")));

	}

}


// 这是我做的半成品 还是wrong answer 但是我觉得这题的艹我的思想我已经理解了。
//谁有空谁可以研究下正常解的答案
//
//public boolean isNumber(String s) {
//	s = s.trim();
//	boolean hasnumber = false;
//	boolean already1e = false;
//	boolean alreadyDot = false;
//	if (s.equals("")) {
//		return false;
//	}
//
//	if (s.charAt(s.length() - 1) != '.') {
//		if (s.charAt(s.length() - 1) < '0'
//				|| s.charAt(s.length() - 1) > '9') {
//
//			return false;
//		}
//	}
//	for (int i = 0; i < s.length(); i++) {
//		// 一个数都没有肯定错
//		if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {
//			hasnumber = true;
//		}
//
//		if (s.charAt(i) == (' ')) {
//			return false;
//		} // 不可以有空格
//			// 在第一位的状态下先处理第一位 注意这种写法 很巧妙 逻辑很清晰
//		if ((i == 0)
//				&& (s.charAt(i) == 'e' || s.charAt(i) == '.'
//						|| s.charAt(i) == '-' || s.charAt(i) == '+')) {
//
//			if (s.charAt(i) == 'e') {
//				return false;
//			}
//			if (s.charAt(i) == '.') {
//
//				if (s.length() == 1 || s.charAt(i + 1) == 'e') {
//					return false;
//				}// rule out 只有一个点的情况
//				alreadyDot = true;
//				char[] temp = s.toCharArray();
//				temp[i] = '0';
//				s = new String(temp);
//
//				// continue;
//			}
//			if (s.charAt(i) == '-') {
//
//				if (s.length() == 1) {
//					return false;
//				}// rule out 只有一个'-'的情况
//				if (s.charAt(i + 1) != '.') {
//					if (s.charAt(i + 1) < '0' || s.charAt(i + 1) > '9') {
//						return false;
//					}
//				}
//
//				char[] temp = s.toCharArray();
//				temp[i] = '0';
//				s = new String(temp);
//
//				// continue;
//			}
//			if (s.charAt(i) == '+') {
//
//				if (s.length() == 1) {
//					return false;
//				}// rule out 只有一个'+'的情况
//				if (s.charAt(i + 1) != '.') {
//					if (s.charAt(i + 1) < '0' || s.charAt(i + 1) > '9') {
//						return false;
//					}
//				}
//
//				char[] temp = s.toCharArray();
//				temp[i] = '0';
//				s = new String(temp);
//
//				// continue;
//			}
//
//		}
//
//		if (i == 0 && (s.charAt(i) < '0' || s.charAt(i) > '9')) {
//			return false;
//		}
//		// e和.只能出现1次 (最后一位已经被之前处理过了)
//		if (i != 0 && s.charAt(i) == 'e') {
//			if (already1e == true || s.charAt(i + 1) == '.') {
//				return false;
//			} else {
//				already1e = true;
//				alreadyDot = true;
//				char[] temp = s.toCharArray();
//				temp[i] = '0';
//				s = new String(temp);
//			}
//
//		}
//		if (i != 0 && s.charAt(i) == '.') {
//			if (alreadyDot == true) {
//
//				return false;
//			} else {
//
//				alreadyDot = true;
//				char[] temp = s.toCharArray();
//				temp[i] = '0';
//				s = new String(temp);
//
//			}
//		}
//
//		if (s.charAt(i) < '0' || s.charAt(i) > '9') {
//			if (s.charAt(i) == '+' || s.charAt(i) == '-') {
//				if (s.charAt(i - 1) == 'e') {
//					continue;
//				}
//			}
//			return false;
//		}
//	}
//	System.err.print(s);
//	if (hasnumber == false) {
//		return false;
//	}
//	return true;
//}
