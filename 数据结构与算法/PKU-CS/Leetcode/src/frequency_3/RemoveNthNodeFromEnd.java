package frequency_3;

//删除LL倒数第N个 Node
//   Given linked list: 1->2->3->4->5, and n = 2.
// result                1->2->3->5.
public class RemoveNthNodeFromEnd {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		// 要弄个dummy head 来处理要删的正好是头节点的情况
		ListNode dummyHead = new ListNode(0);
		dummyHead.next = head;
		ListNode fast = head;
		ListNode slow = head;
		for (int i = 0; i < n; i++) {
			if (fast.next == null) { 
				//请注意 fast.next==null 说明什么 因为n题目告诉你valid 所以移动n次
				//后fast.next==null说明fast已经到最后 n  就是linkedlist的数量 所以要删的就是头节点。
				return head.next;
			}
			fast = fast.next;
		}
	 
		while (fast.next != null) {
			 
			fast = fast.next;
			slow = slow.next;
		}

	slow.next = slow.next.next;   
		return dummyHead.next;
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