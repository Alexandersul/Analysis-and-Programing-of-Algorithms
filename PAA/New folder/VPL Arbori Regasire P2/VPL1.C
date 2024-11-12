#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int k=0;
typedef struct NodArboreDeRegasire {
	struct NodArboreDeRegasire *alfabet[27]; //alfabetul A B ... Z [
}NodArboreDeRegasire;

NodArboreDeRegasire *radacina;

void Initializare(NodArboreDeRegasire *Nod)
{
	//ATENTIE, aceasta functie trebuie apelata cu *Nod deja alocat
	char c;
	for (c = 'a'; c <= 'z'+1; c++)
		Nod->alfabet[c - 'a'] = NULL;
}

void Atribuie(NodArboreDeRegasire *Nod, char c, NodArboreDeRegasire *p)
{
	Nod->alfabet[c - 'a'] = p;
}

NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c)
{
	return Nod->alfabet[c - 'a'];
}

void NodNou(NodArboreDeRegasire *Nod, char c)
{
	Nod->alfabet[c - 'a'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
	Initializare(Nod->alfabet[c - 'a']);
}

void Adauga(char *x, NodArboreDeRegasire *cuvinte)  //x=cuvantul, cuvinte=radacina arborelui de regasire
{
	unsigned i;
	NodArboreDeRegasire *t;
	t = cuvinte;
	for (i = 0; i < strlen(x);i++)
	{
		if (Valoare(t, x[i]) == NULL) //nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou
			{
			    NodNou(t, x[i]);
			    k++;
			}
		t = Valoare(t, x[i]); //avansez in arborele de regasire
	}
	Atribuie(t, '{', t); //se face o bucla pentru '[', pentru a marca un nod terminal

}
void Parcurge(NodArboreDeRegasire *Nod, char cuv[], int niv) //nodul curent, un buffer pentru construirea cuvantului, nivelul curent
{
	char c;
	for (c ='a'; c <= 'z'; c++)		//pentru toate literele considerate
	{
		if (Valoare(Nod, c))			//daca exista legatura in dictionar
		{
			cuv[niv] = c;				//adaug litera gasita in buffer
			Parcurge(Valoare(Nod, c),cuv,niv+1); //avansez
		}
	}
	if (Valoare(Nod, '['))			//exista terminator=>am gasit un cuvant intreg
	{
		cuv[niv] = '\0';
		printf("%s\n", cuv);		//prelucrez datele
	}
}

int main()
{
    int n,x=0;
    char l='0';
    int a[2][32],s=0;
    radacina = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));
    Initializare(radacina);
    char cuvant[32];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", cuvant);
        Adauga(cuvant, radacina);
        if(x<strlen(cuvant))
            x=strlen(cuvant);
        a[0][i]=strlen(cuvant);
        a[1][i]=cuvant[0]-'0';
    }
    for(int i=0; i<n; i++)
    {
        if(a[1][i]!=a[1][i+1])
            s+=a[0][i];

    }
    printf("%d %d", x+1, k+1);
}







