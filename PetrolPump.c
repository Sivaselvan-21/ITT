//Petrol Pump Circular Tour
#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of petrol pumps: ");
    scanf("%d",&n);

    int petrol[n];
    int distance[n];

    printf("Enter petrol values:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&petrol[i]);

    printf("Enter distance values:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&distance[i]);

    int start=0;
    int balance=0;
    int deficit=0;

    for(int i=0;i<n;i++)
    {
        balance += petrol[i]-distance[i];

        if(balance<0)
        {
            start=i+1;
            deficit+=balance;
            balance=0;
        }
    }

    if(balance+deficit>=0)
        printf("Starting Pump Index = %d\n",start);
    else
        printf("-1\n");

    return 0;
}