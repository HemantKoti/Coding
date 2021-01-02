#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX 22000


char names[MAX][22];
int nameSize = 0;
int connection[MAX][MAX];
bool visited[MAX];
bool isConnectedToProfessor[MAX];

int getIndex(char name[])
{
    int i;
    for (i = 0; i < nameSize; i++)
        if (strcasecmp(names[i], name) == 0)
            return i;
    return -1;
}

bool addName(char name[])
{
    int i = getIndex(name);
    if (i == -1)
    {
        strcpy(names[nameSize], name);
        nameSize++;
        return true;
    }
    return false;
}

void addConnection(char name1[], char name2[])
{
    int i = getIndex(name1);
    int j = getIndex(name2);
    if (connection[i][j] != 1)
    {
        connection[i][j] = 1;
        connection[j][i] = 1;
    }
}

char *trimwhitespace(char *str)
{
    char *end;
    while (isspace(*str)) str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;

    *(end + 1) = 0;

    return str;
}

void DFSWithProfessor(int i, int K)
{
    visited[i] = true;
    isConnectedToProfessor[i] = true;
    for(int j=0; j < nameSize; j++)
    {
        if(K > 0 && !visited[j] && (connection[i][j] == 1 || connection[j][i] == 1))
        {
            DFSWithProfessor(j,K - 1);
        }
    }
}

void DFS(int i)
{
    visited[i] = true;
    printf("%s ",names[i]);
    for(int j=0; j < nameSize; j++)
    {
        if(!isConnectedToProfessor[j] && !visited[j] && (connection[i][j] == 1 || connection[j][i] == 1))
        {
            DFS(j);
        }
    }
}

bool checkFriends(char name1[], char name2[])
{
    int i = getIndex(name1);
    int j = getIndex(name2);
    if (connection[i][j] == 1 || connection[j][i] == 1)
    {
        return true;
    }
    return false;
}


int main(int argc, char** argv)
{
    int N, K, index;
    scanf("%d %d ",&N,&K);
    fflush(stdin);
    char frnd1[22], frnd2[22];
    char str[100];
    for(int i = 0; i < N ; i++)
    {
        if(fgets(str,100,stdin)){
		char *friends;
		friends = strtok(str, " ,._");
        strcpy(frnd1, friends);
        friends = strtok(NULL, " ,._");
        strcpy(frnd2, friends);
        addName(trimwhitespace(frnd1));
        addName(trimwhitespace(frnd2));
        addConnection(trimwhitespace(frnd1), trimwhitespace(frnd2));
		}      
    }

    for(int i = 0; i < nameSize ; i++)
    {
        if(names[i][0] == 'd' && names[i][1] == 'r')
        {
            isConnectedToProfessor[i] = true;
            for(int j = 0; j < nameSize ; j++)
            {
                if(connection[i][j] || connection[j][i])
                {
                    index = getIndex(names[j]);
                    DFSWithProfessor(index,K - 1);
                }
            }
        }
    }

    fill_n(visited,nameSize,false);

    bool flag = false;
    for(int i = 0; i < nameSize ; i++)
    {
        if(!isConnectedToProfessor[i] && !visited[i])
        {
            flag = true;
            index = getIndex(names[i]);
            DFS(index);
        }
    }

    if(flag == false)
    {
        printf("-1\n");
    }
    return (EXIT_SUCCESS);
}

