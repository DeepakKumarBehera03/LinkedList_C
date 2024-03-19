#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insertAtBeginning();
void insertAtEnd();
void insertAtAny();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromAny();
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
        printf("\n6.delete from the beginning .");
        printf("\n7.delete from the end .");
        printf("\n8.delete from any position .");
        printf("\n9.Exit from creating node .");
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
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                deleteFromAny();
                break;
            case 9:
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
    printf("\nEnter the value for node : ");
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
void insertAtAny() {
    struct node *newNode, *ptr, *preptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("MEMORY ALLOCATION FAILED");
        exit(1);
    }
    printf("Enter the value for new node : ");
    scanf("%d", &newNode->data);
    int data;
    printf("Enter the data at which you want to insert the value : ");
    scanf("%d", &data);
    ptr = start;
    preptr = NULL;
    while (ptr != NULL && ptr->data != data) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value not found in the list\n");
        free(newNode);
        return;
    }
    newNode->next = ptr;
    if (preptr == NULL)
        start = newNode;
    else
        preptr->next = newNode;
}


void deleteFromBeginning(){
    if (start == NULL){
        printf("UNDERFLOW");
        return;
    }
    struct node *temp;
    temp = start;
    start = start->next;
    free(temp);
}
void deleteFromEnd(){
    struct node *ptr, *preptr;
    if (start == NULL){
        printf("UNDERFLOW");
        return;
    }
    ptr = start;
    while (ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}
void deleteFromAny(){
    struct node *ptr, *preptr;
    if (start == NULL){
        printf("UNDERFLOW");
        return;
    }
    printf("Enter the value which u want to delete : ");
    int value;
    scanf("%d", &value);
    ptr = start;
    while (ptr->data != value){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}