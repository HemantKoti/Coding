using System;

namespace StackQueue
{
    internal class Stack
    {
        private int[] elements;
        private int top, max;

        public int Count { get => top + 1; }

        public Stack(int size)
        {
            this.elements = new int[size];
            this.top = -1;
            this.max = size;
        }

        public void Push(int element)
        {
            if (this.top == max - 1)
                throw new StackOverflowException();

            elements[++top] = element;
        }

        public int Pop()
        {
            if (top == -1)
                throw new InvalidOperationException("Empty Stack");

            return elements[top--];
        }

        public int Peek()
        {
            if (top == -1)
                throw new InvalidOperationException("Empty Stack");

            return elements[top];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            if (args is null)
                throw new ArgumentNullException(nameof(args));

            Stack stack = new(5);

            stack.Push(10);
            stack.Push(20);
            stack.Push(30);

            while (stack.Count != 0)
                Console.WriteLine(stack.Pop());
        }
    }
}
