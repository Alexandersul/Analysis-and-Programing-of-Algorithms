#include<stdio.h>
#include<stdlib.h>

typedef struct Nod{
    float key;
    struct Nod *st, *dr;
}Nod;
Nod *head;

void adauga(int key)
{
    Nod *q, *poz;
        q = (Nod*)malloc(sizeof(Nod));
        q->key=key;
        q->st=NULL;
        q->dr=NULL;
    if(head == NULL)
        head = q;
    else
    {
        poz=head;
        while(poz!=NULL)
        {
            if(poz->key<key)
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

void preordine(Nod* poz)
{
    if(poz!=NULL)
    {
        printf("%d ",poz->key);
        preordine(poz->st);
        preordine(poz->dr);
    }
}

int main()
{
    int n, h;
    float x;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%f", &x);
        adauga(x);
    }
    preordine(head);
    return 0;
}
