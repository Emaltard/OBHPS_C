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


int main(){

        //INITIALISATION LISTE
        ELEMENT* elem =NULL;
        elem = ajoutElement(elem, 'm');
        elem = ajoutElement(elem, 'a');
        elem = ajoutElement(elem, 'x');
        elem = ajoutElement(elem, 'e');
        elem = ajoutElement(elem, 'n');
        elem = ajoutElement(elem, 'c');
        elem = ajoutElement(elem, 'e');

        elem = ajoutElement(elem, ' ');

        elem = ajoutElement(elem, 'j');
        elem = ajoutElement(elem, 'o');
        elem = ajoutElement(elem, 'u');
        elem = ajoutElement(elem, 'l');
        elem = ajoutElement(elem, 'i');
        elem = ajoutElement(elem, 'n');

        //1er Affichage
        afficheChaine(elem);


        //DESTRUCTION LISTE

        ELEMENT* tmp;
        while(elem !=NULL) {
                tmp = elem;
                elem = elem->suivant;
                free(tmp);
                tmp = tmp->suivant;
        }

        return 0;
}
