#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool isPresent(Node *root, int key)
{
    if(root == NULL)
        return false;

    if(root->key == key)
        return true;

    if(isPresent(root->left, key))
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

    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL)? left_lca: right_lca;
}

void printResult(Node *root, int x, int y)
{
    if(root == NULL || isPresent(root, x) == false || isPresent(root, y) == false)
    {
        cout << "-1" << endl;
        return;
    }

    vector<int> v1, v2;
    bool b1, b2;

    Node *lca = findLCA(root, x, y);

    if(x < y)
    {
        b1 = findPath(lca, v1, x);
        b2 = findPath(lca, v2, y);
    }
    else
    {
        b1 = findPath(lca, v1, y);
        b2 = findPath(lca, v2, x);
    }

    for(int i = v1.size()-1; i >= 0; i--)
        cout << v1.at(i) << " ";

    for(int i = 1; i < v2.size(); i++)
        cout << v2.at(i) << " ";

    cout << endl;
}

int main()
{
    Node * root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);

    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    int T, x, y;

    cin >> T;
    while(T--)
    {
        cin >> x >> y;
        printResult(root, x, y);
    }

    return 0;
}
