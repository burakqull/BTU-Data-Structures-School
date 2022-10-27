#include <stdio.h>

int main(){
    int sayi1,sayi2;
    printf("Birinci sayiyi giriniz: ");
    scanf("%d",&sayi1);
    printf("Ikinci sayiyi giriniz: ");
    scanf("%d",&sayi2);

    
    int islem;
    printf("1-Toplama 2-Cikarma 3-Carpma 4-Bolme \n");
    printf("Yapmak istediginiz islemi seciniz: ");

    

    scanf("%d",&islem);
    

    switch (islem)
    {
    case 1:
        printf(" sonuc :  %d",sayi1+sayi2);
        break;
    case 2:
        printf(" sonuc :  %d",sayi1-sayi2);
        break;
    case 3:
        printf(" sonuc :  %d",sayi1*sayi2);
        break;
    case 4:
        printf(" sonuc :  %d",sayi1/sayi2);
        break;    

    default:
        break;
    }
    return 0;
}