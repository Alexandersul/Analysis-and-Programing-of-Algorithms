#include<stdio.h>
#include<stdlib.h>

int N,M;
int matriceAdiacenta[50][50];
int marc[50];
int historyAdancime[50], historyCuprindere[50];

void parcurgereAdancime(int x)
{
    marc[x]=1;
    historyAdancime[pozHA]=x;
    pozHA++;
    for(int i=1; i<=N; i++)
    {
        if(matriceAdiacenta[x][i]!=0 && marc[i]==0)
            parcurgereAdancime(i);
    }
}

void parcurgereCuprindere(int x)
{
    int k;
    ad=(ad+1)%n;
    c[ad]=x;
    while((ad+1)%n!=st)
    {
        k=c[st];
        st=(st+1)%n;
        v[k]=1;
       p2[++x2]=k;
        for(int i=1;i<=n;i++)
        {
            if(a[k][i]&&!v[i])
            {
                v[i]=1;
                ad=(ad+1)%n;
                c[ad]=i;
            }
        }

    }
}

void resetare()
{
    for(int i=1;i<=n;i++)
    {
        marc[i]=0;
        coada[i]=0;
    }
    pozHA=0;
    pozHC=0;
    ad=-1;
    st=0;
}

int test(int x)
{
    resetare();
    parcurgereAdancime(x);
    resetare();
    parcurgereCuprindere(x);
    for(int i=1; i<=n; i++)
    {
        if(historyAdancime[i] != historyCuprindere[i])
           return 0;
    }
    return 1;
}

int main()
{
    scanf("%d %d", &N, &M);
    int a,b;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b)
        matriceAdiacenta[a][b]= 1;
        matriceAdiacenta[b][a]= 1;
    }
    for(int i=1; i<=N; i++)
    {
        if(test(i)==1)
            printf("%d ",i);
    }

}
