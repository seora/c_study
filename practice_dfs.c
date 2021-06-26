//
//  practice_DFS.c
//  c_study
//
//  Created by Seora Lee on 2021/06/25.
//  Copyright © 2021 Seora Lee. All rights reserved.
//


// 깊이 우선 탐색 : 깊은 것을 우선적으로 탐색하는 알고리즘 (stack 사용)
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

Node **a;
int n, m;   // node, edge
int c[MAX_SIZE];    // 현재 방문을 했는지 체크


void addFront(Node *root, int index){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> index = index;
    node -> next = root -> next;
    root -> next = node;
}       //스택 연결 리스트 삽입 함수


void dfs(int x){
    if(c[x]) return;        //현재 해당 노드를 방문할 수 있다면 바로 return
    c[x] = 1;               //해당 노드 방문처리
    printf("%d ", x);
    Node *cur = a[x] -> next;
    while( cur!= NULL){
        int next = cur -> index;
        dfs(next);
        cur = cur -> next;
    }
}


int main(){
    printf("정점과 간선 갯수를 입력해주세요\n");
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE)); //정점의 갯수만큼 할당
    
    // 각 노드 초기화
    for(int i = 1; i <= n; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i] -> next = NULL;
    }
    
    // 연결된 각 노드 (x, y를 서로 연결)
    printf("연결된 각 노드를 입력해주세요\n");
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    
    dfs(1);     // 첫 방문 순서
    
    return 0;
}

