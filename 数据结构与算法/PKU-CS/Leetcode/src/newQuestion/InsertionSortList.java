package newQuestion;

import java.util.Iterator;
 
//Sort a linked list using insertion sort.

public class InsertionSortList {
//insertion sort本来是将后面的未排序区按大小插入前面的半有序区
	
// 所以 比方说要排序 6543的话，先设一个dummynode -1
// 然后 //	-16  -156  -1456  -13456
	// while(head!=null){进这个大循环之后，node就一直是那个初始dummy-1
	//然后通过内while循环比大小选中要往前查的那个node
	//temp=head.next=5 然后 dummy node 的next赋给head.next 一开始dummy.next 是null 那么此时第一轮head.next也是null
	//
	
	public ListNode insertionSortList(ListNode head) {
	       ListNode dummy= new ListNode(-1); 
	 
	 while(head!=null){
		 ListNode node=dummy;

		 while(node.next!=null&&node.next.val<head.val){
			 node=node.next;
		 }  //找比head小的 插入

		 ListNode temp=head.next; 
         head.next=node.next; //比方说dummy原来指向6 现在让 head 5指向6   
		 node.next=head; //让dummy.next=一直指向当前head 5  所以现在是 dummy-5-6
		 head=temp;  //head等于 实质上的head.next 从linkedlist的下一位再排序 此时 head=4

		 }
	 
	 return dummy.next;

	 }
//	排序 6 5 4  3
//	-1
//	-16
//	-156
//	-1456
//	-13456


	 public static void main(String[] args) {
		ListNode a=new ListNode(6);
		ListNode b=new ListNode(5);
		ListNode c=new ListNode(4);
		ListNode d=new ListNode(3);
		a.next=b;
		b.next=c;
		c.next=d;
		
	InsertionSortList sort=new InsertionSortList();
	sort.insertionSortList(a);
		
	}
}
