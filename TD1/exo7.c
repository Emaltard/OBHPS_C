#include <stdio.h>

#define SIZE 128


int main(){
        char chaine_char[SIZE];
        printf("Entrez une chaîne de caractères: \n");
        fgets(chaine_char, SIZE, stdin);

        int nb_char = 0;
        int i=0;
        while(chaine_char[i]!='\0') {
                nb_char += 1;
                i++;
        }

        printf("taille: %d\n", nb_char);

        char chaine_char_inv[SIZE];
        int j = 0;
        for(int i = nb_char; i>0; i--) {
                chaine_char_inv[j] = chaine_char[i-1];
                j++;
        }
        printf("inverse: %s\n", chaine_char_inv);
        return 0;
}
