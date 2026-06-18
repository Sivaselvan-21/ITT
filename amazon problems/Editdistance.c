//count number of edits needed to achieve the given state
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;

    if(b < min)
        min = b;

    if(c < min)
        min = c;

    return min;
}

int main()
{
    char s[101];
    char t[101];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    int n = strlen(s);
    int m = strlen(t);

    int dp[101][101];

    for(int i = 0; i <= n; i++)
        dp[i][0] = i;

    for(int j = 0; j <= m; j++)
        dp[0][j] = j;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 +
                           minimum(dp[i - 1][j],     // Delete
                                   dp[i][j - 1],     // Insert
                                   dp[i - 1][j - 1]);// Replace
            }
        }
    }

    printf("Edit Distance = %d\n", dp[n][m]);

    return 0;
}