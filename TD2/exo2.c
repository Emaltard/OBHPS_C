#include <stdio.h>

struct temps {
        int heures;
        int minutes;
        int secondes;
};
typedef struct temps TEMPS;

void afficherTemps(TEMPS t){
        printf("%dh %dm %ds\n", t.heures, t.minutes, t.secondes);
}

TEMPS sommeTemps(TEMPS t1, TEMPS t2){
        TEMPS tmp;
        tmp.secondes = (t1.secondes + t2.secondes) % 60;
        tmp.minutes = ((t1.secondes + t2.secondes)/60 + (t1.minutes + t2.minutes) )% 60;
        tmp.heures = ((t1.minutes + t2.minutes)/60 + (t1.heures + t2.heures))%24;
        return tmp;
}

int main(){
        TEMPS tmp1, tmp2, tmps;
        tmp1.heures = 12;
        tmp1.minutes = 34;
        tmp1.secondes = 58;
        tmp2.heures = 12;
        tmp2.minutes = 34;
        tmp2.secondes = 58;
        afficherTemps(tmp1);
        afficherTemps(tmp2);
        tmps = sommeTemps(tmp1,tmp2);
        afficherTemps(tmps);
}
