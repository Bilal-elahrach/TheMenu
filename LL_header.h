#ifndef LL_DECLARATION_H
#define LL_DECLARATION_H

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data);
void insertNode(Node** head, int data);
void printList(Node* head);
void insertNodeEnd(Node** head, int data);
void deleteNode(Node** head, int data);
int countNodes(Node* head);
#endif