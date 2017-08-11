package frequency_5;
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
//把2个sort好的linkedlist合并成一个sort好的linkedlist  类似 mergesort
public class Merge2SortedList {

	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if (l1 == null && l2 == null) {
			return null;
		}
		if (l1 == null && l2 != null) {
			return l2;
		}
		if (l1 != null && l2 == null) {
			return l1;
		}
		// 这个root 是dummy head 为了方便编程，是空的，最后 返回的是head.next
		ListNode head = new ListNode(0); // root 到最后会变成指向linkedlist倒数第二个节点
		ListNode root = head;
		while (l1 != null && l2 != null) {
             //不要忘了 都是先建好 root.next = 你要的东西 然后再把 root.next设为root 下次实际上等于是说root。next。next=。。。。
			if (l1.val <= l2.val) {
				root.next = new ListNode(l1.val);
				root = root.next;
				l1 = l1.next;
			} else {
				root.next = new ListNode(l2.val);
				root = root.next;
				l2 = l2.next;
			}

		}
		if (l1 == null) {
			if (l2 != null) {
				root.next = l2;
			}
		} else if (l2 == null) {
			if (l1 != null) {
				root.next = l1;
			}
		}

		return head.next;
	}

	public static void main(String[] args) {
		ListNode root1  = new ListNode(2);
		
		ListNode root2  = new ListNode(1);
		System.out.print((new Merge2SortedList().mergeTwoLists(root1, root2)).val);
	}

}

class ListNode {
	int val;
	ListNode next;

	// ListNode() {
	// val = 0;
	// next = null;
	// }

	ListNode(int x) {
		val = x;
		next = null;
	}
}
