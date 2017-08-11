package newQuestion;

import java.util.Random;

//一个linkedlist 除了next之外还有一个random指针 可以指向任意节点 包括自己/null
//Return a deep copy of the list. 

//做法1 1. 用hashmap存新的点和老的点的影射关系
//做法2.每个node都把自己.next复制一个自己（node。Next=node） 
//然后他们的random指向原来node的后一点。 然后再把复制的点和原来的点分开来  

//比方说  1-1'-2-2'-3-3'
//       3    2    null   假设 3 2 null是 123的random指向  
//那么复制节点后 random怎么深复制呢？
//head.next.random=head.random.next;
//eg    1’.random=1.random.next=3.next=3' 就深复制了

public class Copylistwithrandompointer {
	public RandomListNode copyRandomList(RandomListNode head) {

		if (head == null) {
			return null;
		}
		copyNext(head);
		copyRandom(head);
		return splitList(head);
	}

	private void copyNext(RandomListNode head) {
		while (head != null) {
			// 新节点是new出来的
			RandomListNode newNode = new RandomListNode(head.label);
			// 注意 这里只是加了一个引用 是浅拷贝 不是深拷贝
			newNode.random = head.random;
			newNode.next = head.next;
			head.next = newNode;
			head = head.next.next;// head 跳过1‘ 更新成2
		}
	}

	private void copyRandom(RandomListNode head) {
		while (head != null) {
			// head.next 就是复制的那些 1’ 2’ node了
			if (head.next.random != null) {
				// 关键！1'2’们的random都变成深克隆了
				head.next.random = head.random.next;
			}
			head = head.next.next;// head 跳过1‘ 更新成2

		}
	}

	// 把 1-1'-2-2'-3-3' 拆开来
	// 1'-2'-3'
	private RandomListNode splitList(RandomListNode head) {
		RandomListNode newHead = head.next;
		while (head != null) {
			RandomListNode temp = head.next; //1'
			head.next = temp.next;// temp.next是2
			head = head.next;  //head往后移一位
			if (temp.next != null) { // 2.next!=null
				temp.next = temp.next.next;//1'连上2' 下一个while里再检查head和3.next是不是null 
				
			}
		}
		return newHead;
	}

}

class RandomListNode {
	int label; // 相当于value
	RandomListNode next, random;

	RandomListNode(int x) {
		this.label = x;
	}
}