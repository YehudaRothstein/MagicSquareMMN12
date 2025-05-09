#include <stdio.h>

#define N 3  /* define the size of the matrix (N x N) */
int matrix[N][N];  /* declare the matrix */

/* Function declarations */
int isMagicMatrix();
int getMatrix();
int getExpectedSum(int n);
int printMatrix();

int main() {
    int i, j;
    /* Get the matrix input from the user */
    if (getMatrix() == 1) return 1;

    /* Print the entered matrix */
    printMatrix();

    /* Check if the matrix is a magic matrix */
    if (isMagicMatrix() == 1){
        printf("The Matrix is not a magic matrix!\n");
    } else {
        printf("The Matrix is a magic matrix!\n");
    }
    return 0;
}

/* Read matrix input */
int getMatrix(){
    int i, j, input, result;

    /* ask user for input */
    printf("Please enter %d values, while adding a whitespace between each value,\nwhen finished press ctrl + z  for windows or ctrl + d for Ubuntu \n", N * N);

    /* read exactly N*N inputs */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result = scanf("%d", &matrix[i][j]);
            /* check if the input is cut-off */
            if (result == EOF){
                printf("Error: Invalid input. Please enter enough numbers.\n");
                return 1;
            }
            /* check if the input is not an integer */
            if (result != 1) {
                printf("Error: Invalid input. Please enter only numbers.\n");
                return 1;
            }
        }
    }

    /* Check if there are more than N*N inputs */
    if (scanf("%d", &input) == 1) {
        printf("Error: Too many input values. Expected only %d numbers.\n", N * N);
        return 1;
    }

    return 0;
}

/* Prints the matrix in a formatted way */
int printMatrix(){
    int i , j;
    /* Print each element of the matrix */
    for (i = 0; i < N; i++) {
        printf("\n");
        for (j = 0; j < N; j++) {
            printf("%3d  ", matrix[i][j]);
        }
    }
    printf("\n---------------\n");
    return 0;
}

/* Checks whether the matrix is a magic matrix */
int isMagicMatrix() {
    int initSum = 0;  /* Sum of the first row */
    int tempSum = 0;  /* Temporary sum for validation */
    int fullSum = 0;  /* Sum of all elements in the matrix */
    int i, j;

    /* Calculate the full sum of the matrix */
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            fullSum += matrix[i][j];
        }
    }

    /* Compare full sum with expected sum of numbers from 1 to N*N */
    if (fullSum != getExpectedSum(N*N)) return 1;

    /* Calculate the sum of the first row */
    for (i = 0; i < N; i++){
        initSum += matrix[0][i];
    }

    /* Check that all rows sum to the same value */
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (matrix[i][j] > N*N) return 1;  /* Bad value */
            tempSum += matrix[i][j];
        }
        if (tempSum != initSum) return 1;
        tempSum = 0;
    }

    /* Check that all columns sum to the same value */
    for (i = 0; i < N; i++ ){
        for (j = 0; j < N; j++){
            if (matrix[j][i] > N*N) return 1;  /* Bad value */
            tempSum += matrix[j][i];
        }
        if (tempSum != initSum) return 1;
        tempSum = 0;
    }

    return 0;  /* Matrix is a magic matrix */
}

/* Returns the expected sum of numbers from 1 to n */
int getExpectedSum(int n){
    int sum = 0;
    int i;
    for (i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}
