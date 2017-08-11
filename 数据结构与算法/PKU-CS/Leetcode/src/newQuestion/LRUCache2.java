package newQuestion;

import java.util.HashMap;
import java.util.Map;

public class LRUCache2 {
    
    private LRUNode head;  //dummy head
    private LRUNode tail;   ///dummy head
    private Map<Integer,LRUNode> map;
    private final int capacity;
    private int size=0;
    
    
    private class LRUNode{
        private int key;
        private int value;
        private LRUNode prev=null;
        private LRUNode next=null;
    
    public LRUNode(int key,int val){
        this.key=key;
        this.value=val;
        prev=null;
        next=null;
        
    }
    }
    public LRUCache2(int capacity) {
        this.capacity=capacity;
        this.head =new LRUNode(0,0);
        
        this.tail=new LRUNode(0,0);
        head.next=tail;
        tail.prev=tail;
        this.map=new HashMap<Integer,LRUNode>();
        
    }
    
    public int get(int key) {
       LRUNode node=map.get(key); 
       if(node==null){
           return -1;
       }else{ //update visted 
           remove(node);
           insert(node);
           return node.value;
       }
    }
    
    public void set(int key, int value) {
      LRUNode node=map.get(key);
      if(node==null){
          node=new LRUNode(key,value);
        map.put(key,node);
        insert(node);
         size++;
         if(size>capacity){
             //remove dummy tails's prev
         
             map.remove(tail.prev.key);
         remove(tail.prev);
         size--;
         }
         
          }

      
    }
    
    private void remove(LRUNode node){
        node.prev.next=node.next;
        node.next.prev=node.prev;
    }
    //insert betwean dummy head and old real head
    private void insert(LRUNode node){
        node.next=head.next;
        head.next=node;
        node.prev=head;
        node.next.prev=node;
        
        
    }
    
    public static void main(String[] args) {
		LRUCache2 liquidCache2=new LRUCache2(100);
		liquidCache2.set(12, 22);
		
	}
}