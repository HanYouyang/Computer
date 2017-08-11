package newQuestion;

import java.awt.List;
//Sort a linked list in O(n log n) time using constant space complexity.

//merge sort 
public class SortList {
	 public ListNode sortList(ListNode head) {
	       if(head==null||head.next==null){
	    	   return head;
	       } 
	       
	       ListNode mid=findMiddle(head);
	       ListNode right=sortList(mid.next);
	       mid.next=null;  //把前后段截断 1分2
	       ListNode left=sortList(head);
	       return merge(left, right);
	    }
	 
	 private ListNode findMiddle(ListNode head){
		 ListNode slow=head;
		 ListNode fast=head.next; //fast 从2位开始 那么 2.4.6 slow 1 2 3 那么不管总长度是6还是7slow都是3
		 while(fast!=null&&fast.next!=null){
			 fast=fast.next.next;
			 slow=slow.next;
		 }
	 return slow;
	 }
	                  //两个排序完的 linkedlist merge
	 //和 merget sort一模一样 
private ListNode merge(ListNode head1,ListNode head2){
	ListNode dummy= new ListNode(-1);
	ListNode tail=dummy;
	while(head1!=null&&head2!=null){
		if(head1.val<head2.val){
			tail.next=head1;
			head1=head1.next;
		}else{
			tail.next=head2;
			head2=head2.next;
		}
		tail=tail.next;
		}
	// 直接把多余部分连上
	if(head1!=null){
		tail.next=head1;
	}else{
		tail.next=head2;
	}
	return dummy.next;
	}
	
	 
}
