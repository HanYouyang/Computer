package frequency_1;

import java.util.ArrayList;

import javax.naming.spi.DirStateFactory.Result;

//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//
//click to show corner cases.
//Corner Cases:
//
//    Did you consider the case where path = "/../"?
//    In this case, you should return "/".
//    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//    In this case, you should ignore redundant slashes and return "/home/foo".

//简化unix 下的路径名  实现题 
//在unix里 . 表示 当前文件夹 ..表示parent文件夹  光一个/ 表示root
//所以 /a/./b/../../c/ --> 
//  a/还是a/b/回上一层变a 再回上一层变root/c 所以简化成 /c
//知道题意后 就容易做了  "/+" 拆分后(就已经没有 )  新建一个 paths String[]
// 然后扫描原数组 如果是. 或者空 就不动， 如果是.. 就remove path最后一个
// 如果是正常的字母就存入arraylist
//最后每个paths都插入/ 就行
public class SimplifyPath {
	public String simplifyPath(String path) {
			StringBuilder sb =new StringBuilder();
			sb.append("/");
			String[] stubs=path.split("/+"); //正则 碰到不管几个/都分割一次
	ArrayList<String> paths=new ArrayList<String>();
	for(String s:stubs){
		if(s.equals("..")){  
		if(paths.size()>0){
			paths.remove(paths.size()-1);
		}
		}else if(!s.equals(".")&&!s.equals("")){
			paths.add(s);
		}
		}  //for循环结束 path 完成
	
	for(String string:paths){
		sb.append(string).append("/");
	}
		if(sb.length()>1){   //最后会多append一个 "/"
			sb.deleteCharAt(sb.length()-1);
		}
		return sb.toString();
	}
}
