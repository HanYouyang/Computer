package frequency_5;
//检查一个string是否是回文 eg:racecar
//also we define empty string as valid palindrome.
//"a." 是回文 因为  considering only alphanumeric characters and ignoring cases. 
public class ValidPalindrome {

	public boolean isPalindrome(String s) {
		if ((s.trim()).equals("") || s == null) {
			return true;
		}
		// STRING 先要处理 去除非alphanueric的 和空格
		String temp = s.toLowerCase();
//		for (int i = 0; i < temp.length(); i++) {
//			if (!((temp.charAt(i) >= '0' && temp.charAt(i) <= '9') || (temp
//					.charAt(i) >= 'a' && temp.charAt(i) <= 'z'))) {
//				temp.replace(temp.charAt(i), ' ');
//				System.err.print(i);
//			}
//		}
//		System.err.print(temp);
//		String withoutSpaceString = temp.replace("$", "");
//
//		withoutSpaceString = withoutSpaceString.replace(" ", "");
		 
		int start = 0;
		int end = temp.length() - 1;
		while (start <= end) {
			if (((temp.charAt(start) >= '0' && temp.charAt(start) <= '9') || (temp
					.charAt(start) >= 'a' && temp.charAt(start) <= 'z'))
					&& ((temp.charAt(end) >= '0' && temp.charAt(end) <= '9') || (temp
							.charAt(end) >= 'a' && temp.charAt(end) <= 'z'))) {
				if (temp.charAt(start) != temp.charAt(end)) {
					return false;
				}
				start++;
				end--;
			}else{
				if(!((temp.charAt(start) >= '0' && temp.charAt(start) <= '9') || (temp
						.charAt(start) >= 'a' && temp.charAt(start) <= 'z'))){
					start++;
				}
				if(!((temp.charAt(end) >= '0' && temp.charAt(end) <= '9') || (temp
							.charAt(end) >= 'a' && temp.charAt(end) <= 'z'))){end--;}
			}
		}
		return true;

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print((new ValidPalindrome()).isPalindrome("avavba"));
		System.out.print((new ValidPalindrome()).isPalindrome2("ab"));
	}
	
	
    public boolean isPalindrome2(String s) {
        if(s==null){return false;}
        if(s.length()==0||s.trim().equals("")){
            return true;
        }
        s=s.toLowerCase();
      StringBuilder chars=new StringBuilder();
      for(int i=0;i<s.length();i++){
          if(s.charAt(i)>='a'&&s.charAt(i)<='z'||s.charAt(i)>='0'&&s.charAt(i)<='9'){
              chars.append(s.charAt(i));
          }
      }
      String string=chars.toString();
      System.err.println(string);
      if(string.length()==0){
     	 return true;
      }
    int start=0;
    int end=string.length()-1;
    System.err.println(start+","+end);
    while(start<=end){
        if(string.charAt(start)!=string.charAt(end)){
            return false;
        }
        start++;
        end--;
    }
 return true;}

}
