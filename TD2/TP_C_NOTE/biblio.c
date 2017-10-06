#include <stdio.h>
#include <stdlib.h>

struct element {
        char valeur;
        struct element* suivant;
};
typedef struct element ELEMENT;

ELEMENT* ajoutElement(ELEMENT* chaine, char c){
        if(chaine==NULL) {
                chaine = malloc(sizeof(ELEMENT));
                chaine->suivant = NULL;
                chaine->valeur = c;
        }else{
                chaine->suivant =  ajoutElement(chaine->suivant,c);
        }
        return chaine;
}

ELEMENT* enleveElement(ELEMENT* chaine, char c){
        if(chaine!=NULL) {
                if(chaine->valeur == c) {
                        ELEMENT* tmp = chaine;
                        chaine = chaine->suivant;
                        free(tmp);
                        return chaine;
                }
                else{
                        chaine->suivant = enleveElement(chaine->suivant, c);
                }
        }
        return chaine;
}


void afficheChaine(ELEMENT* chaine){
        ELEMENT* tmp = chaine;
        while(tmp!=NULL) {
                printf("%c -> ", tmp->valeur);
                tmp = tmp->suivant;
        }
        printf("NULL\n");
}
