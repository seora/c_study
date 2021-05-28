//
//  practice_Stack.c
//  c_study
//
//  Created by Seora Lee on 28/05/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//



// 배열을 이용한 스택 구현

#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data){
    if(top == SIZE -1){
        printf("스택 오버플로우가 발생");
        return;
    }
    stack[++top] = data;
}


int pop(){
    if(top == -1){
        printf("스택 언더플로우가 발생!");
        return -INF;
    }
    return stack[top--];
}

void show(){
    printf("---- stack의 최상단 ----\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
    printf("---- stack의 최하단 ----\n");
}


int main(){

    push(6);
    push(8);
    push(3);
    pop();
    push(4);
    push(1);
    pop();
    push(5);
    show();

    return 0;
}




// 연결 리스트를 이용한 스택 구현

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
}Node;

typedef struct{
    Node *top;
} Stack;


void push(Stack *stack, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = stack -> top;
    stack -> top = node;
}

int pop(Stack *stack){
    if(stack -> top == NULL){
        printf("스택 언더플로우 발생!!");
        return -INF;
    }
    Node *node = stack -> top;
    int data = node -> data;
    stack -> top = node -> next;
    free(node);
    return data;
}

void show(Stack *stack){
    Node *cur = stack -> top;
    printf("---- stack 의 최상단 ----\n");
    while(cur != NULL){
        printf("%d \n", cur -> data);
        cur = cur->next;
    }
    printf("---- stack 의 최하단 ----\n");
}


int main(){

    Stack stack;
    stack.top = NULL;

    push(&stack, 7);
    push(&stack, 5);
    push(&stack, 3);
    pop(&stack);
    push(&stack, 2);
    push(&stack, 8);
    pop(&stack);

    show(&stack);

    return 0;
}






// 스택을 활용한 계산기 만들기
// 수식을 후위 표기법으로 변환
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct Node{
    char data[100];
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
} Stack;

void push(Stack *stack, char *data){
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node -> data, data);
    node -> next = stack -> top;
    stack -> top = node;
}

char* getTop(Stack *stack){
    Node *top = stack -> top;
    return top -> data;
}

char* pop(Stack *stack){
    if(stack -> top == NULL){
        printf("stack 언더플로우 발생!\n");
        return -INF;
    }
    Node *node = stack -> top;
    char* data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data);
    stack -> top = node -> next;
    free(node);
    
    return data;
}

int getPriority(char *i){
    //클수록 우선순위 높음
    if(!strcmp(i, "(")) return 0;
    if(!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if(!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3;
}

char* transition(Stack* stack, char** s, int size) {
    char res[1000] = "";             // 후위표기법으로 바뀐 문자열이 담길 공간
    for (int i = 0; i < size; i++) {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
            while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
                strcat(res, pop(stack)); strcat(res, " "); // 문자열 붙이기
            }
            push(stack, s[i]);
        }
        else if (!strcmp(s[i], "(")) push(stack, s[i]);
        else if (!strcmp(s[i], ")")) {
            while (strcmp(getTop(stack), "(")) {
                strcat(res, pop(stack)); strcat(res, " ");
            }
            pop(stack);
        }
        else { strcat(res, s[i]); strcat(res, " "); }
    }
    while (stack->top != NULL) {
        strcat(res, pop(stack)); strcat(res, " ");
    }
    return res;
}


void calculate(Stack* stack, char **s, int size){
    int x, y, z;
    for(int i = 0; i < size; i++){
        if(!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){
            x = atoi(pop(stack));           // atoi : char -> int
            y = atoi(pop(stack));
            if(!strcmp(s[i], "+")) z = y + x;
            if(!strcmp(s[i], "-")) z = y - x;
            if(!strcmp(s[i], "*")) z = y * x;
            if(!strcmp(s[i], "/")) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z);       // 계산된 z를 문자형태로 다시 바꿔서 stack에 넣음
            push(stack, buffer);
        }else{
            push(stack, s[i]);
        }
    }
    printf("%s ", pop(stack));
}


int main(){
    
    Stack stack;
    stack.top = NULL;
    char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 + ( 2 + 3 ) * 10";
    
    printf("입력 문자열 : %s\n\n", a);
    
    int size = 1;
    for (int i = 0; i < strlen(a);i++) {
        if (a[i] == ' ') size++; // 공백을 만날 때 마다 size 1씩 추가, 즉 문자열의 개수 세기
    }
    
    //띄어쓰기로 문자열 자른 후, 각 문자열을 배열 형태로 input 에 넣기

    char* ptr = strtok(a, " "); // a 공백을 기준으로 문자열을 하나의 토큰으로 변환
    char** input = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        input[i] = (char*)malloc(sizeof(char) * 100);
    }

    for (int i = 0; i < size; i++) {
        strcpy(input[i], ptr);
        ptr = strtok(NULL, " ");
    }                           // 여기까지 각각의 문자들이 input에 문자열 형태로 변환
    
    
    //input에 들어간 문자열 배열을 후위 표기법으로 다시 배열에 넣기

    char b[1000] = "";
    strcpy(b, transition(&stack, input, size));  // 후위 표기법으로 변환
    printf("후위 표기법 : %s\n\n", b);

    size = 1;
    for (int i = 0; i < strlen(b) - 1; i++) { // 후위 표기법의 마지막은 항상 공백이 있어 제거(-1)
        if (b[i] == ' ') size++;
    }
    
    // 후위표기법으로 정리된 배열을 input에 다시 넣기

    char* ptr2 = strtok(b, " ");
    for (int i = 0; i < size; i++) {
        strcpy(input[i], ptr2);
        ptr2 = strtok(NULL, " ");
    }
    calculate(&stack, input, size);

    
    return 0;
}
