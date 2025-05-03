#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "linked_list_1.h"



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

void insertNode(Node** head, int data){
    /* why the Double pointer for head: 
    in order to change the address of head, we need to pass its address, 
    but since head is an address, then we're passing the address of an address, 
    hence the double pointer
    */
    Node* new;

    new = createNode(data);
    new->next = *head; //Make new->next point to whatever *head is pointing to
    *head = new; //Make *head point to new
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

void deleteNode(Node** head, int data){
    Node* current;
    Node* precurrent;

    current = *head;
    precurrent = NULL;

    if(*head == NULL){
        printf("\nLinked List is empty\n");
        return;
    }
    while(current != NULL && current->data != data){
        precurrent = current;
        current = current ->next;
    }
    if(current == NULL){
        printf("\n%d Node not found\n", data);
        return;
    }
    if(precurrent == NULL){
        *head = current->next;
    }
    else{
        precurrent->next = current->next;
    }
    free(current);
}

int countNodes(Node* head){
    int count = 0;
    Node* current = head;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}
