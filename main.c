#include <stdio.h>
#include <stdlib.h>

void create();
void display();

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
        printf("\n3.Exit from creating node .");
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
