#include <stdio.h>

int main(){
    /*
    kullanıcıdan bir sayı al ve tekse 3 ile çarp
    çiftse 2 ile çarp
    */

    int sayi;
    printf("sayi giriniz :");
    scanf("%d",&sayi);

    if (sayi%2==0)
    {
        printf("sayi cifttir");
        sayi=2*sayi;
        printf("sayi : %d",sayi);

    }else
    {
        printf("sayi tektir");
        sayi=3*sayi;
        printf("sayi : %d",sayi);
    }
    return 0;
    
}