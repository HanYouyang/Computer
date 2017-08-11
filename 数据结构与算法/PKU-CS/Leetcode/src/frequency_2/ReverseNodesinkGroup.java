package frequency_2;

import java.awt.List;
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5 

//这题是什么意思 呢 以 K个node位1组反转
//比方说k=2就是2个一组反转  1-2 翻转成2-1  3-4 反转成4-3 5因为不够2个所以不反转
//k=3就是翻转成3-2-1 后面45 不够3个不动

public class ReverseNodesinkGroup {
//先写个helper方法 这个方法的作用是反转 从pre+1 到next-1的这一段linkedlist
        /* a linked list:  0是dummy head
	     * 0->1->2->3->4->5->6
	     * |last cur   |   
	     * pre        next
	     * after call pre = reverse(pre, next)
	     * 
	     * 0->3->2->1->4->5->6
	     *          |  |
	     *          pre next
	     */
	//写法就和普通的linkedlist一样  四步while 到 cur==next跳出while
	private ListNode reverse(ListNode pre,ListNode next){
		ListNode last=pre.next; //pre-1 翻转后 next指向 next-4 
		ListNode cur=last.next;//相当于2;
		while(cur!=next){         //第一轮
			last.next=cur.next;   //1-3
		  cur.next=pre.next;      //2-1
		  pre.next=cur;           //0-2
		  cur=last.next;          //cur2变3  所以第一轮完后就是0-2-1-3 curr是3
		}               //第二轮完后就是 0-3-2-1  然后一开始就1-4了 所以0-3-2-1-4
	return last; //一直是1 while循环内没变过 因为1是连4的所以每次返回的就是下一轮的dummy node
	}
//主方法里面，遍历LL的过程中每次都计数，每次到达k个节点，就可以使用pre和head.next调用上面的方法逆转了。给跪了。
	
	
	public ListNode reverseKGroup(ListNode head, int k) {
	    if(head==null||k==1){return head;}
	    ListNode dummy =new ListNode(0);
	    dummy.next=head;
	    ListNode pre=dummy;
	    int count=0;
	    while(head!=null){
	    	count++;
	    	if(count%k==0){ //因为是从0开始计数 所以 当k=3时候0..4..7
	    		pre=reverse(pre, head.next);  // 因为helper方法传进去的时候是0,4 然后反转123
	    		//所以这里第一次初始的时候传进去0-2 1自己反转不影响, count=0  时候返回1
	    	head=pre.next;// 1.next是2   所以当count等于0时候 时间上没有反转 head 自动后移一位
	    	}else{
	    		head=head.next;
	    	}
	    }
		return dummy.next;
		
	    }
}
