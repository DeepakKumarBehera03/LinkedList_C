#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insertAtBeginning();
void insertAtEnd();
void insertAtAny();
struct node{
    int data;
    struct node *next;
};
struct  node *start;
int main() {
    int choice;
    while (1){
        printf("\n1.Create() .");
        printf("\n2.display() .");
        printf("\n3.insert at beginning .");
        printf("\n4.insert at any position .");
        printf("\n5.insert at end .");
        printf("\n6.Exit from creating node .");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertAtBeginning();
                break;
            case 4:
                insertAtAny();
                break;
            case 5:
                insertAtEnd();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input .");
                break;
        }
    }
}

void create(){
    struct node *temp, *ptr;
    temp = (struct node *) malloc(sizeof(struct node));
    if (temp == NULL){
        printf("Underflow");
        return;
    }
    printf("Enter the value for node : ");
    scanf("%d", &temp->data);
    if (start == NULL){
        start = temp;
    }
    else{
        ptr = start;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(){
    struct node *ptr;
    ptr = start;
    while (ptr != NULL){
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}
void insertAtBeginning(){
    struct node *temp, *ptr;
    temp = (struct node *) malloc(sizeof(struct node));
    if (temp == NULL){
        printf("UNDERFLOW");
        return;
    }
    printf("Enter the value for new node : ");
    scanf("%d", &temp->data);
    if (start == NULL){
        temp->next = NULL;
        start = temp;
    }
    else{
        temp->next = start;
        start = temp;
    }
}
void insertAtEnd(){
    struct node *temp, *ptr;
    temp = (struct node *) malloc(sizeof(struct node));
    if (temp == NULL){
        printf("UNDERFLOW");
        return;
    }
    printf("Enter the value for new node : ");
    scanf("%d", &temp->data);
    ptr = start;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void insertAtAny(){
    struct node *newNode, *ptr, *preptr;
    newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("UNDERFLOW");
        return;
    }
    printf("Enter the value for new node : ");
    scanf("%d", &newNode->data);
    int data;
    printf("Enter the data at which you want to insert the value : ");
    scanf("%d", &data);
    ptr = start;
    while (ptr->data != data){
        preptr = ptr;
        ptr = ptr->next;
    }
    newNode->next = preptr->next;
    preptr->next = newNode;
}
