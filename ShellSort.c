#include <stdio.h>
#include <stdlib.h>

void shell_sort (int *v, int tam);
#define tam 5000

int main (){

    int *v = malloc (tam * sizeof (int));
    int i;
    for (i = 0; i < tam; i++)
        v[i] = rand () % 1000; 

    shell_sort (v, i);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void shell_sort(int *vet, int size){

    int i, j, val;
    int salto = 1;

    while(salto < size)
        salto = 3*salto+1;

    while (salto > 1){
        salto /= 3;

        for(i = salto; i < size; i++){
            val = vet[i];
            j = i-salto;
            while (j >= 0 && val < vet[j]){
                vet [j+salto] = vet[j];
                j -= salto;
            }
            vet [j+salto] = val;
        }
    }
}