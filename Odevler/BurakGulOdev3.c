/*
kuyruk yapısını kullanarak prefix ifadelerin sonucunu hesaplayan genel bir uygulama c ile yazılacak.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    char *data;
    struct Node *next;
} NODE;

typedef struct Que
{
    NODE *front;
    NODE *rear;
    int count;
} QUE;

void initQue(QUE *que)
{
    que->front = NULL;
    que->rear = NULL;
    que->count = 0;
}

QUE *CreateQue()
{
    QUE *que = (QUE *)malloc(sizeof(QUE));
    initQue(que);
    return que;
}

void Enque(QUE *que, char *data)
{
    // printf("Enque calisacak \n");
    NODE *node = (NODE *)malloc(sizeof(NODE));

    node->data = data;
    node->next = NULL;

    if (que->count == 0)
    {
        que->front = node;
        que->rear = node;
    }
    else
    {
        que->rear->next = node;
        que->rear = node;
    }
    que->count++;
    // printf("Enque calisti \n");
}

char *Deque(QUE *que)
{
    if (que->count == 0)
    {
        return NULL;
    }
    else
    {
        NODE *node = que->front;
        char *data = node->data;
        que->front = node->next;
        free(node);
        que->count--;
        return data;
    }
}

void PrintQue(QUE *que)
{
    if (que->count == 0)
    {
        printf("Queue is empty");
        return;
    }

    NODE *node = que->front;
    while (node->next != NULL)
    {
        printf("%s > ", node->data);

        node = node->next;
    }
    printf("%s \n", node->data);
}

char *Peek(QUE *que)
{
    if (que->count == 0)
    {
        return NULL;
    }
    else
    {
        return que->front->data;
    }
}

bool isOperator(char data)
{

    if (data == '+' || data == '-' || data == '*' || data == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOperand(char data)
{
    if (data >= '0' && data <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSpace(char data)
{
    if (data == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ConvertStringToQue(QUE *que, char *data)
{

    int i = 0;
    while (data[i] != '\0')
    {
        if (isSpace(data[i]))
        {

            i++;
            continue;
        }
        else if (isOperator(data[i]))
        {

            char *temp = (char *)malloc(sizeof(char));
            temp[0] = data[i];
            temp[1] = '\0';
            Enque(que, temp);
            i++;
        }
        else if (isOperand(data[i]))
        {
            int j = 0;
            char *temp = (char *)malloc(sizeof(char));
            while (!isSpace(data[i]) && data[i] != '\0' && !isOperator(data[i]))
            {
                temp[j] = data[i];
                j++;
                i++;
            }
            temp[j] = '\0';
            Enque(que, temp);
        }
        else
        {
            printf("Invalid character \n");
            return;
        }
    }
}

QUE *ScanQue(QUE *que)
{

    QUE *geciciQue = CreateQue();
    NODE *iter = que->front;
    int number1, number2, result;
    char *temp = NULL;

    while (iter != NULL)
    {
        if (isOperator(*(iter->data)) && isOperand(*(iter->next->data)) && isOperand(*(iter->next->next->data)))
        {
            switch (*(iter->data))
            {
            case '+':
                number1 = atoi(iter->next->data);
                number2 = atoi(iter->next->next->data);
                result = number1 + number2;
                temp = (char *)malloc(sizeof(char));
                sprintf(temp, "%d", result);
                Enque(geciciQue, temp);
                // printf(" + operatoru var , %d ile %d toplami %d \n",number1,number2,result);
                iter = iter->next->next;
                break;
            case '-':
                number1 = atoi(iter->next->data);
                number2 = atoi(iter->next->next->data);
                result = number1 - number2;
                temp = (char *)malloc(sizeof(char));
                sprintf(temp, "%d", result);
                Enque(geciciQue, temp);
                // printf(" - operatoru var , %d ile %d farki %d \n",number1,number2,result);
                iter = iter->next->next;
                break;
            case '*':
                number1 = atoi(iter->next->data);
                number2 = atoi(iter->next->next->data);
                result = number1 * number2;
                temp = (char *)malloc(sizeof(char));
                sprintf(temp, "%d", result);
                Enque(geciciQue, temp);
                // printf(" * operatoru var , %d ile %d carpimi %d \n",number1,number2,result);
                iter = iter->next->next;
                break;
            case '/':
                number1 = atoi(iter->next->data);
                number2 = atoi(iter->next->next->data);
                result = number1 / number2;
                temp = (char *)malloc(sizeof(char));
                sprintf(temp, "%d", result);
                Enque(geciciQue, temp);
                // printf(" / operatoru var , %d ile %d bolumu %d \n",number1,number2,result);
                iter = iter->next->next;
                break;

            default:
                break;
            }
        }
        else if (isOperator(*(iter->data)))
        {

            Enque(geciciQue, iter->data);
            // printf(" %c operatoru var \n",*(iter->data));
        }
        else if (isOperand(*(iter->data)))
        {
            Enque(geciciQue, iter->data);
            // printf(" %s sayisi var \n",iter->data);
        }
        else
        {
            printf("Invalid character \n");
        }

        iter = iter->next;
    }

    return geciciQue;
}

int GetValueOfPrefix(QUE *que)
{
    QUE *geciciQue = CreateQue();

    if (que->count == 1)
    {
        return atoi(que->front->data);
    }
    else
    {
        geciciQue = ScanQue(que);
        return GetValueOfPrefix(geciciQue);
    }
}

void program_start()
{
    char *data = (char *)malloc(sizeof(char));
    QUE *que = CreateQue();
    printf("Enter a prefix expression : ");
    scanf("%[^\n]s", data);

    ConvertStringToQue(que, data);
    printf(" %d sonuc \n", GetValueOfPrefix(que));
}

int main()
{

    program_start();

    return 0;
}
