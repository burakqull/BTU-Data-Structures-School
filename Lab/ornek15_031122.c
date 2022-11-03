#include <stdio.h>
#include <stdlib.h>

// fibonacci serisindeki sayıları döndüren fonksiyon
int fibonacci(int n){


    if (n==0)
    {
        return 0;
    }else if (n==1)
    {
        return 1;
    }else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
    
    

}

int main(){

    for (size_t i = 0; i < 15; i++)
    {
        printf("%d ",fibonacci(i));
    }
    





    return 0;
}