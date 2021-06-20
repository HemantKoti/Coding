using System;
using System.Collections.Generic;

namespace Tree
{
    public class TreeNode
    {
        public int key;
        public TreeNode left, right;

        public TreeNode(int key)
        {
            this.key = key;
            this.left = this.right = null;
        }
    }

    /*
     * Types of Binary Tree
     * Full Binary Tree: A Binary Tree is a FBT if every node has 0 or 2 children.
     * 
     * Complete Binary Tree: A Binary Tree is a CBT if all the levels are completely filled 
     * except possibly the last level and the last level has all keys as left as possible.
     * 
     * Perfect Binary Tree: A Binary tree is a PBT in which all the internal nodes have 
     * two children and all leaf nodes are at the same level. 
     * 
     * Balanced Binary Tree: A binary tree is balanced if the height of the tree is O(Log n) 
     * where n is the number of nodes. For Example, the AVL tree maintains O(Log n) height 
     * by making sure that the difference between the heights of the left and right subtrees 
     * is at most 1. Red-Black trees maintain O(Log n) height by making sure that the number 
     * of Black nodes on every root to leaf paths is the same and there are no adjacent red nodes. 
     * Balanced Binary Search trees are performance-wise good as they provide O(log n) time 
     * for search, insert and delete. 
     * 
     * A degenerate (or pathological) tree: A Tree where every internal node has one child. 
     * Such trees are performance-wise same as linked list. 
     * 
     * Properties of a Binary Tree
     * The maximum number of nodes at level ‘l’ of a binary tree is 2 ^ l.
     * 
     * The Maximum number of nodes in a binary tree of height ‘h’ is 2 ^ h – 1. 
     * 
     * In a Binary Tree with N nodes, minimum possible height or the minimum number 
     * of levels is Log2(N+1).
     * 
     * A Binary Tree with L leaves has at least = Log2(L) | + 1 levels.
     * 
     * In Binary tree where every node has 0 or 2 children, the number of leaf nodes is 
     * always one more than nodes with two children.
     */
    public class BinaryTree
    {
        TreeNode root;

        public BinaryTree()
        {
            this.root = null;
        }

        public void Inorder(TreeNode node)
        {
            if (node == null)
                return;

            Inorder(node.left);
            Console.Write(node.key + " ");
            Inorder(node.right);
        }

        public void Preorder(TreeNode node)
        {
            if (node == null)
                return;

            Console.Write(node.key + " ");
            Preorder(node.left);
            Preorder(node.right);
        }

        public void Postorder(TreeNode node)
        {
            if (node == null)
                return;

            Postorder(node.left);
            Postorder(node.right);
            Console.Write(node.key + " ");
        }

        public void LevelOrder(TreeNode node)
        {
            Queue<TreeNode> queue = new();
            queue.Enqueue(node);
            while (queue.Count != 0)
            {   
                TreeNode tempNode = queue.Dequeue();
                Console.Write(tempNode.key + " ");

                if (tempNode.left != null)
                    queue.Enqueue(tempNode.left);

                if (tempNode.right != null)
                    queue.Enqueue(tempNode.right);
            }
        }

        public void PrintLevelOrder(TreeNode node)
        {
            int height = Height(node);
            for (int i = 1; i <= height; i++)
                PrintCurrentLevel(node, i);
        }

        public int Height(TreeNode node)
        {
            if (node == null)         
                return 0;            
            else
            {
                int lheight = Height(node.left);
                int rheight = Height(node.right);

                return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
            }
        }

        public void PrintCurrentLevel(TreeNode node, int level)
        {
            if (node == null)
                return;

            if (level == 1)
                Console.Write(node.key + " ");
            else if (level > 1)
            {
                PrintCurrentLevel(node.left, level - 1);
                PrintCurrentLevel(node.right, level - 1);
            }
        }

        public void Insert(TreeNode node, int key)
        {
            if (node == null)
            {
                this.root = new TreeNode(key);
                return;
            }

            Queue<TreeNode> queue = new();
            queue.Enqueue(node);

            while (queue.Count != 0)
            {
                node = queue.Dequeue();

                if (node.left == null)
                {
                    node.left = new TreeNode(key);
                    break;
                }
                else
                    queue.Enqueue(node.left);

                if (node.right == null)
                {
                    node.right = new TreeNode(key);
                    break;
                }
                else
                    queue.Enqueue(node.right);
            }
        }

        private void DeleteDeepest(TreeNode node, TreeNode delNode)
        {
            Queue<TreeNode> queue = new();
            queue.Enqueue(node);

            TreeNode temp;

            while (queue.Count > 0)
            {
                temp = queue.Dequeue();

                if (temp == delNode)
                {
                    temp = null;
                    return;
                }

                if (temp.right != null)
                {
                    if (temp.right == delNode)
                    {
                        temp.right = null;
                        return;
                    }
                    else
                        queue.Enqueue(temp.right);
                }


                if (temp.left != null)
                {
                    if (temp.left == delNode)
                    {
                        temp.left = null;
                        return;
                    }
                    else
                        queue.Enqueue(temp.left);
                }
            }
        }

        public void Delete(TreeNode node, int key)
        {
            if (node == null)
                return;

            if (node.left == null && node.right == null)
            {
                if (node.key == key)
                    node = null;

                return;
            }

            TreeNode temp = null, keyNode = null;
            Queue<TreeNode> queue = new();
            queue.Enqueue(node);

            while (queue.Count > 0)
            {
                temp = queue.Dequeue();

                if (temp.key == key)
                    keyNode = temp;

                if (temp.left != null)
                    queue.Enqueue(temp.left);

                if (temp.right != null)
                    queue.Enqueue(temp.right);
            }

            if (keyNode != null)
            {
                int x = temp.key;
                DeleteDeepest(node, temp);
                keyNode.key = x;
            }
        }
    }
}
