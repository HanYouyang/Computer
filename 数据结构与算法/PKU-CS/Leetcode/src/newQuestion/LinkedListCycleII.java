package newQuestion;
//和上面一样  当乌龟兔子追到后 
//兔子回到head,然后也和乌龟一样一步一步走
//他们再次相遇的一个地点 
public class LinkedListCycleII {
	 public ListNode detectCycle(ListNode head) {
	        if(head==null){
	        	return null;
	        }
 ListNode fast=head;
 ListNode slow=head;
 //前半段和cycle linked list 1一样 
 do{
	 if(fast.next==null||fast.next.next==null){
		 return null;
	 }
	 fast=fast.next.next;
	 slow=slow.next;
}while(fast!=slow);
 // 此时首尾相遇  再从头同步走起
 while(head!=slow){
	 head=head.next;
	 slow=slow.next;
 }
 return head;
	 }
}
