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
