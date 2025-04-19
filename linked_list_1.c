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
    Node* newnode;

    newnode = (Node*)malloc(sizeof(Node));

    if(!newnode){
        printf("\nNo memory allocation\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertNode(Node** head, int data){
    /* why the Double pointer for head: 
    in order to change the address of head, we need to pass its address, 
    but since head is an address, then we're pasing the address of an address, 
    hence the double pointer
    */
    Node* newnode;

    newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void printList(Node* head){
    /* we are passing head as a single pointer 
    because we're not changing its address
    */
   Node* current;
   current = head;
   while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
   }
   printf("NULL\n");
}



int main () {
    Node* head = NULL; //Initialize empty list

    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);

    printList(head);

    return 0;
}