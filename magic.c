#include <stdio.h>

#define N 2

int isMagicMatrix(int m[N][N]);
int getExpectedSum(int n);

int main() {
    int matrix[N][N];
    int res;
    // Input characters
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Error: Invalid input. Please enter only numbers.\n");
                return 1;
            }
        }
    }

    // Print matrix
    for (int i = 0; i < N; i++) {
        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
    }

    printf("\n---------------\n");

    if (isMagicMatrix(matrix) == 1){
        printf("The Matrix is not a mgic matrix!\n");
    }
    
    return 0;
}

int isMagicMatrix(int m[N][N]) {
    int initSum = 0;
    int tempSum = 0;
    int fullSum = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fullSum += m[i][j];
        }
    }

    if (fullSum != getExpectedSum(N*N)) return 1;

    for (int i = 0; i < N; i++){
        initSum += m[0][i];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (m[i][j] > N*N) return 1;
            tempSum += m[i][j];
        }
        if (tempSum != initSum) return 1;
        tempSum = 0;
    }
    
    for (int i = 0; i < N; i++ ){
        for (int j = 0; j < N; j++){
            if (m[j][i] > N*N) return 1;
            tempSum += m[j][i];
        }
        if (tempSum != initSum) return 1;
        tempSum = 0;
    }
    return 0;
}

int getExpectedSum(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

