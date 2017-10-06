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
        ELEMENT* liste =NULL;
        liste = ajoutElement(liste, 'm');
        liste = ajoutElement(liste, 'a');
        liste = ajoutElement(liste, 'x');
        liste = ajoutElement(liste, 'e');
        liste = ajoutElement(liste, 'n');
        liste = ajoutElement(liste, 'c');
        liste = ajoutElement(liste, 'e');

        liste = ajoutElement(liste, ' ');

        liste = ajoutElement(liste, 'j');
        liste = ajoutElement(liste, 'o');
        liste = ajoutElement(liste, 'u');
        liste = ajoutElement(liste, 'l');
        liste = ajoutElement(liste, 'i');
        liste = ajoutElement(liste, 'n');

        //1er Affichage
        printf("1er affichage:\n");
        afficheChaine(liste);

        //Suppression des voyelles

        ELEMENT* tmp;
        tmp = liste;
        while(tmp !=NULL) {
                enleveElement(liste, 'a');
                enleveElement(liste, 'e');
                enleveElement(liste, 'i');
                enleveElement(liste, 'o');
                enleveElement(liste, 'u');
                enleveElement(liste, 'y');
                tmp = tmp->suivant;
        }

        //2ème Affichage
        printf("2ème affichage:\n");
        afficheChaine(liste);

        //Fin: Destruction de la Liste (free de toutes les allocations)

        while(liste !=NULL) {
                tmp = liste;
                liste = liste->suivant;
                free(tmp);
        }

        return 0;
}
