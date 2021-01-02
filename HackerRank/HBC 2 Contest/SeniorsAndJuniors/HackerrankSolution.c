#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode LLNode;
struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
};

LLNode *createNode(int data)
{
    LLNode *temp = malloc(sizeof (LLNode));
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
        printf("-1\n");        
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head -> data);        
        head = head -> next;
    }
    printf("\n");    
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
        printf("-1\n");        
    }
    return originalHead;
}

int main()
{   
    LLNode *head = NULL;
    int key,i,j,data,N,M;   
    scanf(" %d %d ",&N,&M);
    for(j = 0; j < N; j++)
    {
        scanf("%d ",&data);
        head = sortedInsertDesc(head,data);
    }
    for(j = 0; j < M; j++)
    {
        scanf("%d ",&key);
        head = printChain(head,key);
    }
    return 0;
}
