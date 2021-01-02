#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

queue<Node *> q;

Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

int hasBothChild(Node* temp)
{
    return temp && temp->left && temp->right;
}

void insertInFullBinaryTree(Node**root, int data)
{
    Node *temp = newNode(data);

    if (!*root)
        *root = temp;
    else
    {
        Node* front = q.front();

        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;

        if (hasBothChild(front))
            q.pop();
    }
    q.push(temp);
}

bool isPresent(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->key == key)
        return true;

    if (isPresent(root->left, key))
        return true;

    return isPresent(root->right, key);
}

bool findPath(Node *root, vector<int> &path, int k)
{
    if (root == NULL)
        return false;

    path.push_back(root->key);

    if (root->key == k)
        return true;

    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;

    path.pop_back();

    return false;
}

struct Node *findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->key == n1 || root->key == n2)
        return root;

    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

void printResult(Node *root, int x, int y)
{
    if (root == NULL || isPresent(root, x) == false || isPresent(root, y) == false)
    {
        cout << "-1" << endl;
        return;
    }

    vector<int> v1, v2;
    bool b1, b2;

    Node *lca = findLCA(root, x, y);

    if (x < y)
    {
        b1 = findPath(lca, v1, x);
        b2 = findPath(lca, v2, y);
    }
    else
    {
        b1 = findPath(lca, v1, y);
        b2 = findPath(lca, v2, x);
    }

    for (int i = v1.size() - 1; i >= 0; i--)
    {
        cout << v1.at(i) << " ";
    }

    for (int i = 1; i < v2.size(); i++)
    {
        cout << v2.at(i) << " ";       
    }
    cout << endl;
}

int main()
{    
    int x, y, N, M, data;
    Node *root = NULL;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        insertInFullBinaryTree(&root, data);
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y;
        printResult(root, x, y);
    }
    delete(root);
    return 0;
}
