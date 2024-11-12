#include<stdio.h>
#include<stdlib.h>

int matriceAdiacenta[50][50];
int N, M;
int marc[50];
int kconexe;
int historyAdancime[50], pozHA;
int ok;

void parcurgereAdancime(int x)
{
    marc[x]=1;
    historyAdancime[pozHA]=x;
    pozHA++;
    for(int i=1; i<=N; i++)
        if(matriceAdiacenta[x][i]==1 && marc[i]==0)
            parcurgereAdancime(i);
}

void conexe()
{
    for(int i=1; i<=N; i++)
    {
        if(marc[i]==0)
        {
            kconexe++;
            parcurgereAdancime(i);
        }
    }
}

void resetare()
{
    for(int i=1; i<=N; i++)
    {
        marc[i] = 0;
        historyAdancime[i] = 0;
    }
    pozHA=1;
    ok=0;
}


void parcurgereAdancimeModificata(int x, int prev, int compare)
{
    marc[x]=1;
    if(matriceAdiacenta[compare][x]==1 && prev!=compare)
        ok=1;
    for(int i=1; i<=N; i++)
        if(matriceAdiacenta[x][i]==1 && marc[i]==0)
            parcurgereAdancimeModificata(i,x,compare);
}

int ciclic()
{
    for(int i=1; i<=N; i++)
    {
        resetare();
        parcurgereAdancimeModificata(i,0,i);
        if(ok==1)
            return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    int a,b;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        matriceAdiacenta[a][b] = 1;
        matriceAdiacenta[b][a] = 1;
    }
    conexe();
    printf("%d %d", kconexe, ciclic());
    return 0;
}
