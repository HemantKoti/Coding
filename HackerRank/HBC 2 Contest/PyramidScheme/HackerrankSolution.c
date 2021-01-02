#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100000

typedef struct node Node;
struct node
{
    int data;
    struct node *right,*left;
};

struct Queue
{
    int front, rear;
    int size;
    Node**array;
};

Node* newNode(int data)
{
    Node* temp = (Node*) malloc(sizeof( Node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (Node**) malloc(queue->size * sizeof( Node* ));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{
    return queue->rear == queue->size - 1;
}

int hasOnlyOneItem(struct Queue* queue)
{
    return queue->front == queue->rear;
}

void Enqueue(Node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

Node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;

    Node* temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}

Node* getFront(struct Queue* queue)
{
    return queue->array[queue->front];
}


int hasBothChild(Node* temp)
{
    return temp && temp->left && temp->right;
}

void insertInFullBinaryTree(Node **root, int data, struct Queue* queue)
{
    Node *temp = newNode(data);
    if (!*root)
        *root = temp;

    else
    {
        Node* front = getFront(queue);
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;
        if (hasBothChild(front))
            Dequeue(queue);
    }
    Enqueue(temp, queue);
}

bool isPresent(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (isPresent(root->left, key))
        return true;

    return isPresent(root->right, key);
}

bool findPath(Node *root, int arr[], int *top, int k)
{
    if (root == NULL)
        return false;

    //path.push_back(root->key);
	arr[(*top)++] = root -> data;

    if (root->data == k)
        return true;

    if ((root->left && findPath(root->left, arr, top, k)) || (root->right && findPath(root->right, arr, top, k)))
        return true;

    //path.pop_back();
	(*top)--;

    return false;
}

struct Node *findLCA(Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
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
        printf("-1\n");
        return;
    }

    //vector<int> v1, v2;
	int arr1[SIZE], arr2[SIZE];
	int i,arrTop1 = 0, arrTop2 = 0;
    bool b1, b2;

    Node *lca = findLCA(root, x, y);

    //printf("LCA : %d\n",lca -> data);
    if (x < y)
    {
        b1 = findPath(lca, arr1, &arrTop1, x);
        b2 = findPath(lca, arr2, &arrTop2, y);
    }
    else
    {
        b1 = findPath(lca, arr1, &arrTop1, y);
        b2 = findPath(lca, arr2, &arrTop2, x);
    }
    //printf("Top 1 : %d Top 2 : %d\n",arrTop1,arrTop2);
    for (i = arrTop1 - 1; i >= 0; i--)
    {
        printf("%d ",arr1[i]);
    }

    for (i = 1; i < arrTop2; i++)
    {
        printf("%d ",arr2[i]);
    }
    printf("\n");
}


int main()
{    
    int i,x, y, N, M, data;
    Node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    scanf("%d %d ",&N,&M);
    for ( i = 0; i < N; ++i)
    {
        scanf("%d ",&data);
        insertInFullBinaryTree(&root, data,queue);
    }
    for (i = 0; i < M; ++i)
    {
        scanf("%d %d ",&x,&y);
        printResult(root, x, y);
    }
    free(root);
    return 0;
}
