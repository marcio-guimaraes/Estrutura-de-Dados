#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("1\n");
        return 0;
    }

    int a = 1, b = 1; 
    for (int i = 2; i <= N; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    printf("%d\n", b);
    return 0;
}