#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    struct ListNode *next;
    int data;
};

int ListLength(struct ListNode *head){
    struct ListNode *current = head;
    int count = 0;
    if(head == NULL){
        printf("List Empty");
        return 0 ;
    }
    while(current != NULL){
        count++;
        printf("%d:%p->%d\n",count, current, current->data);
        current = current ->next;
    }
    printf("==============\n");
    return count;
}

void InsertInLinkedList(struct ListNode **head, int data, int position) {
    int k= 1;
    struct ListNode *p, *q, *newNode;
    newNode = malloc(sizeof(struct ListNode));
    if(!newNode){
        printf("Memory Error");
        return;
    }
    newNode -> data = data;
    p=*head;
    if(position == 1){
        newNode->next = p;
        *head = newNode;
    }else{
        while(( p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL) {     //마지막 삽입
            q->next = newNode;
            newNode->next = NULL;
        }else{              // 중간 삽입
            q->next = newNode;
            newNode->next = p;
        }
    }
}

void DeleteNodeFromLinkedList( struct ListNode **head, int position){
    int k = 1;
    struct ListNode *p, *q, *last;
    if(*head == NULL){
        printf("List Empty");
        return;
    }
    p = *head;
    if(position == 1){
        p = *head;
        *head = p->next;
        free (p); return;
    }else{
        while((p != NULL) && (k < position)) {
            k++;
            if(k == position -1){
                last = p;
            }
            q=p; p = p->next;
        }
        if(p == NULL){
            printf("Position does not exist\n");
            last ->next = NULL;
            free(q);
        }else{
            q->next = p->next;
            free(p);
        }
    }
}

void DeleteLinkedList(struct ListNode **head){
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while(iterator){
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}

main() {
    struct ListNode *list1=NULL;
    printf("ADD Node\n");
    InsertInLinkedList(&list1,4,1);
    InsertInLinkedList(&list1,15,2);
    InsertInLinkedList(&list1,7,3);
    InsertInLinkedList(&list1,40,4);
    ListLength(list1);
    printf("DELETE Node\n");

    DeleteNodeFromLinkedList(&list1, 5);

    ListLength(list1);
    printf("DELETE ListNode\n");
    DeleteLinkedList(&list1);
    ListLength(list1);
}