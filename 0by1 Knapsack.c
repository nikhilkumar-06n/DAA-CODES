#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int i, j, n, m;
    int w[10], p[10], v[10][10];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(w[i] <= j)
                v[i][j] = max(p[i] + v[i-1][j-w[i]], v[i-1][j]);
            else
                v[i][j] = v[i-1][j];
        }
    }

    printf("Maximum profit = %d", v[n][m]);

    return 0;
}
