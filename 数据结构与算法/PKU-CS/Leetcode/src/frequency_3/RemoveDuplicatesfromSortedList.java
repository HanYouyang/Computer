
package frequency_3;
//Given a sorted linked list, delete all duplicates such that each element appear only once. 
//双指针 快慢， 快的每回合都走一步 慢的只有在快慢不等的时候才后移一位
//然后把快的val复制过来 然后当快的走到底的时候慢的直接 慢.next==null


public class RemoveDuplicatesfromSortedList {
	// 因为是sorted 所以只要前后比就可以
	
	public ListNode deleteDuplicates(ListNode head) {
		if (head == null) {
			return null;
		}
		//双指针
		ListNode prev = head;
		ListNode current = head.next;
		// 不重复
		while (current != null) {
			if (prev.val != current.val) {
				prev = prev.next;
				prev.val = current.val;
			}
			current = current.next;
		}
		prev.next = null;
		return head;
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
