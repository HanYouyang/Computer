//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

//和CC150 2_4完全一样



package frequency_4;

import java.util.LinkedList;

 

 



public class AddTwoNumbers {

	
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	
		 
	   return addTwoNumbers(l1, l2, 0);
	}
	
	public ListNode addTwoNumbers(ListNode l1, ListNode l2,int carry) {
		 //carry 是进到上一位的数字 value是本位
		if(l1==null&&l2==null&&carry==0){return null;}
		  ListNode result=new ListNode(0);
		int value=carry;
		   if(l1!=null){
			 value=value+l1.val;
		   }
		   if(l2!=null){
				 value=value+l2.val;
			   }
		   //先设为0 然后如果value大于等于10 carry设为1
		   carry=0;
		   if(value>9){
			   carry=1;
		      value=value%10;
		   }
		   //更新正确的result的value
		   result.val=value; //这样是ok的 因为 就算n1 n2都是null value=carry; 也执行过了
			ListNode following = addTwoNumbers(l1 == null ? null : l1.next,
					l2== null ? null : l2.next,
				            carry);
		
			result.next=following;
			
	return result;}
	
	public static void main(String[] args) {
		ListNode l1=new ListNode(3);
		ListNode l2=new ListNode(4);
		ListNode l3=new ListNode(7);
		l1.next=l2;
		l2.next=l3;
		ListNode h1=new ListNode(8);
		ListNode h2=new ListNode(9);
		ListNode h3=new ListNode(6);
		h1.next=h2;
		h2.next=h3;
		
   (new AddTwoNumbers()).addTwoNumbers(l1, h1);
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