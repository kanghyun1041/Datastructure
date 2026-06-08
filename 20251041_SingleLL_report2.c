#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[50];
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
}

Node* insertLast(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
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

void searchContact(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s의 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("%s을(를) 찾을 수 없습니다.\n", name);
}

Node* deleteContact(Node* head, char* name) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            free(current);
            printf("%s의 연락처가 삭제되었습니다.\n", name);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("%s을(를) 찾을 수 없습니다.\n", name);
    return head;
}

int main() {
    Node* head = NULL;
    int choice;
    char name[50];
    char phone[50];

    while (1) {
        printf("\n--- 전화번호부 관리 시스템 ---\n");
        printf("1. 새로운 연락처 추가\n");
        printf("2. 연락처 검색\n");
        printf("3. 연락처 삭제\n");
        printf("4. 전체 전화번호부 출력\n");
        printf("5. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 5) {
            Node* current = head;
            while (current != NULL) {
                Node* nextNode = current->next;
                free(current);
                current = nextNode;
            }
            break;
        }

        switch (choice) {
        case 1:
            printf("이름 입력: ");
            scanf("%s", name);
            printf("전화번호 입력: ");
            scanf("%s", phone);
            head = insertLast(head, name, phone);
            break;

        case 2:
            printf("검색할 이름 입력: ");
            scanf("%s", name);
            searchContact(head, name);
            break;

        case 3:
            printf("삭제할 이름 입력: ");
            scanf("%s", name);
            head = deleteContact(head, name);
            break;

        case 4:
            printList(head);
            break;

        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }

    return 0;
}