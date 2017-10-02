#include <stdio.h>

struct element {
        int valeur;
        struct element* suivant;
};
typedef struct element ELEMENT;


void afficheChaine(ELEMENT* chaine){
        ELEMENT* tmp = chaine;
        printf("%d\n", tmp->valeur);
        while(tmp->suivant!=NULL) {
                tmp = tmp->suivant;
                printf("%d\n", tmp->valeur);
        }
        printf("\n");
}


int main(){
        ELEMENT elem;
        elem.valeur = 3;
        elem.suivant = NULL;
        afficheChaine(&elem);
}
