#include "Dictionary.h"

int showMenu()
{
    int choice;
    printf("\n\tMENU");
    printf("\n\t====");
    printf("\n\t1. Add Word.");
    printf("\n\t2. Print All Words.");
    printf("\n\t3. Auto Suggest.");
    printf("\n\t4. Exit.");
    printf("\n\n\tYour Choice: ");
    scanf("%d", &choice);
    return choice;
}

void DoAddWord(Dictionary *d)
{
    char word[200];
    printf("\tEnter word to insert: ");
    scanf("%s", word);
    insertWord(d, word);
}

void DoAutoSuggest(Dictionary *d)
{
    // char prefix[200];
    string prefix;
    cout << "Enter a prefix: ";
    cin >> prefix;
    autoSuggest(d, prefix);
}

int main()
{
    int choice;
    Dictionary *d = createDictionary();
    while (true)
    {
        choice = showMenu();
        switch (choice)
        {
        case 1:
            DoAddWord(d);
            break;
        case 2:
            printAllWords(d);
            break;
        case 3:
            DoAutoSuggest(d);
            break;
        case 4:
            return 0;
        default:
            printf("\nBAD CHOICE!! TRY AGAIN!!\n");
        }
    }
    return 0;
}
