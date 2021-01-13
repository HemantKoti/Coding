#include "Dictionary.h"

Dictionary *createNode()
{
    int i;
    Dictionary *newNode = (Dictionary *)malloc(sizeof(Dictionary));
    newNode->isEndOfWord = false;
    for (i = 0; i < 26; i++)
        newNode->children[i] = NULL;
    return newNode;
}

Dictionary *createDictionary()
{
    return createNode();
}

void insertWord(Dictionary *d, char *word)
{
    int i = 0;
    int idx;
    while (word[i] != '\0')
    {
        int idx = word[i] - 'a';
        if (d->children[idx] == NULL)
            d->children[idx] = createNode();
        d = d->children[idx];
        i++;
    }
    d->isEndOfWord = true;
}

void printWordsFromANode(Dictionary *root, string prefix)
{
    int i;
    if (root->isEndOfWord)
        printf("\n%s", prefix);
    for (i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            int prefixLen = prefix.size();
            char *newPrefix = (char *)malloc(prefixLen + 2);
            strcpy(newPrefix, prefix.c_str());
            newPrefix[prefixLen] = i + 'a';
            newPrefix[prefixLen + 1] = '\0';
            printWordsFromANode(root->children[i], newPrefix);
            free(newPrefix);
        }
    }
}

void printAllWords(Dictionary *d)
{
    printWordsFromANode(d, "");
}

void autoSuggest(Dictionary *d, string prefix)
{
    int i = 0;
    while (prefix[i] != '\0')
    {
        int idx = prefix[i] - 'a';
        if (d->children[idx] == NULL)
        {
            printf("\nNo word starting with prefix '%s'", prefix);
            return;
        }
        d = d->children[idx];
        i++;
    }

    printWordsFromANode(d, prefix);
}
