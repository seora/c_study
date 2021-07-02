//
//  binary_search.c
//  c_study
//
//  Created by Seora Lee on 2021/06/28.
//  Copyright © 2021 Seora Lee. All rights reserved.
//

// 이진 탐색 트리 : 이진 탐색이 항상 동작하도록 구현하여 탐색 속도를 높임
// 부모노드가 왼쪽 자식보다 크고, 오른쪽 자식보다 작다

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data){
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
        return root;
    }
    else{
        if(root->data > data){
            root -> leftChild = insertNode(root -> leftChild, data);
        }
        else{
            root -> rightChild = insertNode(root -> rightChild, data);
        }
    }
    
    return root;
}

Node* searchNode(Node* root, int data){
    if(root == NULL) return NULL;
    if(root -> data == data) return root;
    else if(root -> data > data)
        return searchNode(root -> leftChild, data);
    else
        return searchNode(root -> rightChild, data);
}

//전위순회 방식으로 순회 : 자기 자신 -> 왼쪽 -> 오른쪽
void preOrder(Node* root){
    if(root == NULL)
        return;
    printf("%d ", root -> data);
    preOrder(root -> leftChild);
    preOrder(root -> rightChild);
}

Node* findMinNode(Node* root){
    Node* node = root;
    while(node -> leftChild != NULL){
        node = node -> leftChild;
    }
    return node;
}

Node* deleteNode(Node* root, int data){
    Node* node = NULL;
    if(root == NULL) return NULL;
    if(root -> data > data){
        root -> leftChild = deleteNode(root -> leftChild, data);
    }
    else if(root -> data < data){
        root -> rightChild = deleteNode(root -> rightChild, data);
    }
    else{
        if(root -> leftChild != NULL && root -> rightChild != NULL){
            node = findMinNode(root -> rightChild);
            root -> data = node -> data;
            root -> rightChild = deleteNode(root->rightChild, node -> data);
        }
        else{
            node = (root -> leftChild != NULL) ? root->leftChild : root -> rightChild;
            free(root);
            return node;
        }
    }
    return root;
}


int main(){
    Node* root = NULL;
    int n, num = 0;
    printf("이진탐색트리에 넣을 숫자 갯수를 입력해주세요\n");
    scanf("%d", &n);
    printf("이진탐색트리에 넣을 숫자들을 입력해주세요\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        root = insertNode(root, num);
    }
    printf("전위순회로 실행할 트리 구조입니다\n");
    preOrder(root);
    
   
    int k = 0;
    while(k != 3){
        printf("\n 다음 트리에 어떤 작업을 하시겠습니까? 1) 삽입 2) 제거 3) 종료 \n");
        scanf("%d", &k);
        if(k == 1){
            printf("넣을 숫자를 입력해주세요\n");
            scanf("%d", &num);
            root = insertNode(root, num);
            
        }else if(k == 2){
            int dNum;
            printf("이진탐색트리에서 삭제할 숫자를 입력해주세요\n");
            printf("삭제하지 않을 경우 0을 입력하세요\n");
            scanf("%d", &dNum);
            if(dNum != 0){
                root = deleteNode(root, dNum);
            }
        }else
            break;
        
        printf("전위순회로 실행할 트리 구조입니다\n");
        preOrder(root);
    }
    
    
    
    
    
    
    
    return 0;
}
