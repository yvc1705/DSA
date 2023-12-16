#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node* hashTable[SIZE] = { NULL };

int hashFunction(int key) {
    return key % SIZE; // Simple modulo hashing function
}

void insert(int value) {
    int index = hashFunction(value);

    // Creating a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If no element exists at the index, insert as the first element
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else { // If collision occurs, append to the existing list at the index
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(int value) {
    int index = hashFunction(value);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at index %d\n", value, index);
            return;
        }
        temp = temp->next;
    }

    printf("Element %d not found\n", value);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}
