#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

int searchValue1(Node* head, int val) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == val) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            if (prev != NULL) {
                printf("이전 노드 값: %d\n", prev->data);
            }
            else {
                printf("이전 노드가 없습니다. (맨 앞 노드)\n");
            }

            if (current->next != NULL) {
                printf("다음 노드 값: %d\n", current->next->data);
            }
            else {
                printf("다음 노드가 없습니다. (맨 뒤 노드)\n");
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", val);
}

int main() {
    Node* head = NULL;

    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    head = insertLast(head, 40);
    insertAfterValue(head, 20, 25);

    printList(head);

    int pos = -1;
    int val = 20;
    pos = searchValue1(head, val);
    if (pos != -1) {
        printf("%d의 위치는 %d번째\n", val, pos);
    }
    else {
        printf("%d을(를) 찾을 수 없습니다.\n", val);
    }

    searchValue2(head, val);

    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}