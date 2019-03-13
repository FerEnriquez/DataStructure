//Maria Fernanda Hernandez Enriquez   A01329383
//Manuel Alejandro Neri Reyes          A01329872

#include <stdio.h>
#include <stdlib.h>

struct nodo {
        int x;
        int p;
};

struct nodo agregar(int x, int p){
        struct nodo tmp;
        tmp.x = x;
        tmp.p = p;
        return tmp;
}

void ordenar(struct nodo cola[], int n){
        int i,j;
        for( i = 0; i < n; i++) {
                for(j=i+1; j<n; j++) {
                        if(cola[j].p > cola[i].p) {
                                struct nodo aux = cola[i];
                                cola[i] = cola[j];
                                cola[j] = aux;
                        }
                }
        }
}

int main(){
        int n;
        int i;
        int j;
        int k;
        scanf("%i", &n);
        int matrix[n][n];
        int distancias[n];

        for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                        scanf("%i", &matrix[i][j]);
                }
        }

        for(k = 0; k < n; k++) {
                struct nodo cola[1024];
                int ind = 1;

                for(i = 0; i < n; i++) {
                        distancias[i] = 1024*1024;
                }

                cola[0] = agregar(k,0);
                while(ind > 0) {
                        ordenar(cola, ind);
                        struct nodo n1 = cola[--ind];
                        if(n1.p >= distancias[n1.x])
                                continue;
                        distancias[n1.x] = n1.p;
                        for(i=0; i<n; i++) {
                                if(matrix[n1.x][i] > 0) {
                                        cola[ind++] = agregar(i, n1.p + matrix[n1.x][i]);
                                }
                        }
                }
                for( i = 0; i < n; i++) {
                        if(i != k)
                                printf("Distancia mas corta del nodo %i al nodo %i es: %i\n", k+1, i+1, distancias[i]);
                }
                printf("\n");
        }


}
//DEF
