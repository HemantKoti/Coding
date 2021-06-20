using System;

namespace Tree.Test
{
    class Program
    {
        public static void Main(string[] args)
        {
            if (args is null)            
                throw new ArgumentNullException(nameof(args));

            BinaryTree bt = new();
            TreeNode root = new(10);
            root.left = new TreeNode(11)
            {
                left = new TreeNode(7)
            };

            root.right = new TreeNode(9)
            {
                left = new TreeNode(15),
                right = new TreeNode(8)
            };

            Console.WriteLine("Inorder traversal before insertion");
            bt.Inorder(root);

            // Insert new elements
            bt.Insert(root, 12);
            bt.Insert(root, 16);
            bt.Insert(root, 17);
            bt.Insert(root, 18);

            Console.WriteLine("\nInorder traversal after insertion");
            bt.Inorder(root);

            // Delete node
            bt.Delete(root, 8);

            Console.WriteLine("\nInorder traversal after deletion");
            bt.Inorder(root);
        }
    }
}
