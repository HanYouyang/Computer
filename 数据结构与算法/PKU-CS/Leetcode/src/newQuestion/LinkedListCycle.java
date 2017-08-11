package newQuestion;

//Given a linked list, determine if it has a cycle in it.
//cc原题 龟兔指针做法 大家都从头开始走  兔每次走两步 龟每次走一步 然后 如果是直线的linkedlist
//就兔子早走完了 龟兔不会碰到  但是如果是环龟兔会碰到 

public class LinkedListCycle {
	public boolean hasCycle(ListNode head) {
    if(head==null){
    	return false;
    }
	ListNode fast=head;//一次走两步 
	ListNode slow=head;//一次走一步 
	do{
		if(fast==null||fast.next.next==null){
			//fast 走到低了 但是圆环情况下不可能走到低
	return false;
		}
		fast=fast.next.next;
	    slow=slow.next;
	}while(fast!=slow);
	//这样 如果跑到最后 fast==slow了 就是跳出循环 有环
	return true;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}