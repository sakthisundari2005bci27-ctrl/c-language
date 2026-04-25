#include <stdio.h>

int main() {
    int m[2][2] = {{1, 2}, {3, 4}}, tr[2][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            tr[j][i] = m[i][j];

    printf("Transposed Matrix:\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) printf("%d ", tr[i][j]);
        printf("\n");
    }
    return 0;
}
