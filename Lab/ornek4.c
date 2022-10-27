#include <stdio.h>

int main(){




    int sayi;
    printf("sayi giriniz :");
    scanf("%d",&sayi);
    int faktoriyel=1;
    for (int i = 1; i <= sayi; i++)
    {
        faktoriyel=faktoriyel*i;
        printf(" %d! : %d \n",i,faktoriyel);
    }
    


    return 0;
}