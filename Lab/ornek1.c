#include <stdio.h>
#include <locale.h>


int main(){
    /*
    sınav notunu kullanıcıdan al ve harf notunu ekrana yazdır.
    */
    
    printf("sınav notunuzu giriniz :");
    int not;
    scanf("%d",&not);
    

    if (not>90)
    {
        printf("notunuz AA ");
    }else if (not>85 && not<90)
    {
        printf("notunuz BA ");
    }else if (not <85 && not >70)
    {   
        printf("notunuz CB  ");
    }else if (not<70 && not >60)
    {
        printf("notunuz CC ");
    }else if (not<60 && not>50)
    {
        printf("notunuz DC ");
    }else if (not<50)
    {   
        printf("notunuz FF KALDINIZ ");
    }
    
    return 0;
    
    
    
    
    
}