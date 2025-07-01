#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    while (scanf("%d", &n) && n != 0)
    {
        int p1 = 0, p2 = 0;

        for (int i = 0; i < n; i++)
        {
            char cmd[10];
            int m;
            scanf("%s %d", cmd, &m);

            if (strcmp(cmd, "DROP") == 0)
            {
                printf("DROP 2 %d\n", m);
                p2 += m;
            }
            else if (strcmp(cmd, "TAKE") == 0)
            {
                if (p1 == 0)
                {
                    if (p2 > 0)
                    {
                        printf("MOVE 2->1 %d\n", p2);
                        p1 = p2;
                        p2 = 0;
                    }
                }

                if (m <= p1)
                {
                    printf("TAKE 1 %d\n", m);
                    p1 -= m;
                }
                else
                {
                    printf("TAKE 1 %d\n", p1);
                    m -= p1;
                    p1 = 0;
                    if (p2 > 0)
                    {
                        printf("MOVE 2->1 %d\n", p2);
                        p1 = p2;
                        p2 = 0;
                    }
                    printf("TAKE 1 %d\n", m);
                    p1 -= m;
                }
            }
        }

        printf("\n");
    }

    return 0;
}
