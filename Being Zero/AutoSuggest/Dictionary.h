#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct _dictionary
{
    bool isEndOfWord;
    struct _dictionary *children[26];
} Dictionary;

Dictionary *createDictionary();
void insertWord(Dictionary *d, char *word);
void printAllWords(Dictionary *d);
void printWordsFromANode(Dictionary *root, string prefix);
void autoSuggest(Dictionary *d, string prefix);

#endif // DICTIONARY_H_INCLUDED
