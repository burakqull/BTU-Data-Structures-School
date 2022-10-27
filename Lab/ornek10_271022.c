#include <stdio.h>
#include <stdlib.h>
#include "ornek10_271022.h"


int main(){

    int * newData=NULL;
    int * nodeData=NULL;
    NODE * node=NULL;
    newData=(int*)malloc(sizeof(int));
    *newData=77;
    node=createNode(newData);
    nodeData=(int*)(node->dataPtr);

    printf("Data from node %d \n",*nodeData);
    printf("Data from node %d \n",*(int*)(node->dataPtr));

    



    return 0 ;

}