package frequency_3;

import java.util.ArrayList;

import javax.management.loading.PrivateClassLoader;

import org.omg.CORBA.PUBLIC_MEMBER;

//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
//给一个string 求能有这个string里组成的所有的合法ip

//
//
//首先我们要明确传统IP 地址的规律是分4个Part，每个Part是从0-255的数字
//
//0-255的数字，转换成字符，即每个Part 可能由一个字符组成，二个字符组成，
//或者是三个字符组成。那这又成为组合问题了，dfs便呼之欲出
//每一个枝桠深到最后就是一个dfs
//所以我们写一个For循环每一层从1个字符开始取一直到3个字符，
//再加一个isValid的函数来验证取的字符是否是合法数字，如果是合法的数字，
//我们再进行下一层递归，否则跳过


public class RestoreIPAddresses {

	
	
	public ArrayList<String> restoreIpAddresses(String s) {
       ArrayList<String> result=new ArrayList<String>();
       //不能组成合法ip地址
       if (s.length()<4||s.length()>12) {
	return result;}
		dfs(s,"",result,0);
       return result;
	
	}                              //暂时存储未完整的IP(枝桠)
      private void dfs(String s,String temp, 
    		                             //ip 0段1 段 2段 3段
    		  ArrayList<String> result,int count){
      //结束条件    //count=3 ip4段都加完了
    	  if(count==3&&isValid(s)){
    		  result.add(temp+s);
    		  return;
    	  }
    	  //dfs
      for(int i=1; i<4&&i<s.length();i++){
    	  String onePartOfIP =s.substring(0,i);//前闭后开 01，02，03
          if(isValid(onePartOfIP)){
        	 //原string减去被用掉的  //空加上用掉的                               //一共四段
        	  dfs(s.substring(i), temp+onePartOfIP+'.', result, count+1);
               }  
            }
        }
	
	private boolean isValid(String s){
		if(s.charAt(0)=='0'){  //192.0.0.1 可以。 192.00.00.1 不可以
			return s.equals("0");
		}
		Long num=Long.valueOf(s);
		return num<=255&&num>0;
	}
	
	}



