class Node {
    int data;
    Node next;

    public Node(int x) {
        this.data = x;
        this.next = null;
    }
}

class MyClass {
    Node head;
    Node tail;

    public MyClass() {
        head = null;
        tail = null;
    }

    public void addLast(Node x) {
        x.next = null;

        if (head == null) {
            head = x;
            tail = x;
            return;
        }

        tail.next = x;
        tail = x;
    }

    public void traverse() {
        Node current = head;

        while (current != null) {
            System.out.printf("%d ", current.data);
            current = current.next;
        }

        System.out.println();
    }

    public Node getHead() {
        return head;
    }
}

public class AddTwoNumber {

    public MyClass addTwoNumbers(MyClass l1, MyClass l2) {
        MyClass answer = new MyClass();

        Node i1 = l1.getHead();
        Node i2 = l2.getHead();

        int carry = 0, num1, num2;

        while (i1 != null || i2 != null) {
            num1 = (i1 == null) ? 0 : i1.data;
            num2 = (i2 == null) ? 0 : i2.data;


            System.out.printf("%d %d\n", num1, num2);

            int sum = num1 + num2 + carry;

            carry = sum / 10;
            int pushNum = sum % 10;

            answer.addLast(new Node(pushNum));

            if (i1 != null) i1 = i1.next;
            if (i2 != null) i2 = i2.next;
        }

        if (carry > 0) {
            answer.addLast(new Node(carry));
        }

        return answer;
    }

    public static void main(String[] args) {
        MyClass list1 = new MyClass();
        MyClass list2 = new MyClass();

        int[] test1 = {9, 9, 9, 9, 9, 9, 9};
        int[] test2 = {9, 9, 9, 9};

        for (int i = 0; i < 7; i++) {
            list1.addLast(new Node(test1[i]));
        }
        for (int i = 0; i < 4; i++) {
            list2.addLast(new Node(test2[i]));
        }

        AddTwoNumber a = new AddTwoNumber();

        MyClass answer = a.addTwoNumbers(list1, list2);
        answer.traverse();
    }
}


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;
        int num1, num2, carry = 0;
        while (i1 != null || i2 != null) {
            num1 = (i1 == null) ? 0 : i1.val;
            num2 = (i2 == null) ? 0 : i2.val;
            int sum = num1 + num2 + carry;

            carry = sum / 10;
            Node pushNum = new Node(sum % 10);
            curr.next = pushNum;

            if (i1 != null) i1 = i1.next;
            if (i2 != null) i2 = i2.next;
        }

        if (carry > 0) {
            curr.next = new Node(carry);
        }

        return dummyHead.next;
    }

    public MyClass addTwoNumbers(MyClass l1, MyClass l2) {
        MyClass answer = new MyClass();

        Node i1 = l1.getHead();
        Node i2 = l2.getHead();

        int carry = 0, num1, num2;

        while (i1 != null || i2 != null) {
            num1 = (i1 == null) ? 0 : i1.data;
            num2 = (i2 == null) ? 0 : i2.data;


            System.out.printf("%d %d\n", num1, num2);

            int sum = num1 + num2 + carry;

            carry = sum / 10;
            int pushNum = sum % 10;

            answer.addLast(new Node(pushNum));

            if (i1 != null) i1 = i1.next;
            if (i2 != null) i2 = i2.next;
        }

        if (carry > 0) {
            answer.addLast(new Node(carry));
        }

        return answer;
    }
}
