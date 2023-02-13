#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t1[45];
    int t2[30];

    for (int i = 0; i < 45; i++)
    {
        scanf("%i", &t1[i]);
    }
    for (int n = 0; n < 30; n++)
    {
        scanf("%i", &t2[n]);
    }

    for (int x = 0; x < 45; x++)
    {
        for (int k = 0; k < 30; k++)
        {
            if (t1[x] == t2[k])
            {
                printf("%i ", t1[x]);
            }
        }
    }
    
}