/*
Normal parantez ve süslü parantez karakterlerini kabul eden bir program yazın. Karakter çiftlerinin eşleşip eşleşmediğini belirlemek için bir yığın kullanın. Bu doğrultuda aşağıdaki fonksiyonun gövdesini tamamlayın.
bool balanced(const char p[ ], size_t n)
// Precondition: p[0]...p[n-1] her biri '(', ')', '{' veya '}‘ olan n adet karakter içerir // Postcondition: Karakterler, her biri '(' ile eşleşen ')' ve '{'ile eşleşen
// '}'ile doğru şekilde dengelenmiş parantezler dizisi oluşturursa,
// fonksiyon true değerini döndürür.
// ( { ) } Gibi bir dizinin dengeli(eşleştirilmiş) olmadığına dikkat edin, çünkü
// parantezleri eşleriyle eşleştirmek için çizgiler çizdiğimizde, çizgiler
// birbiriyle kesişir geçer. Diğer taraftan, ( { } ) ve { ( ) } dengesi dengelidir.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct ArrayOfStack{
    int boyut;
    char *dizi;
    int top;
} STACK;

STACK *CreateStack(int DimensionOfStack){

    STACK *tempStack = (STACK *)malloc(sizeof(STACK));
    tempStack->boyut = DimensionOfStack;
    tempStack->dizi = (char *)malloc(sizeof(char) * DimensionOfStack);
    tempStack->top = -1;
    return tempStack;
}

void Push(STACK *stack, char data){
    if (stack->top == stack->boyut)
    {
        printf("stack dizisi doldu daha eleman eklenemez \n");
        return;
    }
    else
    {
        stack->top++;
        stack->dizi[stack->top] = data;
        
    }
}

char Pop(STACK*stack){
    
        char temp=stack->dizi[stack->top];
        stack->top--;
        
        return temp;
    
}

char Top(STACK*stack){

    return (stack->dizi[stack->top]);
}

void PrintStack(STACK *stack){

    for (size_t i = 0; i < stack->top; i++)
    {
        printf(" %c ", stack->dizi[i]);
    }
    printf("\n");
}

bool isEmpty(STACK*stack){
    if(stack->top==-1)
        return true;
    else 
        return false;

}
void PrintArray(char*array){
    int i=0;
    printf("--------------\n");
    while(array[i]!='\0'){
        printf("%c",array[i]);
        i++;
    }
    printf("\n");
    
    
    
}

bool isBalanced(char dizi[],size_t elemanSayisi){

    STACK *temp=CreateStack(elemanSayisi);

    for(int i=0;i<elemanSayisi;i++){
        switch (dizi[i])
    {
      case '(':
        Push(temp,dizi[i]);
        break;

      case '{':
        Push(temp,dizi[i]);
        break;

      case ')':
        if ( Top(temp) == '(')
        {
          Pop(temp);
        }else{
            Push(temp,dizi[i]);
        }
        break;
      
      case '}':
        if ( Top(temp)=='{')
        {
          Pop(temp);
        }else{
            Push(temp,dizi[i]);
        }
        break;
    }
    }

  

    if(isEmpty(temp)){
        PrintArray(dizi);
        printf(" bu dizi dengelidir \n");
        return isEmpty(temp);
     }
    else{
        PrintArray(dizi);
        printf(" bu dizi dengeli degildir \n");
        return isEmpty(temp); 
    }      

    



}










int main()
{   
    srand(time(NULL));
    int sayi=4;
    char dizi[sayi];

    for(int i=0; i<sayi;i++){
    
        int karakter=(rand()%4)+1;

        if(karakter==1){
            dizi[i]='(';
        }else if(karakter==2){
            dizi[i]=')';
        }else if(karakter==3){
            dizi[i]='{';
        }else if(karakter==4){
            dizi[i]='}';
        }
    }
    
  
    
    isBalanced(dizi,sayi);
    
    

    char dizi2[6]={'(','{','(',')','}',')'};
    isBalanced(dizi2,6);
    

    return 0;
}


