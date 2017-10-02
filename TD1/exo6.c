#include <stdio.h>

void afficherTableau(int* t, int n){
        for(int i = 0; i<n; i++) {
                printf("%d ", t[i]);
        }
        printf("\n");
}

int sommeTableau(int* t, int n){
        int somme =0;
        for(int i = 0; i<n; i++) {
                somme += t[i];
        }
        return somme;
}

int moyenneTableau(int *t, int n){
        int somme = sommeTableau(t, n);
        int moyenne = somme /n;
        return moyenne;
}

int main(){
        int t[20];
        for(int i = 0; i<20; i++) {
                t[i] = 2*i +1;
        }

        afficherTableau(t, 20);
        printf("%d\n", sommeTableau(t,20));
        printf("%d\n", moyenneTableau(t,20));
        return 0;
}
