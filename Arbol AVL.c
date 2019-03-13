//María Fernanda Hernandez Enriquez
//A01329383
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int alt;
    char data[50];
    struct node *left;
    struct node *right;
};
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
int altura(struct node * head){
    if (head == NULL){
        return 0;
    }
    else{
        return head->alt;
    }
}
//0- izq  1-der
struct node * cambio(struct node * head, int cond){
    struct node *result;
    struct node *tmp;
    if(cond == 1){
        result = head->left;
        tmp = result->right;
        result->right = head;
        head->left = tmp;
        head->alt = 1 + max(altura(head->left), altura(head->right));
        result->alt = 1 + max(altura(result->left), altura(result->right));
        return result;
    }
    else{
        result = head->right;
        tmp = result->left;
        result->left = head;
        head->right = tmp;
        head->alt = 1 + max(altura(head->left), altura(head->right));
        result->alt = 1 + max(altura(result->left), altura(result->right));
        return result;
    }
}
struct node * add(char *x){
    struct node* nuevo = (struct node*)malloc(sizeof(struct node));
    strcpy(nuevo->data, x);
    //printf("add: %s", nuevo->data);
    nuevo->left = nuevo->right = NULL;
    nuevo->alt = 1;
    return(nuevo);
}
int equilibrar(struct node * head){
    if (head == NULL)
        return 0;
    int result = altura(head->left) - altura(head->right);
    return result;
}
struct node* insert(struct node* head, char *x){
    if (head == NULL){
        return(add(x));
    }
    //strcmp( x, head->data) < 0
    if (strcmp( x, head->data) < 0){
        head->left = insert(head->left, x);
    }
    else if (strcmp( x, head->data) > 0){
        head->right = insert(head->right, x);
    }
    else{
        return head;
    }
    head->alt = max(altura(head->left),altura(head->right));
    head->alt++;
    int balance = equilibrar(head);
    if (balance > 1 && strcmp( x, head->left->data) < 0){
        return cambio(head, 1);
    }
    if (balance < -1 && x > head->right->data){
        return cambio(head, 0);
    }
    if (balance > 1 && x > head->left->data){
        head->left =  cambio(head->left, 0);
        return cambio(head, 1);
    }
    if (balance < -1 && x < head->right->data){
        head->right = cambio(head->right, 1);
        return cambio(head, 0);
    }
    return head;
}

void preOrder(struct node * head){
    if(head){
        printf("%s, ", head->data);
        preOrder(head->left);
        preOrder(head->right);
    }
}
void inOrder(struct node * head){
    if(head){
        inOrder(head->left);
        printf("%s, ", head->data);
        inOrder(head->right);
    }
}
void posOrder(struct node * head){
    if(head){
        posOrder(head->left);
        posOrder(head->right);
        printf("%s, ", head->data);
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
        printf("%s, ", head->data);
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

void buscar(struct node *ptr, char *x){
        if (strcmp(x, ptr->data) == 0){
            printf("%s encontrado.\n", x);
            return;
        }
        if (strcmp( x, ptr->data) < 0){
            if (ptr->left == NULL){
                printf("%s no encontrado.\n", x);
                return;
            }
            buscar(ptr->left, x);
        }
        if (strcmp( x, ptr->data) > 0){
            if (ptr->right == NULL){
                printf("%s no encontrado.\n", x);
                return;
            }
            buscar(ptr->right, x);
    }
}

int main()
{
  struct node *head = NULL;
  int option = 1;
  while (option != 7){
    printf("Opcion: ");
    scanf("%d", &option);
    fflush(stdin);
    switch(option){
    case 1:
        printf("Insertar: ");
        char name[50];
        gets(name);
        fflush(stdin);
        head = insert(head, name);
        break;
    case 2:
        printf("Preorder: ");
        preOrder(head);
        printf("\n");
        break;
    case 3:
        printf("Inorder: ");
        inOrder(head);
        printf("\n");
        break;
    case 4:
        printf("Postorder: ");
        posOrder(head);
        printf("\n");
        break;
    case 5:
        printf("Por niveles: ");
        porNiveles(head);
        printf("\n");
        break;
    case 6:
        printf("Buscar: ");
        char aux[50];
        gets(aux);
        fflush(stdin);
        buscar(head, aux);
        break;

    }
  }
    printf("Salir.");
  return 0;
}
