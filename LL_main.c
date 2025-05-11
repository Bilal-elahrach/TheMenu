#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "LL_header.h"


int main () {
    Node* head = NULL;
    Node* tail = NULL;
    int value;
    int count;

    do{
        printf("Enter Value of the new Node or 0 to display the result: ");
        scanf("%d", &value);
        if(value != 0){
            insertNode(&head, value);
            insertNodeEnd(&tail, value);
            continue;
        };
        break;
    }while(1);

    if(value == 0){
        printf("\nPrepend: ");
        printList(head);
        
        printf("Append: ");
        printList(tail);

    }

    printf("\nNow, we are going to delete a node from Prepend.\n\nNode to delete: ");
    scanf("%d", &value);
    printf("Original Prepend: ");
    printList(head);
    deleteNode(&head, value);
    printf("\nNew Prepend: ");
    printList(head);

    printf("\nNext, we count the nodes in Prepend.\nThat would be: %d Nodes", count = countNodes(head));
    
    return 0;
}