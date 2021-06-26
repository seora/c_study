//
//  practice_BFS.c
//  c_study
//
//  Created by Seora Lee on 2021/06/26.
//  Copyright © 2021 Seora Lee. All rights reserved.
//


// 너비 우선 탐색 : 너비를 우선으로 탐색 수행하는 알고리즘 (Queue 사용)

// 탐색 시작 노드를 큐에 삽입, 인접 노드 중 방문하지 않은 노드를 모두 큐에 삽입 후, 방문 처리, 탐색 노드 빼기
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

//연결리스트 정의
typedef struct {
    int index;
    struct Node *next;
} Node;

// Queue 정의
typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node **a;
int n, m, c[MAX_SIZE];      //정점, 간선, 방문 정보

void addFront(Node *root, int index){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> index = index;
    node -> next = root -> next;
    root -> next = node;
}

void queuePush(Queue *queue, int index){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> index = index;
    node -> next = NULL;
    
    if(queue -> count == 0){        //큐가 비어있다면 front에 노드 넣기
        queue -> front = node;
    }
    else{
        queue -> rear -> next = node;       //큐의 꼬리 부분에 해당 노드 넣기
    }
    queue -> rear = node;
    queue -> count++;
}

int queuePop(Queue *queue){
    if(queue -> count == 0){
        printf("큐 언더플로우 발생!\n");
        return -INF;
    }
    Node *node = queue -> front;
    int index = node -> index;
    queue -> front = node -> next;
    free(node);
    queue -> count--;
    
    return index;
}

void bfs(int start){
    Queue q;
    q.front = q.rear = NULL;        //큐 초기화
    q.count = 0;
    
    queuePush(&q, start);
    c[start] = 1;
    
    while(q.count != 0){
        int x = queuePop(&q);
        printf("%d ", x);
        Node *cur = a[x] -> next;
        while(cur != NULL){
            int next = cur -> index;
            if(!c[next]){
                queuePush(&q, next);
                c[next] = 1;
            }
            cur = cur -> next;
        }
    }
}

int main(){
    printf("너비 우선 탐색 알고리즘입니다!!\n");
    printf("정점과 간선 갯수를 입력해주세요\n");
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*)*(MAX_SIZE));
    for(int i = 1; i <= n; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i] -> next = NULL;
    }
    
    printf("연결된 노드 두개를 입력해주세요 ex)1 3  \n");
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    
    bfs(1);
    
    return 0;
}



