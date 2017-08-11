package frequency_2;

import java.awt.List;

import javax.annotation.PostConstruct;

//Reverse a linked list from position m to n. Do it |in-place| and |in one-pass.|
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//  //把2～4之间的node给交换了 
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ≤ m ≤ n ≤ length of list. 
//  这题最要紧的就是 在反转当中那段 mn后，成为了 1 n m end
//把 1-n和 m-end 连起来 是最关键的。 比方说 1->2->3->4->5 反转 2～4 成为 
// 1->4->3->2->5  那么 1->4的连接和2->5的连接 这些要搞好 所以就要记录
//第一段最后一个节点(第m-1个node)，反转段首节点(第m个node)，反转段首尾节点(标准反转做法return的newnode)，
//和最后段第一个节点(标准反转做法next.next)

public class ReverseLinkedListII {
	public ListNode reverseBetween(ListNode head, int m, int n) {
		if (head == null || m >= n) {
			return null;
		}
		ListNode dummy = new ListNode(-1);
		dummy.next = head;
		head = dummy;
		// 检查 是否还没到m链表就结束了
		for (int i = 1; i < m; i++) {
			if (head == null) {
				return null;
			}
			head = head.next;
		}
		// for循环结束后 head在m点之前的那个node
		ListNode premNode = head;
		ListNode mNode = head.next; // m 节点本身
		ListNode nNode = mNode;
		ListNode postnNode = mNode.next;// n之后的那个node
		// 开始处理m n段
		for (int i = m; i < n; i++) {
			if (postnNode == null) {
				return null;// 如果还没到n LL就结束了 那么返回null
			}
			// 正常的linkedlist反转 但是同步吧postnNode 和nNode都往后一个循环推后一次
			ListNode temp = postnNode.next;
			postnNode.next = nNode;
			nNode = postnNode;
			postnNode = temp;
		}

		
		mNode.next=postnNode;//2->5连起来
				premNode.next=nNode;//1->4连起来
				return dummy.next;
				
						
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

// 未完成的代码2
// if (head == null||m>=n) {
// return null;
// }
// ListNode dummy =new ListNode(-1);
// dummy.next=head;
// ListNode preBegin=dummy;// 这个preBegin就是标记第一段最后一个节点
// int currentIndex=1;
// while(preBegin!=null&&currentIndex<m){
// preBegin=preBegin.next; //因为一开始等于dummy （.next=head）
// currentIndex++; //所以第一个循环后才是1
// //循环m-1次--preBegin是m-1
// }
// ListNode reverseEnd=preBegin.next; //反转段首节点(第m个node)
// ListNode reHead=null;//反转后的头
// ListNode cur=preBegin.next;
//
// //http://blog.csdn.net/fightforyourdream/article/details/17332977
// //记得发答案后来更新
//

// 有错的代码1
// public ListNode reverseBetween(ListNode head, int m, int n) {
// if (head == null) {
// return null;
// }
// ListNode DH = new ListNode(0);
// DH.next = head;
// ListNode prev1 = null;
// while (m > 1) {
// prev1 = head;
// head = head.next;
// m--;
// n--;
// }
//
// ListNode newHead = null;
// ListNode reverseEnd = head;
//
// ListNode unreversed = null;
// while (n > 1) {
// ListNode next = head.next;
// head.next = newHead;
//
//
// newHead = head;
// head = next;
// n--;
// unreversed=next;
// }
// if (prev1 != null)
// prev1.next = newHead;
//
// if (reverseEnd != null) {
// reverseEnd.next = unreversed;
// }
//
// return DH.next;
//
// }
// }