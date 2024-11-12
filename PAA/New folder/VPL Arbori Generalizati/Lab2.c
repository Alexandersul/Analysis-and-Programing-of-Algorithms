#include<stdio.h>
#include<stdlib.h>

typedef struct Nod
{
    int cheie;
    struct Nod *fiu;
    struct Nod *frate_drept;
} Nod;
Nod *radacina;

void adauga(int cheie,int cheie_parinte,int n)
{
    Nod *q, *poz;
    Nod **w;
    int c=0;
    w=(Nod**)malloc(sizeof(n*n));
    for(int i;i<n;i++)
        w[i]=(Nod*)malloc(sizeof(Nod));
    if(cheie == cheie_parinte)
    {
        q = (Nod*)malloc(sizeof(Nod));
        q->cheie=cheie;
        radacina = q;
    }
    poz=radacina;
    //initializare terminat
        while(1)
        {
            if(poz->cheie==cheie_parinte)
            {
                if(poz->fiu == NULL)
                {
                    poz->fiu=(Nod*)malloc(sizeof(Nod));
                    poz->fiu->cheie=cheie;
                }
                if(poz->fiu->frate_drept==NULL)
                {
                    radacina->fiu=(Nod*)malloc(sizeof(Nod));
                    radacina->fiu->cheie=cheie;
                }
                poz=radacina->fiu->frate_drept;
                while(1)
                {
                    if(poz->frate_drept==NULL)
                    {
                        poz->frate_drept=(Nod*)malloc(sizeof(Nod));
                        poz->frate_drept->cheie=cheie;
                        break;
                    }
                    else poz=poz->frate_drept;
                }
            }
            else
            {
                w[c]=poz;
                c++;
                if(poz->frate_drept!=NULL)
                    poz=poz->frate_drept;
                else if(poz->fiu!=NULL)
                    poz=poz->fiu;
                else
                {
                    poz=w[c-4];//-nr de noduri de la "primul" raspuns de nu care activeaza else-ul mare
                    if(poz->fiu!=NULL)
                    poz=poz->fiu;//de repetat de ceva -1 ori
                }
            }
    }
}

int inaltime(int n,int *v)//de schimbat modul in care calculeaza inaltimea
{
    int s=0,p;

    for(int i=0;i<n;i++)
        if(v[i]==i+1)
            p=i;
     for(int i=0;i<n;i++)
        if(v[i]==p+1&&i!=p)
        {
            p=v[i];
            //asta e fiul radacinii de aici trebuie generalizat fiul unui nod
        }
    return s;
}

/*void preordine(Nod* poz)//grad() in loc de preordine
{
    if(poz!=NULL)
    {
        printf("%d ",poz->cheie);
        preordine(poz->st);
        preordine(poz->dr);
    }
}*/ //cu 0 punem in tabel numerele de nu apar de loc, facem vector de aparitii pentru vectorul de tati si luam maximul de aparitii inafara de 0

int main()
{
    int n, x,y, h,*v;
    scanf("%d", &n);
    v=(int*)malloc(sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        adauga(x,y,n);
        v[x-1]=y;
    }

    //h=inaltime(n,v);
    //printf("%d\n", h);
    //preordine(radacina);
    return 0;
}
