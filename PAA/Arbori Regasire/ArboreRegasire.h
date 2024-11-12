#ifndef ARBORE_REGASIRE
#define ARBORE_REGASIRE

typedef struct NodArboreDeRegasire {
	struct NodArboreDeRegasire *alfabet[27]; //alfabetul A B ... Z [
}NodArboreDeRegasire;

void Initializare(NodArboreDeRegasire *Nod);
void Atribuie(NodArboreDeRegasire *Nod, char c, NodArboreDeRegasire *p);
NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c);
void NodNou(NodArboreDeRegasire *Nod, char c);

#endif