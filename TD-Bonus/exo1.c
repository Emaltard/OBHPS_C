#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum {
        max, min, avg, med
};

struct service_t {
        int* data;
        int size_data;
        int (*func)();
};
typedef struct service_t service_t;

int minimum(service_t data){
        int min = INT_MAX;
        for(int i=0; i<data.size_data; i++) {
                if(min>data.data[i]) min = data.data[i];
        }
        return min;
}

int maximum(service_t data){
        int max = INT_MIN;
        for(int i=0; i<data.size_data; i++) {
                if(max<data.data[i]) max = data.data[i];
        }
        return max;
}

int average(service_t data){
        int somme =0;
        for(int i = 0; i<data.size_data; i++) {
                somme += data.data[i];
        }
        int moyenne = somme /data.size_data;
        return moyenne;
}

int mediane(service_t data){
        int tab[data.size_data];
        for(int i=0; i<data.size_data; i++) {
                int i_min = i;

                for(int j= i+1; j<data.size_data; j++) {
                        if(data.data[j] < data.data[i_min]) {
                                i_min = j;
                        }
                }
                tab[i] = data.data[i_min];
        }
        if(data.size_data%2!=0) {
                return tab[data.size_data/2];
        }else{
                return (tab[data.size_data/2-1] + tab[data.size_data/2])/2;
        }
}

void Initialisation_service(service_t* service, int* data, int data_size, int type){
        int* newData = malloc(sizeof(int)*data_size);
        for(int i=0; i<data_size; i++) {
                newData[i] = data[i];
                newData[i+1] = '\0';
        }
        service->data = newData;
        service->size_data = data_size;

        switch (type) {
        case max:
                service->func = maximum;
                break;
        case min:
                service->func =minimum;
                break;
        case avg:
                service->func = average;
                break;
        case med:
                service->func = mediane;
                break;
        default:
                printf("Mauvaise Commande\n");
        }
}



int main(){
        FILE* fichier = NULL;
        char buffer[256] = "";

        fichier = fopen("data.txt", "r");

        service_t service;

        if (fichier != NULL)
        {
                int line = 0;
                int size_data=0;
                int data[128];
                while(fgets(buffer, 256, fichier)!=NULL) {
                        if(line%3==1) {
                                int i=0;
                                while(buffer[i]!=':') {
                                        i++;
                                }
                                i++;
                                char b[128];
                                int z = 0;
                                while(buffer[i]!='\n') {
                                        if(buffer[i]!=';') {
                                                b[z] = buffer[i];
                                                z++;

                                        }
                                        if(buffer[i+1]=='\n'|| buffer[i+1]==';') {
                                                b[z] = '\0';
                                                data[size_data] = atoi(b);
                                                size_data++;
                                                z=0;
                                                strcpy(b, "\0");
                                        }
                                        i++;
                                }
                                printf("Tableau: \n");
                                for(int i=0; i<size_data; i++) {
                                        printf("%d ", data[i]);
                                }
                                printf("\n");
                        }
                        else if(line%3==2) {
                                int i=0;
                                while(buffer[i]!=':') {
                                        i++;
                                }
                                i++;
                                if(buffer[i]=='a') {
                                        Initialisation_service(&service, data, size_data, avg);
                                }
                                else if(buffer[i]=='m') {
                                        if(buffer[i+1]=='i') {
                                                Initialisation_service(&service, data, size_data, min);
                                        }
                                        else if(buffer[i+1]=='a') {
                                                Initialisation_service(&service, data, size_data, max);
                                        }
                                        else if(buffer[i+1]=='e') {
                                                Initialisation_service(&service, data, size_data, med);
                                        }
                                }

                                printf("Retour: %d\n", service.func(service));
                                printf("=================\n");
                                size_data = 0;
                        }
                        else{
                                printf("%s", buffer);
                        }
                        line++;
                }
                fclose(fichier);
        }
        else{
                printf("Impossible de lire le fichier\n");
        }
        return 0;
}
