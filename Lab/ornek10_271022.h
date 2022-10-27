#ifndef ornek10_271022
#define ornek10_271022

typedef struct node
{
    void * dataPtr;
    struct node * link;

}NODE;

NODE* createNode(void* itemPtr){

    NODE *nodePtr=NULL;
    nodePtr=malloc(sizeof(NODE));
    nodePtr->dataPtr=itemPtr;
    nodePtr->link=NULL;
    return nodePtr;




}



#endif