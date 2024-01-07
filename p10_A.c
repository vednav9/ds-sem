//DFS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[20][20], n, visited[20];
char name[20];

int stack[20], top = -1;

void DFS(int v) // v is index of start vertex
{
    int j;
    stack[++top] = v;
    visited[v] = 1;
    while (top != -1) // stack not empty
    {
        v = stack[top--]; // remove from stack
        printf("%c->", name[v]);
        for (j = 1; j <= n; j++)
        {
            if (a[v][j] != 0 && visited[j] == 0)

            {

                stack[++top] = j; // push to stack
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    int i, j, ch;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    printf("\n Enter name of vertex:");
    for (i = 1; i <= n; i++)
        scanf(" %c", &name[i]);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    while (1)
    {
        printf("\n-- Graph Traversal Operation ----");
        printf("\n1.DFS Traversal \n 2.Exit");
        printf("\n Please Enter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++) // initially each vertex unvisited
                visited[i] = 0;
            for (i = 1; i <= n; i++) // ensure each vertex visited
                if (visited[i] == 0)
                    DFS(i);
            break;

        case 2:
            exit(0);
        }
    }
    return 0;
}