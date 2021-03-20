using System;

namespace CircularLinkedList
{

    internal class CicularLinkedList
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

        internal void InsertNode(int data)
        {
            ListNode oHead = this.head;
            ListNode temp = new(data);
            if (head == null)
            {
                temp.next = temp;
                head = temp;
                return;
            }

            while (head.next != oHead)
                head = head.next;

            head.next = temp;
            temp.next = oHead;
            head = oHead;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
