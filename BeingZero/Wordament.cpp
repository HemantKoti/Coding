#include <iostream>
#include <string>
#include <cstring>

#define N 4
#define WORD_SIZE 4

using namespace std;

char board[N][N];
bool flag[N][N];
char word[WORD_SIZE * WORD_SIZE + 1];

void getWordsStartingAtIndex(int i, int j, int index)
{
    if (i < 0 || i > N - 1 || j < 0 || j > N - 1)
        return;
        
    if (flag[i][j])
        return;

    word[index++] = board[i][j];
    word[index] = '\0';

    if (strlen(word) >= WORD_SIZE)
    {
        cout << word << endl;
        return;
    }

    flag[i][j] = true;

    for (int r = -1; r <= 1; r++)
        for (int c = -1; c <= 1; c++)
            getWordsStartingAtIndex(i + r, j + c, index);

    flag[i][j] = false;
}

void wordCombinations()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            getWordsStartingAtIndex(i, j, 0);
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << endl;
    }
}

void readBoard()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
}

// ../Materials/CPS - 2/Problem - 14 - Wordament.pdf
int main()
{
    cout << "Enter the characters: " << endl;
    readBoard();
    printBoard();
    wordCombinations();
    return 0;
}