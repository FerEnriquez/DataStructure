//María Fernanda Hernandez Enriquez
//A1329383
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data[50];
    struct node *right;
    struct node *left;
};

void insert(struct node **ptrth, char *x){
    struct node *tmp = NULL;
    if(*ptrth == NULL) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->left = tmp->right = NULL;
        strcpy(tmp->data, x);
        *ptrth = tmp;
        return;
    }
    if(strcmp(x, (*ptrth)->data) < 0) {
        insert(&(*ptrth)->left, x);
    }
    else if(strcmp(x,(*ptrth)->data) > 0 )  {
        insert(&(*ptrth)->right, x);
    }
}

void remplazo(struct node **ptrth, struct node **aux){
    if((*ptrth)->right == NULL){
        strcpy((*aux)->data, (*ptrth)->data);
        *aux = *ptrth;
        *ptrth = (*ptrth)->left;
    }
    else
        remplazo(&(*ptrth)->right, aux);
}
void eliminar(struct node **ptrth, char *x){
   struct node *aux;
   if( *ptrth == NULL){
   		printf("No puede ser eliminado.\n");
   		return;
   }
   else{
        if(strcmp(x,(*ptrth)->data) > 0){
            eliminar(&(*ptrth)->right, x);
        }
        else if(strcmp(x,(*ptrth)->data) < 0){
            eliminar(&(*ptrth)->left, x);
        }
        else if(strcmp(x,(*ptrth)->data) == 0){
            aux = *ptrth;
            if((*ptrth)->left == NULL){
                *ptrth = (*ptrth)->right;
            }
            else if((*ptrth)->right == NULL){
                *ptrth = (*ptrth)->left;
            }
            else{
                remplazo(&(*ptrth)->left, &aux);
            }
            free(aux);
            printf("%s eliminado.\n", x);
        }
   }

}

void buscar(struct node *ptr, char *x){
        if (strcmp(ptr->data, x) == 0){
            printf("%s encontrado.\n", x);
            return;
        }
        if (x < ptr->data) {
            if (ptr->left == NULL){
                printf("%s no encontrado.\n", x);
                return;
            }
            buscar(ptr->left, x);
        }
        if (x > ptr->data) {
            if (ptr->right == NULL){
                printf("%s no encontrado.\n", x);
                return;
            }
            buscar(ptr->right, x);
    }
}

void preOrden(struct node * head) {
     if (head) {
         printf("%s\n ",head->data);
         preOrden(head->left);
         preOrden(head->right);
     }
 }

 void inOrden(struct node * head) {
     if (head) {
         inOrden(head->left);
         printf("%s\n ",head->data);
         inOrden(head->right);
     }
 }

 void postOrden(struct node * head) {
     if (head) {
         postOrden(head->left);
         postOrden(head->right);
         printf("%s\n ",head->data);
     }
 }

 int level(struct node * head){
    if(head){
        int maxLeft = 1 + level(head->left);
        int maxRight = 1 + level(head->right);
        if(maxLeft > maxRight){
            return maxLeft;
        }
        else{
            return maxRight;
        }
    }
    else
        return 0;
 }
 void printN(struct node * head, int level){
    if(head != NULL && level == 0){
        printf("%s\n ", head->data);
    }
    else if(head){
        printN(head->left, level - 1);
        printN(head->right, level - 1);
    }
}
void porNiveles(struct node * head){
    int contL = level(head);
    int i;
    for(i = 0; i < contL; i++){
        printN(head, i);
    }
}

int main(){
    struct node * head;
    head = NULL;
    int opt = 8;
    while (opt != 0){
        //printf("Opcion: ");
        scanf("%d", &opt);
        fflush(stdin);
        char name[50];
        switch (opt){
            case 0:
                //printf("Salir.");
                break;
            case 1:
                fflush(stdin);
                //printf("Insertar a: ");
                gets(name);
                insert(&head, name);
                break;
            case 2:
                fflush(stdin);
                //printf("Eliminar a: ");
                gets(name);
                eliminar(&head, name);
                break;
            case 3:
                fflush(stdin);
                //printf("Buscar a: ");
                gets(name);
                buscar(head, name);
                break;
            case 4:
                //printf("PreOrden: ");
                preOrden(head);
                //printf("\n");
                break;
            case 5:
                //printf("InOrden: ");
                inOrden(head);
                //printf("\n");
                break;
            case 6:
                //printf("PostOrden: ");
                postOrden(head);
                //printf("\n");
                break;
            case 7:
                //printf("Por niveles: ");
                porNiveles(head);
                //printf("\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
            }
    }
    return 0;
}
