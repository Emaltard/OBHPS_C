#include <stdio.h>

int main(){
        int a,b;
        int a_b_pos = 0;
        while(a_b_pos!=1) {
                printf("Donnez un premier entier a:\n");
                scanf("%d", &a);
                printf("Donnez un premier entier b:\n");
                scanf("%d", &b);
                if(b>0 && a>0) {
                        a_b_pos = 1;
                        int res = a;
                        for(int i=1; i<b; i++) {
                                res = res * a;
                        }
                        printf("a^b: %d\n", res);

                }
                else{
                        printf("a et b doivent être positifs.\n");
                }
        }
        return 0;
}
