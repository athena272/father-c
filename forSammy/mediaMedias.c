#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  do {
    //Receber a lista
    char str[100];
    scanf("%[^\n]s",str);

    //Fazer a divisao dela usando strtoke
    char *eptr;
    char delim[] = ",";

    char *finalString = strtok(str, delim);
    double array[100];

    int i = 0;
    while(finalString != NULL)
    {
        double num = strtod(finalString, eptr);
        array[i] = num;
        i++;
        
        finalString = strtok(NULL, delim);
    }

  } while (str != '*')

  return 0;
}