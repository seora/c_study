//
//  practice_graph.c
//  c_study
//
//  Created by Seora Lee on 2021/06/25.
//  Copyright © 2021 Seora Lee. All rights reserved.
//


// 1. 2차원 배열을 사용한 무방향 비가중치 그래프와 인접 행렬

#include <stdio.h>

int a[1001][1001];
int n, m;

int main(){
    printf("node의 갯수와 edge의 갯수를 입력해주세요\n");
    scanf("%d %d", &n, &m);

    printf("edge가 연결되어있는 node 2개를 입력해주세요\n ");
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;            //방향성이 없기 때문에 서로 연결할 수 있도록
        a[y][x] = 1;
    }

    printf("\n");

    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}



// 2. 방향 가중치 그래프와 인접 리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int distance;
    struct Node *next;
} Node;         //연결 리스트 구조체

void addFront(Node *root, int index, int distance){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> index = index;
    node -> distance = distance;
    node -> next = root -> next;
    root -> next = node;
}           // 방향대로 앞에 계속해서 노드들을 추가해주는 방식

void showAll(Node *root){
    Node *cur = root -> next;
    while(cur != NULL){
        //어떤 노드로 연결되어 있는지, 어떤 거리인지
        printf("%d(거리 : %d)  ", cur -> index, cur -> distance);
        cur  = cur -> next;
    }
}

int main(){
    int n, m;
    printf("node의 갯수와 edge의 갯수를 입력해주세요\n");
    scanf("%d %d", &n, &m);
    Node **a = (Node**)malloc(sizeof(Node*)*(n+1));     //node의 갯수만큼 연결리스트가 필요함
    // node 의 갯수 + 1 만큼 동적할당 -> why? 각 인덱스가 1부터 시작한다
    
    
    //각 node를 동적할당 초기화
    for(int i = 1; i <= n; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i] -> next = NULL;
    }
    
    //각 edge의 정보를 사용자로부터 받아옴
    printf("출발 노드, 도착 노드, 가중치를 입력해주세요\n");
    for(int i = 0; i < m; i++){
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);
        addFront(a[x], y, distance);
    }
    
    for(int i = 1; i<= n; i++){
        printf("원소 [%d] : ", i);
        showAll(a[i]);
        printf("\n");
    }
    
    
    return 0;
}
