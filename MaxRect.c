//Maximum Sum Rectangle in a Matrix
#include <stdio.h>
#include <limits.h>

int summax(int arr[], int n)
{
    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(currSum < 0)
            currSum = arr[i];
        else
            currSum += arr[i];

        if(currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}

int main()
{
    int r, c;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    int mat[r][c];

    printf("Enter matrix:\n");

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int maxSum = INT_MIN;

    for(int left = 0; left < c; left++)
    {
        int temp[r];

        for(int i = 0; i < r; i++)
            temp[i] = 0;

        for(int right = left; right < c; right++)
        {
            for(int i = 0; i < r; i++)
                temp[i] += mat[i][right];

            int sum = summax(temp, r);

            if(sum > maxSum)
                maxSum = sum;
        }
    }

    printf("Maximum Sum Rectangle = %d\n", maxSum);

    return 0;
}