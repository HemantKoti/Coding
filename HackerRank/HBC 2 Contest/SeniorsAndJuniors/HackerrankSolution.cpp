#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

typedef struct LinkedListNode LLNode;
struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
};

LLNode *createNode(int data)
{
    LLNode *temp = (LLNode *) malloc(sizeof (LLNode));
    temp ->data = data;
    temp -> next = NULL;
    return temp;
}

LLNode *sortedInsertDesc(LLNode *head, int data)
{    
    LLNode *originalHead = head;
    LLNode *backUp = head;
    LLNode *temp = createNode(data);

    if (head == NULL)
    {
        return temp;
    }

    if(data > head -> data)
    {
        temp -> next = head;
        return temp;
    }

    while (head -> next)
    {
        if(data < head -> data && data > head -> next -> data)
        {
            backUp = head -> next;
            head -> next = temp;
            temp -> next = backUp;
            return originalHead;
        }
        head = head -> next;
    }
    if(data < head -> data)
    {
        head -> next = temp;
    }
    return originalHead;
}

void printList(LLNode *head)
{
    if(head == NULL)
    {
        cout << -1 << endl;       
        return;
    }
    while (head != NULL)
    {
		cout << head -> data << " " ;
        head = head -> next;
    }
    cout << endl;    
}

LLNode *printChain(LLNode *head,int key)
{    
    LLNode *prev = NULL;
    LLNode *originalHead = head;
    bool found = false;
    if(head == NULL)
    {
        printList(head);
        return NULL;
    }
    if(head -> data == key)
    {
        printList(head);
        return NULL;
    }
    while(head -> next)
    {
        if(head -> data == key)
        {
            found = true;
            break;
        }
        prev = head;
        head = head -> next;
    }
    if(found || head -> data == key)
    {
        prev -> next = NULL;
        printList(head);
        return originalHead;
    }
    else if(!found && head -> data != key)
    {
       cout << -1 << endl;      
    }
    return originalHead;
}

int main()
{   
    LLNode *head = NULL;
    int key, data, N, M;   
    cin >> N >> M;
    for(int j = 0; j < N; j++)
    {
        cin >> data;
        head = sortedInsertDesc(head,data);
    }
    for(int j = 0; j < M; j++)
    {
        cin >> key;
        head = printChain(head,key);
    }
    return 0;
}
