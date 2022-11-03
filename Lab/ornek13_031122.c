#include <stdio.h>
#include <stdlib.h>


int max(int *dizi, int boyut){
    int max = dizi[0];
    for (int i = 1; i < boyut; i++)
    {
        if (dizi[i] > max)
            max = dizi[i];
    }
    return max;



}




int main(){
    int dizi[5]={1,2,3,4,5};
    printf("%d",max(dizi,5));
    return 0;


}