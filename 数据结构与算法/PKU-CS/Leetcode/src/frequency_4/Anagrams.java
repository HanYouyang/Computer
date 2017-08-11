package frequency_4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;



//Given an array of strings, return all groups of strings that are anagrams.
//
//Note: All inputs will be in lower-case.


//就是给你n个string 然后返回里面互为anagram的词 比方说 abc def bca 就返回 abc bca
//不要陷入误区 不用写判断2个string是否为anagram的方法                                                          
///用hashmap做 key是sorted后的string value是 Arraylist<String> 存放互为anagram但是的原始string
//比方说 key： abcd  value里是 bcda  和 dbca

public class Anagrams {

	
public ArrayList<String> anagrams(String[] strs) {
HashMap<String, ArrayList<String>> map=new HashMap<String, ArrayList<String>>();
ArrayList<String> result=new ArrayList<String>();
ArrayList<String> temp;
for(String s:strs){
	char[] chars=s.toCharArray();
	Arrays.sort(chars);
	String key=new String(chars);
	//key is sorted word
	//如果map里没存这个sorted word
	if(!map.containsKey(key)){
    		temp=new ArrayList<String>();
    		temp.add(s);//注意 Arraylist里加的 是原始的未排序s 不是anagram
	 map.put(key,temp);
	}else{
	map.get(key).add(s);}}

//因为map里的key是sorted过后的词 
//每个sorted词看看他的原始s有几个 大于2个的话就是互为anagram 
//
for(String s:map.keySet()){
      //是value 那个arraylist
	if(map.get(s).size()>1){
		//遍历 arraylist
		for(String string:map.get(s)){
			result.add(string);
		}
	}
}
return result;
}

    


	
 
	
	public static void main(String[] args) {
String[] strs={"","","abc","cba","da","e"};
System.out.print((new Anagrams()).anagrams(strs));
 
	}

	
	
	
}
