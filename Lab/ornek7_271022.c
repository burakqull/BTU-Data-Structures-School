#include <stdio.h>
#include <stdlib.h>

// void tipinde bir pointer tanımla
// int tipinde (7) ve float tipinde (23.5) ikimdeğişken tanımla 
// p kullanarak int ve floatın değerini yaz

int main(){

    void *p=NULL;
    int number1=7;
    float number2=23.5;
    p=&number1;
    
    printf("number1=%d",*(int*)p);
    p=&number2;
    printf("number2=%f",*(float*)p);

    



    return 0 ;
}