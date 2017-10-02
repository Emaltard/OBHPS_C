#include <stdio.h>
#include <stdlib.h>

struct element {
        char valeur;
        struct element* suivant;
};
typedef struct element ELEMENT;

void ajoutElement(ELEMENT* chaine, char c){
  ELEMENT* tmp = chaine;
  while(tmp->suivant!=NULL) {
    tmp = tmp->suivant;
  }
  ELEMENT* new_elem = malloc(sizeof(ELEMENT*));
  new_elem->valeur = c;
  tmp->suivant = new_elem;
}

void enleveElement(ELEMENT* chaine, char c){
  ELEMENT * act = chaine;
  while(act->suivant->valeur != c){
    act = act->suivant;
  }
  ELEMENT * tmp = act->suivant;
  act->suivant = tmp->suivant;
  free(tmp);
}


void afficheChaine(ELEMENT* chaine){
        ELEMENT* tmp = chaine;
        printf("%c", tmp->valeur);
        while(tmp->suivant!=NULL) {
                tmp = tmp->suivant;
                printf("%c", tmp->valeur);
        }
        printf("\n");
}


int main(){
        ELEMENT elem;
        elem.valeur = '3';
        elem.suivant = NULL;

        ajoutElement(&elem, 'o');
        ajoutElement(&elem, 'w');
        enleveElement(&elem, 'o');
        afficheChaine(&elem);
}
