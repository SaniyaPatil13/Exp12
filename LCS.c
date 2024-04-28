#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char X[MAX], Y[MAX];
    int L[MAX + 1][MAX + 1]; // LCS length table
    int m, n, i, j;

    // Input the first string
    printf("Enter the first string: ");
    scanf("%999s", X);  // Read up to 999 characters

    // Input the second string
    printf("Enter the second string: ");
    scanf("%999s", Y);  // Read up to 999 characters

    m = strlen(X);
    n = strlen(Y);

    // Building the LCS table in bottom-up manner
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Initialize the borders of the matrix with 0
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // Diagonal increment
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1]; // Take the max of left and top values
            }
        }
    }

    // The length of LCS is now stored in L[m][n]
    printf("The length of LCS is %d\n", L[m][n]);

    return 0;
}
