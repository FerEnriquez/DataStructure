//Maria Fernanda Hernandez Enriquez A01329383
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Libro
struct book{
    char autor[30];
    char titulo[30];
};
void printBook(struct book *x){
     printf("Autor: %s - Titulo: %s\n", (*x).autor, (*x).titulo);
}
//Documentos a imprimir
struct doc{
    char nombre[30];
    char dueno[30];
};
void printDoc(struct doc *x){
    printf("Nombre: %s - Dueno: %s\n", (*x).nombre, (*x).dueno);
}
struct node{
    struct node *data;
    struct node *next;
};
//Funciones para libro
void push (struct node **ptrth, char *s1, char *s2){
    if(*ptrth == NULL){
        struct node *newBook = (struct node*)malloc(sizeof(struct node));
        struct book *ptl = (struct book*)malloc(sizeof(struct book));
        strcpy(ptl->autor, s1);
        strcpy(ptl->titulo, s2);
        (*newBook).data = ptl;
        (*newBook).next = *ptrth;
        *ptrth = newBook;
    }
    else{
        struct node *newBook = (struct node*)malloc(sizeof(struct node));
        struct book *ptl = (struct book*)malloc(sizeof(struct book));
        strcpy(ptl->autor, s1);
        strcpy(ptl->titulo, s2);
        (*newBook).data = ptl;
        (*newBook).next = NULL;

        struct node * aux  = (*ptrth);
        //Lleva al útilmo nodo
        while ((*aux).next != NULL) {
            aux = (*aux).next;
        }
        (*aux).next = newBook;
    }
}
void pop (struct node ** ptrth){
    struct node *tmp =(*ptrth);
    if((*tmp).next == NULL){
        *ptrth = (*tmp).next;
    }
    else{
        struct node *aux;
        while((*tmp).next != NULL){
            aux = tmp;
            tmp = (*tmp).next;
        }
        (*aux).next = NULL;
        free((*aux).next);
    }
}
void printB(struct node * i){
     if(i == NULL){
     }
     else{
        printB((*i).next);
        struct book * lib = (*i).data;
        printBook(lib);
     }
}
//Funciones para imprimir dicuentos
void agregar (struct node ** ptrth, char *s1, char *s2){
    if(*ptrth == NULL){
        struct node *newDoc = (struct node*)malloc(sizeof(struct node));
        struct doc *ptl = (struct doc*)malloc(sizeof(struct doc));
        strcpy(ptl->nombre, s1);
        strcpy(ptl->dueno, s2);
        (*newDoc).data = ptl;
        (*newDoc).next = *ptrth;
        *ptrth = newDoc;
    }
    else{
        struct node *newDoc = (struct node*)malloc(sizeof(struct node));
        struct doc *ptl = (struct doc*)malloc(sizeof(struct doc));
        strcpy(ptl->nombre, s1);
        strcpy(ptl->dueno, s2);
        (*newDoc).data = ptl;
        (*newDoc).next = NULL;

        struct node * aux  = (*ptrth);
        while ((*aux).next != NULL) {
            aux = (*aux).next;
        }
        (*aux).next = newDoc;
    }
}
void despachar (struct node ** ptrth){
    struct node *tmp = (*ptrth);
    *ptrth = (*tmp).next;
    //free((*tmp).next);
}
void printD(struct node * i){
    struct node * tmp = i;
    while(tmp != NULL){
        struct doc * hoja = (*tmp).data;
        printDoc(hoja);
        tmp = (*tmp).next;
    }
    printf("\n");
}
void destruir(struct node * head, int x){
     int i;
     for(i = 0; i < x; i++){
        if(head == NULL){
            break;
        }
        else{
            free((*head).next);
            head = (*head).next;
        }
    }
}

int main (){
//    struct node * head;
//    head = NULL;
    int opcion, opBook, opImp, size;
    opcion = 3;
    while(opcion != 0){
        struct node * head;
        head = NULL;
        printf("(1)Libros (2)Imprimir (0)Salir : ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                printf("Tamano: ");
                scanf("%d", &size);
                fflush(stdin);
                opBook = 1;
                while (opBook != 0){
                    printf("Opcion: ");
                    scanf("%d", &opBook);
                    fflush(stdin);
                    switch(opBook){
                    case 0:
                        destruir(head, size);
                        printf("Salir de libros.\n");
                        break;
                    case 1:
                        fflush(stdin);
                        char s1 [30];
                        char s2 [30];
                        printf("Autor: ");
                        gets(s1);
                        printf("Titulo: ");
                        gets(s2);
                        push(&head, &s1, &s2);
                        break;
                    case 2:
                        pop(&head);
                        break;
                    case 3:
                        printB(head);
                        break;
                    default:
                        printf("Opcion no valida\n");
                        break;
                    }
                }
            break;
            case 2:
                printf("Tamano: ");
                scanf("%d", &size);
                fflush(stdin);
                opImp = 1;
                while (opImp != 0){
                    printf("Opcion: ");
                    scanf("%d", &opImp);
                    fflush(stdin);
                    switch(opImp){
                    case 0:
                        destruir(head, size);
                        printf("Salir de documentos a imprimir.\n");
                        break;
                    case 1:
                        fflush(stdin);
                        char s3[30], s4[30];
                        printf("Nombre: ");
                        gets(s3);
                        printf("Dueno: ");
                        gets(s4);
                        agregar(&head, &s3, &s4);
                        break;
                    case 2:
                        despachar(&head);
                        break;
                    case 3:
                        printD(head);
                        break;
                    default:
                        printf("Opcion no valida\n");
                        break;
                    }
                }
            break;

        }
    }
    printf("Salir del menu.\n");
    return 0;
}
