using System;
using static LinkedList.LinkedList;

namespace LinkedList
{
    internal class LinkedList
    {
        internal ListNode head;

        internal class ListNode
        {
            internal int data;
            internal ListNode next;

            internal ListNode(int data)
            {
                this.data = data;
                this.next = null;
            }
        }

        internal void InsertInTheEnd(int data)
        {
            ListNode originalHead = this.head;
            ListNode temp = new ListNode(data);

            if (this.head == null)
            {
                this.head = temp;
                return;
            }

            while (this.head.next != null)
                this.head = this.head.next;

            this.head.next = temp;
            this.head = originalHead;
        }

        internal void InsertInTheBeginning(int data)
        {
            ListNode temp = new ListNode(data);
            if (this.head == null)
            {
                this.head = temp;
                return;
            }

            temp.next = this.head;
            this.head = temp;
        }

        internal void DisplayList()
        {
            ListNode originalHead = head;

            while (head != null)
            {
                Console.Write(this.head.data + " ");
                this.head = this.head.next;
            }

            Console.WriteLine();
            this.head = originalHead;
        }

        internal int Size()
        {
            int count = 0;
            ListNode originalHead = head;
            while (head != null)
            {
                count++;
                this.head = this.head.next;
            }

            this.head = originalHead;
            return count;
        }

        internal bool Find(int data)
        {
            ListNode originalHead = head;
            while (this.head.next != null)
            {
                if (this.head.data == data)
                {
                    this.head = originalHead;
                    return true;
                }

                this.head = this.head.next;
            }

            this.head = originalHead;
            return false;
        }

        internal ListNode Random()
        {
            Random rd = new Random();
            int index = rd.Next(this.Size());

            for (int i = 0; i < index; i++)
                this.head = this.head.next;

            return this.head;
        }

        internal ListNode Last()
        {
            ListNode last = head;

            while (last.next != null)
                last = last.next;

            return last;
        }

        internal void DeleteNode(int data)
        {
            ListNode originalHead = this.head, prev = null;
            if (!this.Find(data))
            {
                Console.WriteLine($"Cannot find the node: {data}");
                return;
            }

            if (this.head.data == data)
            {
                this.head = this.head.next;
                return;
            }

            while (head != null)
            {
                if (head.data == data)
                {
                    prev.next = head.next;
                    break;
                }

                prev = head;
                head = head.next;
            }

            this.head = originalHead;
        }

        internal ListNode InsertCycle()
        {
            ListNode last = this.Last(), random = this.Random();
            last.next = random;

            return this.head;
        }

        internal bool DetectCycle()
        {
            ListNode slow = this.head, fast = this.head;

            while (slow != null && fast != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast)
                    return true;
            }

            return false;
        }

        internal ListNode MergeSortedList(ListNode a, ListNode b)
        {
            ListNode head = null;

            if (a == null)
                return b;
            else if (b == null)
                return a;

            if (a.data <= b.data)
            {
                head = a;
                head.next = this.MergeSortedList(a.next, b);
            }
            else
            {
                head = b;
                head.next = this.MergeSortedList(a, b.next);
            }

            return head;
        }

        private void Split(ListNode head, ref ListNode front, ref ListNode back)
        {
            ListNode fast = null, slow = null;
            ListNode oHead = head;

            if (head == null || head.next == null)
            {
                front = head;
                back = null;
            }
            else
            {
                slow = head;
                fast = head.next;

                while (fast != null)
                {
                    fast = fast.next;
                    if (fast != null)
                    {
                        slow = slow.next;
                        fast = fast.next;
                    }
                }

                front = head;
                back = slow.next;

                slow.next = null;
            }
        }

        internal void MergeSort(ref ListNode head)
        {
            ListNode temp = head, a = null, b = null;

            if (temp == null || temp.next == null)
                return;

            this.Split(temp, ref a, ref b);

            MergeSort(ref a);
            MergeSort(ref b);

            head = MergeSortedList(a, b);
        }

        internal ListNode Reverse()
        {
            ListNode prev = null, current = this.head, oHead = this.head;

            if (this.head == null)
                return head;

            while (this.head != null)
            {
                this.head = current.next;
                current.next = prev;
                prev = current;
                current = this.head;
            }

            this.head = oHead;
            return prev;
        }

        internal ListNode MergeAlternateNodes(ListNode a, ListNode b)
        {
            ListNode head = null;

            if (a == null)
                return b;
            else if (b == null)
                return a;

            head = a;
            head.next = this.MergeAlternateNodes(b, a.next);

            return head;
        }

        internal void RemoveCycle(LinkedList head)
        {
            // To - Do
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            LinkedList ll = new LinkedList();

            ll.InsertInTheEnd(10);
            ll.InsertInTheEnd(11);
            ll.InsertInTheBeginning(100);
            ll.InsertInTheEnd(200);
            ll.DisplayList();

            ll.DeleteNode(11);
            ll.DisplayList();
        }
    }
}
