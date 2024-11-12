#include <stdio.h>
#include <stdlib.h>

int a[100][100],n,m;
int v[100];
int c[100],ad,st;
int p1[100],x1,p2[100],x2;
void pA(int x)
{
    v[x]=1;
    p1[++x1]=x;
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]&&!v[i])
            pA(i);
    }
}

void pC(int x)
{int k;
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

int ver(int x)
{
    x1=x2=0;
    int ok=1;
    for(int i=1;i<=n;i++)
{v[i]=0; c[i]=0;}
ad=-1;
st=0;
//printf("%d\n",x);
pA(x);
for(int i=1;i<=n;i++)
{v[i]=0; c[i]=0;}
ad=-1;
st=0;
pC(x);
    for(int i=1;i<=n;i++)
    {
            //    printf("%d %d\n",p1[i],p2[i]);
        if(p1[i]!=p2[i])
            {
                ok=0;
            }
    }
    return ok;
}

void parc()
{
    for(int i=1;i<=n;i++)
    {
        if(ver(i))
            printf("%d ",i);
    }
}

int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
for(int i=0;i<m;i++)
{
    scanf("%d%d",&x,&y);
    a[y][x]=a[x][y]=1;
}
//printf("\n");
parc();
return 0;
}
