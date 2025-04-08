#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[1001]; 

    scanf("%d", &n);
    scanf("%s", s);

    int max_len = 0;

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++) {
            char prev = 0;
            int valid = 1;
            int len = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == a || s[i] == b) {
                    if (s[i] == prev) {
                        valid = 0;
                        break;
                    }
                    prev = s[i];
                    len++;
                }
            }

            if (valid && len > 1 && len > max_len) {
                max_len = len;
            }
        }
    }

    printf("%d\n", max_len);

    return 0;
}
