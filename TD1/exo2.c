#include <stdio.h>

int main(){
        int rep = 0;
        while(rep!=1) {
                scanf("%d", &rep);
                if(rep!=1) {
                        printf("Vous n'avez pas écrit 1.\n");
                }
        }
        return 0;
}
