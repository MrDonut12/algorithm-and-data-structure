



class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummyNode = new ListNode(0);
        for (int i = 0; i < lists.length; i++) {
            ListNode current = lists[i];
            while (current.next != null) {
                ListNode curr = dummyNode;
                ListNode nextNode = current.next;

                while (curr.next != null && curr.next.val < current.val) {
                    curr = curr.next;
                }

                current.next = curr.next;
                curr.next = current;

                current = nextNode;

            }
        }

        return dummyNode.next;
    }
}
