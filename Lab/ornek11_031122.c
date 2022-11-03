#include <stdio.h>
#include <stdlib.h>

int factorialWithRecursion(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorialWithRecursion(n - 1);
}


int main(){

    printf("%d", factorialWithRecursion(5));


}