#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *directory;
    struct Node *next;
} Node;

Node *buildPathLinkedList() {
    const char *path = getenv("PATH");
    if (path == NULL) {
        return NULL;
    }

    Node *head = NULL;
    Node *current = NULL;

    char *pathCopy = strdup(path);
    if (pathCopy == NULL) {
        return NULL;
    }

    char *directory = strtok(pathCopy, ":");
    while (directory != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            free(pathCopy);
            return NULL;
        }

        newNode->directory = strdup(directory);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }

        directory = strtok(NULL, ":");
    }

    free(pathCopy);
    return head;
}

void printPathLinkedList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }
}

void freePathLinkedList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->directory);
        free(temp);
    }
}

int main(void) {
    printf("Linked List of PATH directories:\n");
    Node *pathList = buildPathLinkedList();
    printPathLinkedList(pathList);
    freePathLinkedList(pathList);

    return 0;
}
