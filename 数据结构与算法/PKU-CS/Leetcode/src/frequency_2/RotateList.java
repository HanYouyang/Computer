package frequency_2;
// Given a list, rotate the list to the right by k places, where k is
// non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
// rotate 一个LL n位. 或者说n次 每次rotate一位
public class RotateList {
// 首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，
	//将整个圈连起来，接着往前跑len – k%len，从这里断开，就是要求的结果了。
//
	
	// 比方说1-2-3-4 旋转2次成为 3-4-1-2
//   1--2--3--4  找到尾巴 把尾巴连到头形成环
//   |--------|
//然后再找到2位置 让那个   rotateHead =2.next(3) 然后 ==null
//最后return rotate
	public ListNode rotateRight(ListNode head, int n) {
		if (head == null) {
			return null;
		}
		int length = getLength(head);
		// 保证了n的合法性
		n = n % length;
		 ListNode back = head;  
	        ListNode front = head;  
	        ListNode end = head;  
	          
	        // 先把链表改为循环链表  
	        while(front.next != null){  
	            front = front.next;  
	        }  
	        end = front;        // 记录原尾节点  eg 4
	        front.next = head;  // 形成环  
	        front = head;       // 复原front指针   eg1
	          
	        // 使得front在back前面n个距离  
	        for(int i=0; i<n; i++){  
	            front = front.next;   //此时 front会到旋转后的头 eg 3
	        }  
	          
	        // 双指针同步移动  
	        while(front != end){  
	            front = front.next;    //移到front=end 此时 
	            back = back.next;  //请记住back 一开始是0 ,当 front=end时候 back是2
	        }  
	          
	        ListNode rotateHead = back.next;        // 找到rotate之后的链表头  
	        back.next = null;           // 切开循环链表  
	        return rotateHead;  
	}

	// 求 LL长度 mod要用
	private int getLength(ListNode head) {
		int length = 0;
		while (head != null) {
			length++;
			head = head.next;
		}
		return length;
	
	
	}
	 public static void main(String[] args) {  
	        ListNode head = new ListNode(1);  
	        ListNode n2 = new ListNode(2);  
	        ListNode n3 = new ListNode(3);  
	        ListNode n4 = new ListNode(4);  
	        ListNode n5 = new ListNode(5);  
	        head.next = n2;  
	        n2.next = n3;  
	        n3.next = n4;  
	        n4.next = n5;  
	          
	        ListNode rotateHead = new RotateList().rotateRight(head, 2);  
	       // rotateHead.print();  
	    }  
	 
	
}
