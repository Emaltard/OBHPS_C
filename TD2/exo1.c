#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void remplirTableau(int* t, int n){
        srand(time(NULL));
        for(int i=0; i<n; i++) {
                t[i]=rand()%100;
        }
}

void afficherTableau(int* t, int n){
        for(int i=0; i<n; i++) {
                printf("%d\n", t[i]);
        }
}

int min(int* t, int n){
        int min = INT_MAX;
        for(int i=0; i<n; i++) {
                if(min>t[i]) min = t[i];
        }
        return min;
}

int max(int* t, int n){
        int max = INT_MIN;
        for(int i=0; i<n; i++) {
                if(max<t[i]) max = t[i];
        }
        return max;
}

void tri(int* t, int n){
        for(int i=0; i<n; i++) {
                int i_min = i;
                int v_min = t[i];

                for(int j= i+1; j<n; j++) {
                        if(t[j] < t[i_min]) {
                                i_min = j;
                                v_min = t[j];
                        }
                }
                int tmp = t[i];
                t[i] = t[i_min];
                t[i_min] = tmp;
        }
}


int main(){
        int i;

        printf("Entrez la taille du tableau à allouer: ");
        scanf("%d", &i);

        int* t = malloc(sizeof(int)*i);

        remplirTableau(t,i);
        afficherTableau(t,i);

        printf("Minimum: %d\n", min(t,i));
        printf("Maximum: %d\n", max(t,i));

        tri(t,i);

        afficherTableau(t,i);
        free(t);
}
