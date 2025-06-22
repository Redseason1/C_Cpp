#include <stdio.h>

void print(int arr[]);

int main(){

    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    //count non-0 elements -> rows the matrix needs 
    int size = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            if (sparseMatrix[i][j] != 0) size++;
        }
    }

    // Make a new matrix     
    int compactMatrix[3][size]; //3 means how many rows contain elements, size means how many columns the matrix needs
    int k = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            if (sparseMatrix[i][j] != 0){
                compactMatrix[0][k] = i;  //store the row where the element is
                compactMatrix[1][k] = j;  //store the column where the element is
                compactMatrix[2][k] = sparseMatrix[i][j];  //store the value of the element
                k++;
            }
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<size; j++){
            printf("%d ", compactMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}