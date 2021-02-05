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
    for (int i = 0, idx; word[i] != '\0'; i++)
    {
        idx = word[i] - 'a';
        if (d->children[idx] == NULL)
            d->children[idx] = createNode();
        d = d->children[idx];
    }
    d->isEndOfWord = true;
}

void printWordsFromANode(Dictionary *root, string prefix)
{
    if (root->isEndOfWord)
        cout << prefix << endl;

    for (int i = 0; i < 26; i++)
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
    for (int i = 0, idx; prefix[i] != '\0'; i++)
    {
        idx = prefix[i] - 'a';
        if (d->children[idx] == NULL)
        {
            cout << "No word starting with prefix " << prefix << endl;
            return;
        }
        d = d->children[idx];
    }

    printWordsFromANode(d, prefix);
}
