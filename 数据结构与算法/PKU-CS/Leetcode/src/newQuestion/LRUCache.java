package newQuestion;
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

import java.util.LinkedHashMap; 

//用linkedhashmap实现 ,linkedhashlist 的特性就是最老插入的在 
//int firstKey = map.keySet().iterator().next();  是第一个。然后你   map.remove(firstKey); 
//就把最老插入的那个给去掉了。 然后 提议要求删掉 least visted 那么就在get和 set的时候 
//都访问好再删掉-插入一次， 这样就符合题意了。然后满的时候 就通过iterator拿到第一个key 删之 在插入


public class LRUCache {
    LinkedHashMap<Integer,Integer> map;
    int capacity;
    
    public LRUCache(int capacity) {
     map=new LinkedHashMap<Integer,Integer>(capacity);
     this.capacity=capacity;
    }
    
    public int get(int key) {
        if(map.containsKey(key)){
            int val=map.get(key);
        
        map.remove(key);
        map.put(key,val); //reinsert the vak
        return val;
    }
 return -1;   
}
    
    public void set(int key, int value) {
        if(map.containsKey(key)){
            map.remove(key);
            map.put(key,value);
        }else{
            if(map.size()==capacity){
                int firstKey= map.keySet().iterator().next();
            map.remove(firstKey);
            }
            map.put(key,value);
        }
        
    }
}
