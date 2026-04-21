#include "node.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
    int num;
    Node *head;
    Node *last;
    Node *p;

    p->value = num;
    p->next = NULL;

    if (last->next){
        do{
            last->next = next->next;


        }
    }
}

typedef struct _list{
    Node* head;
}List;

void add(List *pList,int number)
{
    Node *p = (Node*)malloc(suzeof(Node));
    p->vlaue = number;
    p->next = NULL;

    Node *last = pList->head;

    if(last){

        do{
            last = last->next;
        }while(last);

        last->next = p;
    }else {
        pList->head = p;
    }
}

        

