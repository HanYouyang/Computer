package frequency_3;
 

public class RemoveDuplicatesfromSortedList2 {
//	1个dummyhead.next=4指针 pre(最后去完重的链表的头节点)  realpre curr next   3个node都往右，  我们先用非编程的思想考虑问题。
//			只有完全唯一的node才能保留，那么 这个node （假设不是最前或者最后）他要和前后node都不一样才可以视作唯一（pre curr next依次平移检查）
//			(第一次比较的初始状态就是dummyhead,head,head.next)。
//			那么我们可以拿不断平移的node来检查哪些node是eligibal的。出循环后（pre.next=null;防止还连着老链表）最后再检查尾巴。   在返回dummyhead.next
	

	
	public static ListNode deleteDuplicates(ListNode head) {
		if (head == null) {
			return null;
		}
		// 检查是否只有一个节点的情况
		if (head.next == null) {
			return head;
		}
		//ps 你不是 pre curr next 三个指针检查么  那么dummy head的正确用法就是 dh。next=head 然后dh是pre ！！！ head是curr！！ head。next是next！！！ 
		// 4 pointers  dummyHead要是设一个 和后面不会重复的的值 然后在pre curr next系统里就是pre  原来head就是 curr
		ListNode dummyHead = new ListNode(Integer.MIN_VALUE);
		dummyHead.next=head;
		ListNode pre = dummyHead;
	    ListNode realpre=dummyHead;
		ListNode curr = pre.next; //就是head
		ListNode next = curr.next; //head.next
 
	

		while (next != null) {
			if (curr.val != realpre.val && curr.val != next.val) {
				// 能进这块说明 curr是unique的
				pre.next = curr;
				pre=pre.next;
				
			}
		
	        realpre=realpre.next;
			curr = curr.next;
			next = next.next;
			
		}
		//这样是防止pre后面还是连着老链表
		pre.next=null;
		// 处理最后一位
		if (curr.val != realpre.val) {
			pre.next = curr;
		}

		return dummyHead.next;
	}

	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode n1 = new ListNode(2);
		ListNode n2 = new ListNode(3);
		ListNode n3 = new ListNode(3);
//		ListNode n4 = new ListNode(3);
//	ListNode n5 = new ListNode(4);
//		ListNode n6 = new ListNode(5);
		head.next = n1;
		n1.next = n2;
		n2.next = n3;
//    	n3.next = n4;
//		n4.next = n5;
//	n5.next = n6;

		print(head);
		ListNode h = deleteDuplicates(head);
		System.out.println();
		print(h);
	}

	static void print(ListNode a) {
		while (a != null) {
			System.out.print(a.val);
			a = a.next;
		}

	}

	static class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	}
}


//做法2 各种神奇的判断
// public class RemoveDuplicatesfromSortedList2 {
// public ListNode deleteDuplicates(ListNode head) {
// if(head==null){
// return null;
// }
// ListNode dummyHead=new ListNode(0);
// //3 pointers
// dummyHead.next=head;
// ListNode pre=dummyHead;
// ListNode curr=pre.next;
// ListNode next=curr.next;
//
// boolean duplicate=false;
// while(true){
// if(next==null){
// break;
// }
// if(curr.val!=next.val){
// if(duplicate){
// pre.next=next;
// duplicate=false;
// }else{
// pre=curr;
// }
// curr=next;
// next=next.next;
//
// } else if(curr.val==next.val){
// duplicate=true;
// next=next.next;
// }
// }
// // 扫尾工作，针对于例如{1,1}的情况，最后再判断一次
// if(duplicate){
// pre.next=next;
// }
// return dummyHead.next;
// }
