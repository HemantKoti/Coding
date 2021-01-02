#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct dictionary Node;

struct dictionary
{
    bool isEndOfWord;
    struct dictionary *children[3];
};

Node* createNode()
{
    int i;
    Node* newNode = (Node *)malloc(sizeof (Node));
    newNode->isEndOfWord = false;
    for (i = 0; i < 3; i++)
        newNode->children[i] = NULL;
    return newNode;
}

void insertWord(Node* d, char word[])
{
    int i = 0;
    int idx;
    while (word[i] != '\0')
    {
        int idx = word[i] - '1';
        if (d->children[idx] == NULL)
            d->children[idx] = createNode();
        d = d->children[idx];
        i++;
    }
    d->isEndOfWord = true;
}

bool findMismatch(Node *root, char word[], bool mismatch)
{
    int i;
    if (word[0] == '\0' && root->isEndOfWord)
        return mismatch;
    else if (word[0] == '\0')
        return 0;
    int idx = word[0] - '1';
    if (!mismatch)
    {
        for (i = 0; i < 3; i++)
            if (root->children[i] != NULL)
            {
                if (findMismatch(root->children[i], word + 1, (idx != i)))
                    return true;
            }
        return false;
    }
    else
    {
        if (root->children[idx] != NULL)
            return findMismatch(root->children[idx], word + 1, true);
    }
    return false;
}

int main()
{
    int N, Q;
    int i = 0;
    scanf("%d %d ", &N, &Q);
    char stringCode[1000];
    Node *root = createNode();
    while (N--)
    {
        scanf("%s ", stringCode);
        stringCode[strlen(stringCode)] = '\0';
        insertWord(root, stringCode);
    }
    while (Q--)
    {
        scanf("%s ", stringCode);
        stringCode[strlen(stringCode)] = '\0';
        printf(findMismatch(root, stringCode, 0) ? "YES\n" : "NO\n");
    }
    return 0;
}
