//María Fernanda Hernández Enriquez A01329383
#include <stdio.h>
struct fraction{
    int num;
    int den;

};
void printFrac(struct fraction *n){
    char numS[5];
    sprintf(numS, "%d", (*n).num);
    char denS[5];
    sprintf(denS, "%d", (*n).den);
    printf("%5s / %5s   ", numS, denS);
}
void simplify(struct fraction *n){
    int min,i,cond, gcd;
    do {
        if ((*n).num < (*n).den){
            min = (*n).num;
        }
        else{
            min = (*n).den;
        }
        i = 2;
        cond = 0;
        while (cond == 0 && i <= min){
            if ((*n).num % i == 0 && (*n).den % i == 0){
                gcd = i;
                cond = 1;
            }
        i++;
        }
        if (cond == 1){
           (*n).num = (*n).num / gcd;
           (*n).den = (*n).den / gcd;
         }
    }while (cond == 1);
}
struct fraction *suma (struct fraction frac1, struct fraction frac2){
    struct fraction result;
    int a = frac1.den;
    int b = frac2.den;
    if (b == 0 || a == b){
        result.num = (frac1).num + (frac2).num;
        result.den = (frac1).den;
    }
    else{
        result.num = ((frac1.num) * (frac2.den)) + ((frac1.den) * (frac2.num));
        result.den = (frac1).den * (frac2).den;
    }
    simplify(&result);
    return &result;
}

struct fraction *multiplicar (struct fraction frac1, struct fraction frac2){
    struct fraction result;
    result.num = (frac1.num) * (frac2.num);
    result.den = (frac1.den) * (frac2.den);
    return &result;
}

struct fraction *multMatrix (struct fraction *frac1, struct fraction *frac2, int a, int b, int c){
    //int c son colA/rowB
    struct fraction aux;
    struct fraction *ptaux;
    ptaux = &aux;
    struct fraction result[a][b];
    struct fraction *ptr;
    ptr = &result;
    (*ptr).num = 0;
    (*ptr).den = 0;

    int i, j, k;
     for(i = 0; i < b; i++){//col B
        for(j = 0; j < a; j++){ // ren A
                for(k = 0; k < c; k++){//col A
                    (*ptaux) = *multiplicar(*frac1,*frac2);
                    (*ptr) = *(suma(*ptaux, *ptr));
                    frac1++;
                    frac2 = frac2 + b; // numero colB
                    }
            ptr++;
            (*ptr).num = 0;
            (*ptr).den = 0;
            frac2 = frac2 - (b*c);
        }
        frac1 = frac1 - (a*c);
        frac2 = frac2 + 1;
    }
    ptr = ptr - (a*b);
    for (j=0; j<a; j++){
            for (i=0; i<b; i++){
                printFrac(ptr+j+(i*a));
            }
         printf("\n");
        }
    return &result;
}

int main(){

    int rA, cA, rB, cB;
    //rA
    scanf("%d", &rA);
    //cA
    scanf("%d", &cA);
    struct fraction matA [rA][cA];
    //rB
    scanf("%d", &rB);
    //cB
    scanf("%d", &cB);
    struct fraction matB [rB][cB];
    //cA == rB
    if(cA == rB){
        int i, j, k;
        //Matriz A
        struct fraction *pta;
        pta = matA;
        for(i = 0; i< (rA*cA); i++){
            int x, y;
            //printf("Num: ");
            scanf("%d", &x);
            pta -> num = x;
            //printf("Den: ");
            scanf("%d", &y);
            pta -> den = y;
            pta++;
        }
        //Matriz B
        struct fraction *ptb;
        ptb = matB;
        for(i = 0; i< (rB*cB); i++){
            int x, y;
           // printf("Num: ");
            scanf("%d", &x);
            ptb -> num = x;
           // printf("Den: ");
            scanf("%d", &y);
            ptb -> den = y;
            ptb++;
        }

        //Matriz C
        struct fraction *ptc;

        //OUTPUT
        pta = pta - (rA*cA);
        for (j=0; j<rA; j++){
            for (i=0; i<cA; i++){
                 printFrac((pta+i+j*cA));
            }
         printf("\n");
        }
        printf("X\n");
        ptb = ptb - (rB*cB);
        for (j=0; j<rB; j++){
            for (i=0; i<cB; i++){
                printFrac((ptb+i+j*cB));
            }
         printf("\n");
        }
        printf("=\n");
        ptc = multMatrix(pta,ptb, rA, cB, cA);
    }
    else{
        printf("NO");
    }

    return 0;
}

