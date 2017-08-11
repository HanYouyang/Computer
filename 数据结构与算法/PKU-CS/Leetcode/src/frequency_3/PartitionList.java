package frequency_3;

//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5. 

//给定一个单项链表与一个值x，划分这个链表使得所有比x小的node都在所有比x大的node的前面。同时注意保持节点原有的相对位置关系
public class PartitionList {
//四指针 一开始 left leftDM right rightDM 都是纯dummy 然后
	public ListNode partition(ListNode head, int x) {
		if (head == null) {
			return null;
		}
		ListNode leftDummy = new ListNode(0);
		ListNode rightDummy = new ListNode(0);
		ListNode left = leftDummy;
		ListNode right = rightDummy; //这时候 leftDummy和 left/ rightDummy和right是同一个对象 
		//然后当第一次进while循环的时候执行25或者28行，此时他们的.next都更新成当时的head
		//然后left/right这个reference被改成head了,那么以后再对left.next/right.next改动都Ldummy/Rdummy无关了
		while (head != null) {
			if (head.val < x) {
				left.next = head;
				left = head;  //这样比x小的都会连在left上,并且保持了顺序
			} else {
				right.next = head; // 比x大的都会连在right上 ,并且保持了顺序
				right = head;
			}
			head = head.next;
		}
		
// 
//leftDym.next     left
//        |         |
//		  1 -> 2 -> 2 
//rightDym.next     right
//         |         | 
//		   4 -> 3 -> 5
		
		right.next = null; 
		left.next = rightDummy.next;
		return leftDummy.next;
	}
}
