//Maria Fernanda Hernandez Enriquez A01329383
//Manuel Alejandro Neri Reyes A01329872
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

typedef struct node{
   int id;
   char nombre[SIZE];
   char autor[SIZE];
   char editorial[SIZE];
   int active ;
   int h;
   struct node *left, *right, *p;
}Node; typedef Node *libroNode;

int max(int a, int b){
  if(a>b)return a;
  else return b;
}

int height(libroNode n){
   if(!n) return 0;
   return n->h;
}

libroNode newNode(int d, char n[], char a[], char b[], int act){
   libroNode temp = (libroNode)malloc(sizeof(Node));

   temp -> id = d;
   strcpy(temp->nombre, n);
   strcpy(temp->autor, a);
   strcpy(temp->editorial, b);
   temp -> active = act;
   temp -> h = 1;
   temp->left = NULL;
   temp->right = NULL;
   temp->p = NULL;

   return temp;
}

libroNode leftRotate(libroNode x){
   libroNode y = x->right;
   libroNode T2 = y->left;
   y->left = x;
   x->right = T2;
   x->h = max(height(x->left), height(x->right))+1;
   y->h = max(height(y->left), height(y->right))+1;
   return y;
}

libroNode rightRotate(libroNode y){
   libroNode x = y->left;
   libroNode T2 = x->right;
   x->right = y;
   y->left = T2;
   y->h = max(height(y->left), height(y->right))+1;
   x->h = max(height(x->left), height(x->right))+1;
   return x;
}

int getBalance(libroNode n){
   if(!n)return 0;
   return height(n->left) - height(n->right);
}

libroNode insert(libroNode head, libroNode n){
   if(head==NULL)
       return n;
   if(n->id < head->id)
       head->left=insert(head->left, n);
   else if(n->id > head->id)
       head->right=insert(head->right, n);
   else{
       return n;
   }
   n->p=head;
   head->h=1+max(height(head->left), height(head->right));
   int balance=getBalance(head);
   if(balance > 1 && (n->id) < (head->left)->id)
       return rightRotate(head);
   if(balance < -1 && (n->id) > (head->right)->id)
       return leftRotate(head);
   if(balance > 1 && (n->id) > (head->left)->id){
       head->left=leftRotate(head->left);
       return rightRotate(head);
   }
   if(balance < -1 && (n->id) < (head->right)->id){
       head->right=rightRotate(head->right);
       return leftRotate(head);
   }
   return head;
}
libroNode insertC(libroNode head, libroNode n){
   if(!head)return n;
   if(strcmp(n->nombre, head->nombre) < 0)
       head->left=insertC(head->left, n);
   else if(strcmp(n->nombre, head->nombre) > 0)
       head->right=insertC(head->right, n);
   else{
       return n;
   }
   n->p=head;
   head->h=1+max(height(head->left), height(head->right));
   int balance=getBalance(head);
   if(balance > 1 && strcmp(n->nombre,head->left->nombre) < 0)
       return rightRotate(head);
   if(balance < -1 && strcmp(n->nombre,head->right->nombre) > 0)
       return leftRotate(head);
   if(balance > 1 && strcmp(n->nombre,head->left->nombre) > 0){
       head->left=leftRotate(head->left);
       return rightRotate(head);
   }
   if(balance < -1 && strcmp(n->nombre,head->right->nombre) < 0){
       head->right=rightRotate(head->right);
       return leftRotate(head);
   }
   return head;
}


void print(libroNode head){
  printf("\n___________________________\n");
   printf("Id: %d\n", head -> id);
   printf("Nombre: %s\n", head->nombre);
   printf("Autor: %s\n", head->autor);
   printf("Editorial: %s\n", head->editorial);
   printf("___________________________\n");
}

struct node * search(libroNode head, int x){
   libroNode aux = head;
   if(aux == NULL || x == aux->id)
       return aux;
   if(x<aux->id)
       return search(aux->left, x);
   else return search(aux->right, x);
}
struct node * searchC(libroNode head, char x[]){
   libroNode aux = head;
   //printf("{%s -- %s}\n", x, aux->nombre);
   int result = strcmp(x, aux->nombre);
   //printf("%d\n", result);
   if(result == 0){
       return aux;
     }
    else if(result < 0){
       return searchC(aux->left, x);
     }
   else if(result > 0) {
     return searchC(aux->right, x);}
}

void _search(libroNode head, char k[]){
   if(!head)return;
   _search(head->left, k);
   if((strcmp(head->nombre, k) == 0 || strcmp(head->autor, k) == 0 || strcmp(head->editorial, k) == 0) && head->active == 1)
       print(head);
   _search(head->right, k);
}

void edit(libroNode *head, char nombre[SIZE], char autor[SIZE], char editorial[SIZE]){
   strcpy((*head)->nombre, nombre);
   strcpy((*head)->autor, autor);
   strcpy((*head)->editorial, editorial);
}

void order(libroNode head, libroNode hOtro){
   if(hOtro){
       order(head, hOtro->left);
       if(head->active == 1){
           print(search(head, hOtro->id));
       }
       order(head, hOtro->right);
   }
}
void orderCon(libroNode head, libroNode hOtro){
   if(hOtro){
       orderCon(head, hOtro->right);
       if(head->active == 1){
           print(search(head, hOtro->id));
       }
       orderCon(head, hOtro->left);
   }
}

void printMenor(libroNode head, int id){
    if(head){
       printMenor(head->left, id);
       if(head->active == 1 && head->id <= id){
           print(head);
       }
       printMenor(head->right, id);
   }
}

void printMayor(libroNode head, int id){
   if(head){
       printMayor(head->left, id);
       if(head->active == 1 && head->id >= id){
           print(head);
       }
       printMayor(head->right, id);
   }
}

void substring(libroNode head, char data[]){
	if(head){
       substring(head->left, data);
       if(head->active == 1){
       			char * res;
       			res = strstr(head->nombre, data);
       			if(res == NULL)
       				res = strstr(head->autor, data);
       			if(res == NULL)
       				res = strstr(head->editorial, data);
       		if(res != NULL){
       			print(head);
       		}
       	}
       substring(head->right, data);
   }
}

struct node * subFile(libroNode head, char data[]){
	if(head){
       subFile(head->left, data);
       if(head->active == 1){
       			char * res;
       			res = strstr(head->nombre, data);
       			if(res == NULL)
       				res = strstr(head->autor, data);
       			if(res == NULL)
       				res = strstr(head->editorial, data);
       		if(res != NULL){
       			return head;
       		}
       	}
       subFile(head->right, data);
   }
}

void print_Menor(FILE *fp, libroNode head, int id){
   if(head != NULL){
       print_Menor(fp, head->left, id);
       if(head->active == 1 && head->id <= id){
           fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
       }
       print_Menor(fp, head->right, id);
   }
}

void print_Mayor(FILE *fp, libroNode head, int id){
   if(head != NULL){
       print_Mayor(fp, head->left, id);
       if(head->active == 1 && head->id >= id){
           fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
       }
       print_Mayor(fp, head->right, id);
   }
}

void print_MenorC(FILE *fp, libroNode head, char data[]){
   if(head != NULL){
       print_MenorC(fp, head->left, data);
       if(head->active == 1 && strcmp(head->nombre, data)<=0){
           fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
       }
       print_MenorC(fp, head->right, data);
   }
}

void print_MayorC(FILE *fp, libroNode head, char data[]){
   if(head != NULL){
       print_MayorC(fp, head->left, data);
       if(head->active == 1 && strcmp(head->nombre, data)>=0){
           fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
       }
       print_MayorC(fp, head->right, data);
   }
}

void saveExacto(libroNode head, char p[]){
   FILE *fp;
   char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   fp = fopen(buffer, "w+");
   fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
   fclose(fp);
}

void saveOrden(libroNode head, char p[], int id, int cond){
   FILE *fp;
   char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   fp = fopen(buffer, "w+");
   if(cond == 1){
      print_Menor(fp, head, id);
    }
    else if(cond == 2){
      print_Mayor(fp, head, id);
    }
   fclose(fp);
}

void saveOrdenC(libroNode head, char p[], char data[], int cond){
   FILE *fp;
   char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   fp = fopen(buffer, "w+");
   if(cond == 1){
      print_MenorC(fp, head, data);
    }
    else if(cond == 2){
      print_MayorC(fp, head, data);
    }
   fclose(fp);
}

void _print(FILE *fp, libroNode head){
   if(head != NULL){
       _print(fp, head->left);
           fprintf(fp, "%d %s %s %s %d\n", head->id, head->nombre, head->autor, head->editorial, head->active);
       _print(fp, head->right);
   }
}

void saveFile(libroNode head, char p[]){
   FILE *fp;
   char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   fp = fopen(buffer, "w+");
   _print(fp, head);
   fclose(fp);
}

libroNode loadFile(char p[]){
   libroNode head = NULL;
   int id;
   char nombre[SIZE];
   int act;
   char autor[SIZE];
   char editorial[SIZE];
    char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   FILE *fp;
   fp = fopen(buffer, "a+");
   if(!fp){
       printf("No se ha podido encontrar el archivo\n" );
       return NULL;
   }
   else{
       while(fscanf(fp, "%d %s %s %s %d", &id, nombre, autor, editorial, &act) != EOF){
           head = insert(head, newNode(id, nombre, autor, editorial, act));
       }
       return head;
   }
}

libroNode loadInicio(char p[]){
   libroNode head = NULL;
   int id;
   char nombre[SIZE];
   int act;
   char autor[SIZE];
   char editorial[SIZE];
    char buffer[200];
   snprintf(buffer, strlen(p)+5, "%s.txt", p);
   FILE *fp;
   fp = fopen(buffer, "r");
   if(!fp){
       printf("No se ha podido encontrar el archivo\n" );
       return NULL;
   }
   else{
       while(fscanf(fp, "%d %s %s %s %d", &id, nombre, autor, editorial, &act) != EOF){
           head = insert(head, newNode(id, nombre, autor, editorial, act));
       }
       return head;
   }
}


int main(){
   int keep = 1;
   int opcion;
   int id;
   char nombre[SIZE];
   char autor[SIZE];
   char editorial[SIZE];
   char o;
   int sub;
   char p[SIZE];
   char s[SIZE];
   libroNode head = NULL;
   libroNode hNombre = NULL;
   libroNode hAutor = NULL;
   libroNode hEditor = NULL;

   libroNode temp = NULL;
   libroNode tNombre = NULL;
   libroNode tAutor = NULL;
   libroNode tEditor = NULL;


   libroNode headTmp = NULL;

   //loadFile("data");
    printf("LIBRERiA EL CASTORCITO FELIZ\n");
    while(keep == 1){
        printf("\n---------------------------\nElija una opcion\n");
        printf(" 1. Insertar un nuevo libro\n 2. Eliminar libro \n 3. Editar informacion \n 4. Informe total \n 5. Busqueda \n 6. Reportes de busquedas \n 7. Herramientas administrativas \n 0. Salir \n" );
        printf("---------------------------\n" );
        printf("\nOpcion: " );
        fflush( stdin );
        scanf("%d", &opcion);
           switch(opcion){
               case 1:
                        printf("Insertar nuevo libro.\n");
                        printf("ID: ");
                        fflush( stdout );
                        scanf("%d\n", &id);
                        while(search(head, id) != NULL){
                            printf("ID repetido. Ingrese un nuevo ID: " );
                            fflush( stdout );
                            scanf("%d \n", &id);

                        }
                        fflush(stdin);
                        printf("Nombre del libro: ");
                        gets(nombre);
                        fflush(stdin);
                        printf("Autor: ");
                       	gets(autor);
                        fflush(stdin);
                        printf("Editorial: ");
                        gets(editorial);
                        fflush(stdin);
                           head = insert(head, newNode(id, nombre, autor, editorial, 1));
                           hNombre = insertC(hNombre, newNode(id, nombre, nombre, nombre, 1));
                           hAutor = insertC(hAutor, newNode(id, autor, autor, autor, 1));
                           hEditor = insertC(hEditor, newNode(id, editorial, editorial, editorial, 1));
                           printf("Libro guardado.\n");
                   break;
               case 2:
                       printf("Elmininar libro.\n");
                       printf("ID: ");
                       fflush( stdout );
                       scanf("%d ", &id);
                       temp = search(head, id);
                       while(temp == NULL){
                           printf("ID no encontrado.\n Ingrese un nuevo ID: ");
                           fflush( stdout );
                           scanf("%d ", &id);
                           temp = search(head, id);
                       }
                       tNombre = search(hNombre, id);
                       tAutor = search(hAutor, id);
                       tEditor = search(hEditor, id);
                       print(temp);
                       printf("Deseas eliminar el libro? (S,N)\n");
                       fflush( stdout );
                       scanf("%c", &o);
                       if(o == 'S' || o == 's'){
                           temp->active = 0;
                           tNombre->active = 0;
                           tAutor->active = 0;
                           tEditor->active = 0;
                           printf("Libro con ID: %i eliminado.\n", id);
                       }

                   break;
               case 3:
                        printf("Editar un libro.\n");
                        printf("ID: ");
                        fflush( stdout );
                        scanf("%d", &id);
                        temp = search(head, id);
                        while(temp == NULL){
                            printf("ID no encontrado.\n Ingrese un nuevo ID: ");
                            fflush( stdout );
                            scanf("%d", &id);
                            temp = search(head, id);
                        }

                       tNombre = search(hNombre, id);
                       tAutor = search(hAutor, id);
                       tEditor = search(hEditor, id);
                       print(temp);
                       printf("*El ID no es editable*\n");
                       printf("Nombre: ");
                       gets(nombre);
                       printf("Autor: ");
                       gets(autor);
                       printf("Editorial: ");
                       gets(editorial);
                       edit(&temp, nombre, autor, editorial);
                       edit(&tNombre, nombre, nombre, nombre);
                       edit(&tAutor, autor, autor, autor);
                       edit(&tEditor, editorial, editorial, editorial);
                       print(temp);
                       printf("Libro actualizado.\n");
                   break;
               case 4:
                        printf("Informe total.\n");
                        printf("1. Orden ascendente por id.\n 2. Orden descendiente por id.\n 3. Orden ascendente por Nombre.\n 4. Orden descendente por Nombre.\n 5. Orden ascendente por Autor.\n 6. Orden descendente por Autor.\n 7. Orden ascendente por Editorial.\n 8. Orden descendente por Editorial.\n");
                        fflush( stdout );
                        scanf("%d", &sub);
                       	switch(sub){
                        	case 1:
                                printf("ID Ascendente:\n" );
                                order(head, head);
                               	break;
                           case 2:
                                printf("ID Descendiente:\n" );
                                orderCon(head,head);
                               	break;
                           case 3:
                                printf("Nombre Ascendente:\n" );
                                order(head, hNombre);
                               	break;
                           case 4:
                                printf("Nombre Descendente:\n" );
                                orderCon(head,hNombre);
                               	break;
                           case 5:
                                printf("Autor Ascendente:\n" );
                                order(head, hAutor);
                               	break;
                           case 6:
                                printf("Autor Descendente:\n" );
                                orderCon(head, hAutor);
                               	break;
                           case 7:
                                printf("Editorial Ascendente:\n" );
                                order(head, hEditor);
                               	break;
                           case 8:
                                printf("Editorial Descendente:\n" );
                                orderCon(head, hEditor);
                               	break;
                           default:
                               	printf("Opcion invalida.\n");
                               	break;
                       }
                       printf("\nFin del informe.\n");
                   break;
                   case 5:
                           		printf("Busqueda.\n");
                           	printf("1. Buscar ID \n2. Buscar en otros campos\n");
                            fflush( stdout );
                           	scanf("%d ", &sub);
                            	switch (sub) {
                               	case 1:
   	                             printf("Busqueda por ID\n");
   	                             printf("1. Coincidencia Exacta\n2. valores menores o iguales a ID\n3. valores mayores o iguales a ID\n");
                                 fflush( stdout );
   	                             scanf("%d", &sub);

   	                             switch(sub){
                                    	case 1:
                                     printf("Ingrese el ID a buscar: ");
                                     fflush( stdout );
      	                             scanf("%d", &id);
                                           printf("Coincidencia exacta.\n");
                                           temp = search(head, id);
                                           print(temp);
                                        	break;
                                    	case 2:
                                     printf("Ingrese el ID a buscar: ");
                                     fflush( stdout );
      	                             scanf("%d", &id);
                                           printf("Valores menor o iguales a ID\n");
                                          	printMenor(head, id);
                                        	break;
                                    case 3:
                                    printf("Ingrese el ID a buscar: ");
                                    fflush( stdout );
     	                             scanf("%d", &id);
                                           printf("Valores mayores o iguales a ID\n");
                                           printMayor(head, id);
                                        	break;
                                    default:
                                    		printf("Opcion invalida.\n");
                                        	break;
                                   }
                                   break;
                               case 2:
                                   printf("Busqueda por otros campos\n");
                                   printf("1. Coincidencia exacta\n2. Coincidencia parcial\n" );
                                   fflush( stdout );
                                   scanf("%d ", &sub);

                                   switch(sub){
                                       case 1:
                                       printf("Nombre del libro, el autor o la editorial: ");
                                       gets(p);
                                           _search(head, p);
                                           break;
                                       case 2:
                                       printf("Nombre del libro, el autor o la editorial: ");
                                       gets(p);
                                       	substring(head, p);
                                           break;
                                       default:
                                           printf("No se recibio un dato correcto\n");
                                           break;
                                   }
                                   break;
                               default:
                                   printf("Opcion invalida.\n");
                                   break;
                              }
                           printf("Fin de busqueda.\n");
                           break;
               case 6:
                		printf("Reportes de busqueda.\n");
                		printf("Nombre del archivo: ");
                		gets(p);
                      	printf("1. Buscar ID.\n2. Buscar en otros campos.\n");
                        fflush( stdout );
                      	scanf("%d", &sub);
                      	switch (sub) {
                        	case 1:
	                         printf("Reporte por ID.\n");
	                         printf("1. Coincidencia Exacta.\n2. Valores menores o iguales a ID.\n3. Valores mayores o iguales a ID.\n");
                           fflush( stdout );
	                         scanf("%d", &sub);
	                         printf("Ingrese el ID a buscar: ");
                           fflush( stdout );
	                         scanf("%d", &id);
	                         switch(sub){
                             	case 1:
                                    saveExacto(search(head, id),p);
                                    break;
                             	case 2:
                                    temp = search(head, id);
                                    saveOrden(temp, p, id, 1);
                                 	  break;
                             	case 3:
                                    temp = search(head, id);
                                    saveOrden(temp, p, id, 2);
                                 	  break;
                             	default:
                             		printf("No se recibio un dato correcto.\n");
                                 	break;
                         	}
                         	break;

                        case 2:
                        printf("Reporte por otro campo.\n");
                        printf("1. Coincidencia exacta\n2. Coincidencia parcial\n" );
                        fflush( stdout );
                        scanf("%d", &sub);
                        switch(sub){
                            case 1:
                                    printf("1)Nombre. 2)Autor. 3)Editorial\n ");
                                    printf("Opcion: ");
                                    fflush( stdout );
                                    scanf("%d ", &sub);
                                    switch(sub){
                                    case 1:
                                        printf("Nombre: ");
                                        fflush(stdin);
                                        gets(s);
                                        saveExacto(searchC(hNombre, s), p);
                                        break;
                                    case 2:
                                        saveExacto(searchC(hAutor, s), p);
                                        break;
                                    case 3:
                                        saveExacto(searchC(hEditor, s), p);
                                        break;
                                    default:
                                        printf("Opcion invalida\n");
                                        break;
                                    }
                                break;
                            case 2:
                                    printf("1)Nombre.\n 2)Autor.\n 3)Editorial\n");
                                    fflush( stdout );
                                    scanf("%d", &sub);
                                    printf("Ingresa: ");
                                    gets(s);
                                    fflush(stdin);
                                    switch(sub){
                                    case 1:
                                        temp = subFile(head, s);
                                        saveFile(temp, p);
                                        break;
                                    case 2:
                                        temp = subFile(head, s);
                                        saveFile(temp, p);
                                        break;
                                    case 3:
                                        temp = subFile(head, s);
                                        saveFile(temp, p);
                                        break;
                                    }
                                break;
                            default: printf("No se recibio un dato correcto\n");
                                break;
                        }

                        default: printf("No se recibio un dato correcto\n");
                        break;
                       }

                       printf("Resultados reportados.\n");
                   break;
               case 7:
                        printf("Herramientas administrativas.\n");
                        printf("1. Guardar una copia de seguridad.\n 2. Cargar dato.\n");
                        fflush( stdout );
                       scanf("%d", &sub);
                       if(sub == 1){
                           printf("Nombre del archivo: ");
                           gets(p);
                           saveFile(head, p);
                           printf("Archivo guardado.\n");
                       }
                       else if(sub==2){
                           printf("Nombre del archivo:");
                           gets(p);
                           head = loadFile(p);
                           printf("Archivo cargado.\n");
                       }
                       else{
                           printf("Opción no válida.\n");
                       }
                       printf("Saliendo de herramientas.\n");
                   break;
                 case 0:
                         keep = 0;
                   break;
               default:
                       printf("Opcion invalida.\n");
                   break;
           }

   }

      char save[SIZE]={"data"};
   saveFile(head, save);
    free(head);

   free(temp);
   printf("Saliendo de la libreria.");
}
