//María Fernanda Hernández Enriquez A01329383

#include <stdio.h>
#include <stdlib.h>
int main(){
    int  n ;
    scanf("%d\n", &n);
    int  cont;
    cont = 0;
    while(cont < n){
        char palabra [20];
        gets (palabra);
        char *pti;
        pti = palabra;
        int size;
        size = 0;
        while (*pti != '\0') {
            size++;
            pti++;
        }

        int cond;
        cond = 1;
            char * ini;
            ini = &palabra[0];
            char * fin;
            fin = &palabra[size-1];
        int i;
        i = 0;
        while(i < size){
                if((*ini) != (*fin)){
                    cond = 2;
                    break;
                }
                ini++;
                fin--;
                i++;
        }
        if (cond==1) printf("YES");
        else printf("NO");
        printf("\n");
        cont++;
    }

return 0;
}

