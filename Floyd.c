//María Fernanda Hernández Enriquez
//A01329383
#include <stdio.h>
void printMat(int size, int matrix[][size]){
    int i, j, data;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
         printf("| %d |", matrix[i][j]);
        }
        printf("\n");
    }

}
int main(){

    int size;
    //printf("Size: ");
    scanf("%d", &size);
    fflush(stdin);

    int i, j, data;
    int aux[size][size];
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            aux[i][j] = i + 1;
        }
    }

    int matrix[size][size];
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
         //printf("Data: ");
         scanf("%d", &data);
         fflush(stdin);
         matrix[i][j] = data;
        }
    }

    int tmp, sum;
    for(tmp = 0; tmp < size; tmp ++){
        for(i = 0; i < size; i++){
            for(j = 0; j< size; j++){
                if( i == tmp || matrix[i][tmp] == -1 || matrix[tmp][j] == -1){
                    sum = 0;
                }
                else{
                    sum = matrix[i][tmp] + matrix[tmp][j];
                    if(matrix[i][j] == -1 || sum < matrix[i][j]){
                        matrix[i][j] = sum;
                        aux[i][j] = tmp + 1;
                    }
                }
            }
        }
    }
    printf("___Matriz de adyacencia___\n");
    printMat(size,matrix);
    printf("_____Matriz de rutas______\n");
    printMat(size,aux);

 return 0;
}
