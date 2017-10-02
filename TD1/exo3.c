#include <stdio.h>

int main(){
        int b_non_null = 0;
        int a,b;
        while(b_non_null!=1) {

                printf("Donnez un premier entier a:\n");
                scanf("%d", &a);
                printf("Donnez un premier entier b:\n");
                scanf("%d", &b);
                if(b!=0) {
                        b_non_null=1;
                        printf("a+b: %d\n", a+b);
                        printf("a-b: %d\n", a-b);
                        printf("a*b: %d\n", a*b);
                        printf("a/b: %d\n", a/b);

                }
                else{
                        printf("b doit être different de 0\n");
                }
        }
        return 0;
}
