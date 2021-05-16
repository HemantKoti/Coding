using System;

namespace Queue
{
    internal class Queue
    {
        private int[] elements;
        private int front, rear, max;

        public int Count { get => rear - front + 1; }

        public Queue(int size)
        {
            this.elements = new int[size];
            this.front = 0;
            this.rear = -1;
            this.max = size;
        }

        public void Enqueue(int element)
        {
            if (rear == max - 1)
                throw new OverflowException("Queue overflow");

            this.elements[++rear] = element;
        }

        public int Dequeue()
        {
            if (front == rear + 1)
                throw new InvalidOperationException("Empty Queue");

            return this.elements[front++];
        }

        public int Peek()
        {
            if (front == rear + 1)
                throw new InvalidOperationException("Empty Queue");

            return this.elements[front];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            if (args is null)            
                throw new ArgumentNullException(nameof(args));

            Queue queue = new(5);
            queue.Enqueue(10);
            queue.Enqueue(20);
            queue.Enqueue(30);
            queue.Enqueue(40);
            
            while (queue.Count != 0)
                Console.WriteLine(queue.Dequeue());
        }
    }
}
