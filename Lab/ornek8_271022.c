#include <stdio.h>
#include <stdlib.h>


int main(){


    int a;
    int *p;
    int**q;

    a=58;
    p=&a;
    q=&p;

    printf("a=%d\n",a);
    printf("*p=%d\n",*p);
    printf("**q=%d\n",**q);





    return 0 ;

}