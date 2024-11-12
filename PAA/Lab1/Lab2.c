#include<stdio.h>
#include<stdlib.h>

typedef struct Nod{
    int cheie;
    struct Nod *st, *dr;
}Nod;
Nod *radacina;

void adauga(int cheie)
{
    Nod *q, *poz;
        q = (Nod*)malloc(sizeof(Nod));
        q->cheie=cheie;
        q->st=NULL;
        q->dr=NULL;
    if(radacina == NULL)
        radacina = q;
    else
    {
        poz=radacina;
        while(poz!=NULL)
        {
            if(poz->cheie<cheie)
            {
                if(poz->dr==NULL)
                {
                    poz->dr=q;
                    break;
                }
                poz=poz->dr;
            }
            else
            {
                if(poz->st==NULL)
                {
                    poz->st=q;
                    break;
                }
                poz=poz->st;
            }
        }
    }
}

int inaltime(Nod *poz)
{
    if(poz!=NULL)
    {
        if(inaltime(poz->st) > inaltime(poz->dr))
            return 1 + inaltime(poz->st);
        else
            return 1+ inaltime(poz->dr);
    }
    else
        return 0;
}

void preordine(Nod* poz)
{
    if(poz!=NULL)
    {
        printf("%d ",poz->cheie);
        preordine(poz->st);
        preordine(poz->dr);
    }
}

int main()
{
    int n, x, h;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        adauga(x);
    }
    h=inaltime(radacina);
    printf("%d\n", h);
    //preordine(radacina);
    return 0;
}
