//String Compression & Decompression
//Compress: AAACCCBBD → A3C3B2D
//Decompress: A3C3B2D → AAACCCBBD
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void compress(char str[])
{
    int i = 0;

    printf("Compressed String: ");

    while(str[i] != '\0')
    {
        char ch = str[i];
        int count = 0;

        while(str[i] == ch)
        {
            count++;
            i++;
        }

        printf("%c", ch);

        if(count > 1)
            printf("%d", count);
    }

    printf("\n");
}

void decompress(char str[])
{
    int i = 0;

    printf("Decompressed String: ");

    while(str[i] != '\0')
    {
        char ch = str[i];
        i++;

        int count = 0;

        while(isdigit(str[i]))
        {
            count = count * 10 + (str[i] - '0');
            i++;
        }

        if(count == 0)
            count = 1;

        for(int j = 0; j < count; j++)
            printf("%c", ch);
    }

    printf("\n");
}

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter original string: ");
    scanf("%s", str1);

    compress(str1);

    printf("Enter compressed string: ");
    scanf("%s", str2);

    decompress(str2);

    return 0;
}