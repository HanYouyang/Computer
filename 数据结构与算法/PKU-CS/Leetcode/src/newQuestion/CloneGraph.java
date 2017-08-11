package newQuestion;

import java.util.ArrayList;
import java.util.HashMap;

//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 
//深克隆一个无向图
//图里每个node有一个label  label是唯一的 . 还有一个ArrayList<UndirectedGraphNode> neighbors
//这个arraylist存的是neighbors 

//    1
//   / \
//  /   \
// 0 --- 2
//      / \
//      \_/
//{0,1,2#1,2#2,2}. 在leetcode是 因为是undirected的图 所以在neighbour里不重复记录
//0的neighbour是 1,2,| 1是2,|2是2 重复的就不记录了
public class CloneGraph {
//	1.因为label是唯一的 所以建一个hashmap<label,Node> 然后递归调用方法 cloneGraphHelper(node, map).
//	在里面根据node的值newNode了 之后 再遍历老node的邻居们,如果在map里有就加到newNode的 arraylist neighbor里，
//	如果没有 就递归调用本方法  newnode.neighbors.add(cloneGraphHelper(point,map));

//dfs
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
		if (node == null) {
			return null;
		}

		// 这个hashmap是存<原node.label,new复制出来的node>
		// 因为label 是unique的 所以可以当key
		HashMap<Integer, UndirectedGraphNode> map = new HashMap<Integer, UndirectedGraphNode>();
		return cloneGraphHelper(node, map);

	}

private UndirectedGraphNode cloneGraphHelper(UndirectedGraphNode node,HashMap<Integer, UndirectedGraphNode> map){
	//深克隆第一个节点
	
	UndirectedGraphNode newnode=new UndirectedGraphNode(node.label);
	map.put(node.label,newnode);
	//遍历给你的这个node里德neighbors
	for(UndirectedGraphNode point:node.neighbors){
	//如果map里面已经有这个neighbours了	(记住 map里面的node都是新建出来的 不是老的)
		if(map.containsKey(point.label)){
			//吧neighbor的放到新node的neighbour里
			newnode.neighbors.add(map.get(point.label));
		}else{
			//没有这node的话 递归调用本方法将node的这个邻居也放到图里还加 最后返回的node加到邻居里
			newnode.neighbors.add(cloneGraphHelper(point,map));
			
		}
	}
return newnode;
}




}

class UndirectedGraphNode {
	int label;
	ArrayList<UndirectedGraphNode> neighbors;

	UndirectedGraphNode(int x) {
		label = x;
		neighbors = new ArrayList<UndirectedGraphNode>();
	}
}