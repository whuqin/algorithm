/**
 * sort a linked list in O(nlogn) time using constant space complexity
 * 单向链表归并排序，双向链表快速排序
 * Created by qinbin on 2017/5/31.
 */
public class SortList {
    ListNode sortList(ListNode listNode) {
        if (listNode == null || listNode.next == null) {
            return listNode;
        }
        ListNode fast = listNode;
        ListNode slow = listNode;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        //断开
        fast = slow;
        slow = slow.next;
        fast.next = null;
        ListNode l1 = sortList(listNode);
        ListNode l2 = sortList(slow);
        return merge2List(l1, l2);
    }

    ListNode merge2List(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode head = new ListNode();
        for (ListNode tmp = head; l1 != null || l2 != null; tmp = tmp.next) {
            int val1 = l1 == null ? Integer.MAX_VALUE : l1.val;
            int val2 = l2 == null ? Integer.MAX_VALUE : l2.val;
            if (val1 <= val2) {
                tmp.next = l1;
                l1 = l1.next;
            } else {
                tmp.next = l2;
                l2 = l2.next;
            }
        }
        return head.next;
    }

}
