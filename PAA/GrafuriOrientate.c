#include <stdlib.h>
#include <stdio.h>
#define INF 262145

int matriceAdiacenta[256][256], vizitat[256];
int N, M;

void Dijkstra(int radacina)
{
    int distanta[256], cost[256][256], min, contor=1, next;

    vizitat[radacina]=1;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(matriceAdiacenta[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=matriceAdiacenta[i][j];

    for(int i=1; i<=N; i++)
        distanta[i]=cost[radacina][i];

    distanta[radacina]=0;

    while(contor<N-1)
    {
        min = INF;

        for(int i=0; i<N; i++)
            if(distanta[i]<min && vizitat[i]==0)
            {
                min = distanta[i];
                next=i;
            }

        vizitat[next] = 1;
        for(int i=0; i<N; i++)
            if(vizitat[i]==0)
                if(min+cost[next][i]<distanta[i])
                    distanta[i]=min+cost[next][i];

        contor++;
    }

    for(int i=0; i<N; i++)
        if(i!=radacina)
        {
            if(distanta[i]==INF)
                printf("0 ");
            else
                printf("%d", distanta[i]);
        }
}

int main()
{
    int nodA, nodB, pondere;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d %d %d", &nodA, &nodB, &pondere);
        matriceAdiacenta[nodA][nodB] = pondere;
    }
    Dijkstra(1);
    return 0;
}
