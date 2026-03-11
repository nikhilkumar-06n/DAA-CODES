#include <stdio.h>

int w[10], x[10];

void subset(int s, int k, int r, int m, int n)
{
    int i;

    x[k] = 1;

    if(s + w[k] == m)
    {
        printf("Subset: ");
        for(i = 1; i <= k; i++)
        {
            if(x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
    }
    else if(s + w[k] + w[k+1] <= m)
    {
        subset(s + w[k], k + 1, r - w[k], m, n);
    }

    if((s + r - w[k] >= m) && (s + w[k+1] <= m))
    {
        x[k] = 0;
        subset(s, k + 1, r - w[k], m, n);
    }
}

int main()
{
    int i, n, m, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter required sum: ");
    scanf("%d", &m);

    subset(0, 1, sum, m, n);

    return 0;
}
