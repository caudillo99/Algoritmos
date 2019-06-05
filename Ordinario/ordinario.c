#include <stdio.h>
#include <stdlib.h>
int factorial(int number);

int main(int argc, char const *argv[])
{
    int number;
    printf("Capture un numero: "); scanf("%d", &number);
    printf("%d! = %d\n", number, factorial(number));
    return 0;
}


int factorial(int number)
{
    if(number == 0)  return 1; 
    else return (factorial(number-1)*number);
}

