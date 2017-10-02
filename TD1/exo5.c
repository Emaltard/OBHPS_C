#include <stdio.h>

int facto(int i){
        if(i==0) {
                return 1;
        }
        else if(i==1) {
                return 1;
        }
        else{
                return i * facto(i-1);
        }
}

int main(){
        int a;
        int a_pos = 0;
        while(a_pos!=1) {
                printf("Donnez un premier entier a:\n");
                scanf("%d", &a);
                if(a>0) {
                        a_pos = 1;
                        printf("a!: %d\n", facto(a));

                }
                else{
                        printf("a doit être positif.\n");
                }
        }
        return 0;
}
