```cpp
                        |
1->2->3->4->5->NULL     | ListNode *slow = head, *fast = head;
^     ^                 | while (k--) {
slow  fast --->         |      if (fast == NULL) fast = head; // [1]
 |_____|                |      fast = fast->next;
    k                   | }
                        | if (fast == NULL) return head;
1->2->3->4->5->NULL     | while (fast->next) {
^     ^     ^           |      fast = fast->next;
head  slow  fast        |      slow = slow->next;
       |_____|          | }
          k             | List *new_head = slow->next;
                        | slow->next = NULL;
                        | fast->next = head;
                        | return new_head;
```

ΨһҪע�������:

[1]: ��� k > linklist.size(n) ��ô�죿

��ʾ������ʾ����ʲô�� rotate the list to the right by `k` places.

| k | origin | after |
|:-:|:------:|:-----:|
| 1 |0->1->2 |2->0->1|
| 2 |0->1->2 |1->2->0|
| 3 |0->1->2 |0->1->2|
| 4 |0->1->2 |2->0->1|

���Թ۲�ĳ������� k > n ��ʱ��`k = k % n`.

�ο����ϣ�[what to do when k is greater than size of list ?](https://oj.leetcode.com/discuss/2353/what-to-do-when-k-is-greater-than-size-of-list)
