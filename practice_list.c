//
//  practice_list.c
//  c_study
//
//  Created by Seora Lee on 28/05/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//


// 배열 리스트
#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data){
    arr[count] = data;
    count++;
}

void addFirst(int data){
    for(int i = count; i>= 1; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = data;
    count++;
}


void show(){
    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
}

void removeat(int index){
    for(int i = index; i < count; i++){
        arr[i] = arr[i + 1];
    }
    count--;
}

int main(void){
    addFirst(4);
    addFirst(5);
    addFirst(1);
    addBack(7);
    addBack(6);
    addBack(8);
    show();

    return 0;
}







// 연결 리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *next;
}Node;

Node *head;


void addFront(Node *root, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = root -> next;
    root -> next = node;
}

void removeFront(Node *root){
    Node *front = (Node*) malloc(sizeof(Node));
    root -> next = front -> next;
    free(front);
}

void freeAll(Node *root){
    Node *cur = head -> next;
    while (cur != NULL) {
        Node *next = cur -> next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root){
    Node *cur = head -> next;
    while (cur!= NULL) {
        printf("%d ", cur->data);
        cur = cur -> next;
    }
}

int main(void){
    head = (Node*) malloc(sizeof(Node));
    head -> next = NULL;
    addFront(head, 2);
    addFront(head, 4);
    addFront(head, 1);
    addFront(head, 8);
    addFront(head, 7);
    removeFront(head);
    showAll(head);
    freeAll(head);


    return 0;
}






// 양방향 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

void insert(int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    Node* cur;
    cur = head -> next;
    while(cur -> data > data && cur != tail){
        cur = cur -> next;
    }
    Node* prev = cur-> prev;
    prev -> next = node;
    node -> prev = prev;
    cur -> prev = node;
    node -> next = cur;
}

void removeFront(){
    Node* node = head -> next;
    head -> next = node -> next;
    Node* next = node -> next;
    next -> prev = head;
    free(node);
}


void show(){
    Node* cur = head -> next;
    while(cur!=tail){
        printf("%d ", cur->data);
        cur = cur-> next;
    }
}

int main(){
    
    head = (Node*) malloc(sizeof(Node));
    tail = (Node*) malloc(sizeof(Node));
    head -> next = tail;
    head -> prev = head;
    tail -> next = tail;
    tail -> prev = head;
    
    insert(2);
    insert(1);
    insert(4);
    insert(7);
    insert(9);
    removeFront();
    show();
    
    return 0;
}
