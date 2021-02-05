#include <cstdbool>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef struct dictionary Dictionary;

struct dictionary
{
    bool isEndOfWord;
    struct dictionary *children[3];
};

FILE *fp;

Dictionary *createDictionary()
{
    Dictionary *newNode = new Dictionary;
    newNode->isEndOfWord = false;
    for (int i = 0; i < 3; i++)
        newNode->children[i] = NULL;
    return newNode;
}

void insertWord(Dictionary *root, string word)
{
    for (int i = 0, idx; i < word.size(); i++)
    {
        idx = word[i] - 'a';
        if (root->children[idx] == NULL)
            root->children[idx] = createDictionary();
        root = root->children[idx];
    }

    root->isEndOfWord = true;
}

bool findMismatch(Dictionary *root, string word, bool mismatch)
{
    if (word[0] == '\0' && root->isEndOfWord)
        return mismatch;
    if (word[0] == '\0')
        return false;

    int idx = word[0] - 'a';
    if (!mismatch)
    {
        for (int i = 0; i < 3; i++)
        {
            if (root->children[i] != NULL)
            {
                if (findMismatch(root->children[i], word.substr(1), (idx != i)))
                    return true;
            }

            return false;
        }
    }
    else
    {
        if (root->children[idx] != NULL)
            return findMismatch(root->children[idx], word.substr(1), true);
    }

    return false;
}

int main()
{
    // freopen("C:\\Users\\Hemant Koti\\Documents\\DataStructuresCompetition\\WattoAndMechanism\\input\\input16.txt", "r", stdin);
    // fp = fopen("C:\\Users\\Hemant Koti\\Documents\\DataStructuresCompetition\\WattoAndMechanism\\output\\output16.txt", "w+");
    int N, Q;
    cin >> N >> Q;

    string word;
    Dictionary *root = createDictionary();

    while (N--)
    {
        cin >> word;
        insertWord(root, word);
    }

    while (Q--)
    {
        cin >> word;
        // findMismatch(root, word, false) ? fprintf(fp, "YES\n") : fprintf(fp, "NO\n");
        findMismatch(root, word, false) ? cout << "Yes" << endl : cout << "No" << endl;
    }

    return 0;
}
