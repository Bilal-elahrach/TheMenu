#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* new; //Declares a pointer to a Node struc that we name new

    new = (Node*)malloc(sizeof(Node));  //Creates memory on the heap for a Node struct

    if(!new){
        printf("\nNo memory allocation\n");
        exit(1);
    }

    new->data = data;
    new->next = NULL;

    return new;
}
void printList(Node* head){
    /* we are passing head as a single pointer 
    because we're not changing its address
    */
   Node* current;

   current = head;
   printf("\n");

   while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
   }
   printf("NULL\n\n");
}
void prependNode(Node** head){
    
}

void insertNodeEnd(Node** head, int data){
    Node* current = *head;
    Node* new;

    new = createNode(data);

    if(*head == NULL){
        *head = new;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new;

}

void revereList() {

}


int main () {
    int value;
    Node* head = NULL;

    printf("\n");
    while(value != 0){
        printf("Node Value (0 to exit): ");
        scanf("%d", &value);
        if(value == 0)
        break;
        insertNodeEnd(&head, value);
    }
    while(getchar() != '\n');
    printf("\nPress enter to continue...\n");
    getchar();

    printList(head);

    return 0;
}