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

int countNodes(Node* head){
    int count = 0;
    Node* current = head;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}

void prependNode(Node** head, Node* node){
    node->next = *head;
    *head = node;
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

void reverseList(Node** head) {
    int flag = 0;
    Node* current = *head;
    Node* precurrent = NULL;

    if(*head == NULL || (*head)->next == NULL){
        if(*head == NULL){
            printf("\nlinked list is empty\n");
            return;
        }
        printf("\nlinked list contains only 1 node, reverse is therefore the same\n");
        exit(1);
    }
    while(current != NULL){
        precurrent = current;
        current = current->next;
        if(flag == 0){
            precurrent->next = NULL;
            flag = 1;
            continue;
        }
        prependNode(head, precurrent);
    }
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
    reverseList(&head);

    printf("Reversed linked list:");
    printList(head);

    return 0;
}