package newQuestion;

import java.util.Stack;

//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//You must do this in-place without altering the nodes' values.
public class ReorderList {
	  public void reorderList(ListNode head) {
	      if(head==null||head.next==null){
	    	  return;
	      }  
	      
	      ListNode dummy=new ListNode(-1);
	      dummy.next=head;
	      ListNode fast=dummy;
	      ListNode slow=dummy;
	      while(fast!=null&&fast.next!=null){
	    	  fast=fast.next.next;
	    	  slow=slow.next;
	      }
	      // 跳出这个循环了 slow正好是 一半
	      ListNode curr=slow.next;
	      slow.next=null;
	  Stack<ListNode> stack=new Stack<ListNode>();
	  // 把后半段都存入stack
	  while(curr!=null){
		  stack.push(curr);
		  curr=curr.next;
	  }
	  //存完了之后 让curr不指向head。
	  curr=head;                            //防止最当中的中点节点被重复用。
	  //curr 是前半段向后。。stack是从最后面pop向前
	  while(!stack.isEmpty()&&stack.peek()!=curr.next){
		  ListNode temp=stack.pop(); //n
		  temp.next=curr.next;//n->2
		  curr.next=temp;//1->n
		  curr=curr.next.next; //  1->n->2 ( 此时curr为2)
	  }
	  
	  }
}
