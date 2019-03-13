//Maria Fernanda Hernandez Enriquez
//A01329383
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct node{
	int data;
	struct node * right;
	struct node * left; //Index = down
};
struct node * seDirigeA(struct node ** ptrth, int pos){
    struct node * aux = (*ptrth);
    if((*aux).left == NULL || (*aux).data == pos){
        return aux;
    }
    else{
        aux = (*aux).left;
        return seDirigeA(&aux, pos);
    }
}
void addNode(struct node ** ptrth, int x){
     if(*ptrth == NULL){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        (*newNode).data = x;
        (*newNode).right = NULL;
        (*newNode).left = *ptrth;
        *ptrth = newNode;
    }
    else{
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        (*newNode).data = x;
        (*newNode).right = NULL;
        (*newNode).left = NULL;

        struct node * aux  = (*ptrth);
        while ((*aux).left != NULL) {
            aux = (*aux).left;
        }
        (*aux).left = newNode;
    }
}

void addEdge(struct node ** ptrth, int x, int posA, int posB){
    struct node * aux  = (*ptrth);
    while((*aux).left != NULL){
        if((*aux).data == posA){
                while ((*aux).right != NULL){
                    aux = (*aux).right;
                }
                struct node *newEdge = (struct node*)malloc(sizeof(struct node));
                (*newEdge).data = x; //Peso de la arista
                (*newEdge).right = NULL;
                (*newEdge).left = seDirigeA(ptrth, posB);
                (*aux).right = newEdge;
                return;
        }
        else{
            aux = (*aux).left;
        }
    }
        while ((*aux).right != NULL){
            aux = (*aux).right;
        }
        struct node *newEdge = (struct node*)malloc(sizeof(struct node));
        (*newEdge).data = x; //Peso de la arista
        (*newEdge).right = NULL;
        (*newEdge).left = seDirigeA(ptrth, posB);
        (*aux).right = newEdge;
}


void printIndex(struct node * i){
    struct node * tmp = i;
    while(tmp != NULL){
        printf(" %d, \n",(*tmp).data );
        tmp = (*tmp).left;
    }
    printf("\n");
}

void printLista(struct node * head, int pos){
    struct node * tmp = head;
    while (tmp != NULL){
        if((*tmp).data == pos){
            struct node * aux = tmp;
            printf("[ %d ]:", (*tmp).data);
            while(aux != NULL){
                printf(" %d,", (*aux).data);
                aux = (*aux).right;
            }
            printf("\n");
            break;
        }
        tmp = (*tmp).left;
    }
}

void imprimir(struct node * head){
    int va;
    struct node * tmp = head;
    while (tmp != NULL){
            struct node * aux = tmp;
            aux = (*aux).right;
            while(aux != NULL){
                printf("Del nodo %d ", (*tmp).data);
                struct node * hlp = (*aux).left;
                va = (*hlp).data;
                printf("al nodo %d ", va);
                printf("es %d.\n", (*aux).data);
                aux = (*aux).right;
            }
            printf("\n");

        tmp = (*tmp).left;
    }
}

void dijkstra(struct node * head, int n){
    //VARIABLES
    int numNode, bf, cm, i, limit, va;
    numNode = bf = 1;
    limit = 0;
    struct node * min = head;
    struct node * hlp;
    //PUNTERO PARA NODOS
    struct node * ptrNode = head;
    printf("NODE ACTUAL: %d\n", (*ptrNode).data);
    //PUNTERO PARA ARISTAS
    struct node * ptrEdge = head;
    //TABLA DE DISTANCIA CORTA
    int mat[2][n];
    //LLENAR TABLA DE DISTANCIAS
    for(i = 0; i<= n; i++){
        if((i+1) != numNode){
            mat[0][i] = i+1;
        }
    }
    //EMPEZAR CICLO
    while(limit < n){
        numNode = bf;
        cm = 0;
        //BUSCAR EL MENOR SIN CONTAR EL NODE DE DONDE VIENE
        printf("NODE ACTUAL: %d\n", (*ptrNode).data);
        ptrEdge = ptrNode;
        min = ptrNode;
        min = (*min).right;
        ptrEdge = (*ptrEdge).right;
        ptrEdge = (*ptrEdge).right;
        while(ptrEdge != NULL){
            hlp = (*min).left;
            va = (*hlp).data;
            if(va != bf){
                min = (*min).right;
                ptrEdge = (*ptrEdge).right;
            }                printf("%d < %d \n",(*ptrEdge).data, (*min).data);
            if((*ptrEdge).data < (*min).data){
                min = ptrEdge;
            }

            ptrEdge = (*ptrEdge).right;
        }
        printf("El menor es: %d\n", (*min).data);

        //ACTUALIZAR NODE ANTERIOR Y ACUMULADO
        bf = (*ptrNode).data;
        printf("De donde viene: %d", bf);
        cm = cm + (*min).data;
        //GUARDAR LA DISTANCIA MÁS CORTA
        hlp = (*min).left;
        va = (*hlp).data;
        mat[0][va] = va;
        //CAMBIO DE APUNTADOR DE NODO
        i = 1;
        while (i < va){
            ptrNode = (*ptrNode).left;
            i++;
        }
        //CONTADOR DE LOS NODOS PERMANENTES
        limit++;
    }
    for (i = 0; i < n; i++){
        printf("La distancia más corta del nodo 1 al nodo %d es: %d.\n", i+1, mat[1][i]);
    }
}

int main(){
	int size, i, j, data;
	//printf("Size: ");
	scanf("%d", &size);

	struct node * head;
	head = NULL;
	for(i = 0; i < size; i++){
        addNode(&head, i+1);
	}
	//printIndex(head);

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            //printf("Data: ");
            scanf("%d", &data);
            if(data != 0){
                if(data != -1){
                    //____Data es el peso de la arista
                    //____i : de donde va
                    //____j : hacia donde va
                addEdge(&head, data, i+1, j+1);
                }
            }
        }
        //printLista(head, i+1);
        //printf("___________________\n");
    }
    imprimir(head);

    //dijkstra(head, size);

	return 0;
}