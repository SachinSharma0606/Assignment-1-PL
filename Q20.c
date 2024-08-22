#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int minDistance(const char *s, const char *t)
{
    int i,j;
    int m = strlen(s);
    int n = strlen(t);
    // Create a 2D array to store the edit distances
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (i = 0; i <= m; ++i)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    // Initialize the base cases
    for (i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (j = 0; j <= n; ++j)
        dp[0][j] = j;
    // Fill the dp table
    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    int result = dp[m][n];
    // Free the allocated memory
    for (i = 0; i <= m; ++i) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main()
{
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s",s);
    printf("Enter the second string: ");
    scanf("%s",t);
    // Compute and display the minimum number of operations
    int result = minDistance(s, t);
    printf("\nThe minimum number of operations required: %d\n", result);
    return 0;
}
