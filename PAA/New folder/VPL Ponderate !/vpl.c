#include <stdio.h>
#include <stdlib.h>
FILE *fin;

int matriceCosturi[256][256];
int n, m;

void a(int n, int m)
{
    int x,y,z;
    for(int i=0; i<m; i++)
    {
        fscanf(fin, "%d %d %d", &x, &y, &z);
        matriceCosturi[x][y] = z;
    }
}

int c(int matriceCosturi[n][n])
{
    int cont=0;
    for(int i=1; i<n; i++)
    {
        int grad=0;
        for(int j=1; j<n; j++)
        {
            if(matriceCosturi[i][j]==1);
            grad++;
        }
        if(grad == n-1)
            cont++;
    }
    return cont;
}

int main()
{
    fin=fopen("lista.txt", "r");
    if(fin == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    /** subunct a **/
    fscanf(fin, "%d %d", &n, &m);
    a(n,m);

    /** subunct b **/
    printf("Matricea Costurilor:\n");
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            printf("%d ", matriceCosturi[i][j]);
        }
        printf("\n");
    }

    /** subunct c **/
    printf("Numar noduri de grad n-1: %d", c(matriceCosturi));

    fclose(fin);
    return 0;
}
