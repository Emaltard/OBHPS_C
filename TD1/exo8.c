#include <stdio.h>

#define SIZE 5

void sommeMatricielle(int l, int c, int (*t1)[c], int (*t2)[c]){
        for(int i = 0; i<l; i++) {
                for(int j = 0; j<c; j++) {
                        t1[i][j] = t1[i][j] + t2[i][j];
                }
        }
}

void afficher_matrice(int l, int c, int (*t)[c]){
        for(int i = 0; i<l; i++) {
                for(int j = 0; j<c; j++) {
                        printf("%d \t", t[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}


int main(){
        int i = SIZE;
        int j = SIZE;
        int a[i][j], b[i][j];

        for(i = SIZE -1; i>=0; i--) {
                for(j = SIZE -1; j>=0; j--) {
                        a[i][j] = i - 2*j;
                        b[i][j] = (-2 * i) + j;
                }
        }
        afficher_matrice(SIZE, SIZE, a);
        afficher_matrice(SIZE, SIZE, b);

        sommeMatricielle(SIZE, SIZE, a, b);

        afficher_matrice(SIZE, SIZE, a);
}
