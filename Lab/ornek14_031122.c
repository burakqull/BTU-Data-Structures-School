#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//indeksten itibaren döndüren fonksiyon
char* dondur(char*p,int indeks){

    int uzunluk=strlen(p);
    if (indeks>=uzunluk) 
    {
        return NULL;
    }else
    {
        return p+indeks;

    }
    

    
    


}


int main(){
    char* p="BursaTeknikUniversitesi";
    printf("%s",dondur(p,1));


    return 0 ;
}