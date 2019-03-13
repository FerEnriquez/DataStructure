//María Fernanda Hernandez Enriquez A01329383
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};
void insert(struct node **ptrth, int x){
    struct node *temp = NULL;
    if(*ptrth == NULL) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->data = x;
        *ptrth = temp;
        return;
    }

    if(x < (*ptrth)->data) {
        insert(&(*ptrth)->left, x);
    }
    else if(x > (*ptrth)->data) {
        insert(&(*ptrth)->right, x);
    }
}
void preOrden(struct node * head) {
     if (head) {
         printf("%d, ",head->data);
         preOrden(head->left);
         preOrden(head->right);
     }
 }
 void inOrden(struct node * head) {
     if (head) {
         inOrden(head->left);
         printf("%d, ",head->data);
         inOrden(head->right);
     }
 }
 void postOrden(struct node * head) {
     if (head) {
         postOrden(head->left);
         postOrden(head->right);
         printf("%d, ",head->data);
     }
 }

int main(){
    struct node * head;
    head = NULL;
    int n, cont;
    printf("Cantidad de numeros a ingresar: ");
    scanf("%d", &n);
    fflush(stdin);
    cont = 0;
    while(cont < n){
        int num;
        printf("Numero: ");
        scanf("%d", &num);
        fflush(stdin);
        insert(&head, num);
        cont++;
    }
    printf("PreOrden: ");
    preOrden(head);
    printf("\n");
    printf("InOrden: ");
    inOrden(head);
    printf("\n");
    printf("PostOrden: ");
    postOrden(head);
    return 0;
}
