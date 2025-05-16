#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Stack_header.h"


Node* createNode(int data) {
    Node* node;

    node = (Node*)malloc(sizeof(Node)); //allocates memory on the heap for the new node of type Node

    if(!node){
        printf("\nNo memory allocation");
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void push(Node** top, int data){
    Node* node = createNode(data);

    node->next = *top;
    *top = node;
    return;
}

void printStack(Node* top){
    
    printf("\nTop -> ");
    if(top == NULL){
        printf("NULL\n\n");
        return;
    }
    while(top != NULL){
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n\n");
    return;
}

void pop(Node** top){
    Node* temp;

    if (*top == NULL){
        printf("\nEmpty Stack\n");
        return;
    }

    temp = *top;
    *top = temp->next;
    free(temp);
    return;
}



int main() {
    Node* top = NULL;
    int data;

    printf("\t##### Stacking Stage #####");
    while(1){
        printf("\nNew node (or 0 to exit): ");
        scanf("%d", &data);
        if(data == 0)
            break;
        push(&top, data);
    }

    printStack(top);

    printf("\t##### Popping Stage #####");
    do{
        printf("\nPress 1 to pop (0 to exit)");
        scanf("%d", &data);
        if(data == 0){
            break;
        }
        pop(&top);
        printStack(top);
    }while(1);

    printf("\nComeagain");
    

    return 0;
}