#include <stdio.h>
#include <stdlib.h>

// pointer ile 2 sayının değerlerini değiştir

void degistir(int *number1,int *number2){

    int temp;
    temp=*number1;
    *number1=*number2;
    *number2=temp;

    



}



int main(){
    int number1 =5;
    int number2 =10;

    printf("number1=%d number2=%d",number1,number2);
    degistir(&number1,&number2);
    printf("\n ");
    printf("number1=%d number2=%d",number1,number2);







    return 0 ;
}