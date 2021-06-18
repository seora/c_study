//
//  practice_search.c
//  c_study
//
//  Created by Seora Lee on 2021/06/18.
//  Copyright © 2021 Seora Lee. All rights reserved.
//



//Sequential Search (순차 탐색) : 특정 원소를 찾기 위해 원소를 순차적으로 앞에서부터 하나씩 탐색

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000

char **array;       // 2차원 배열
int founded;        // 특정 원소를 발견했는지 check

int main(){
    int n;
    char *word;
    word = malloc(sizeof(char) * LENGTH);
    scanf("%d %s", &n, word);
    array = (char**)malloc(sizeof(char*)*n);

    for(int i = 0; i <n; i++){
        array[i] = malloc(sizeof(char) * LENGTH);
        scanf("%s", array[i]);
    }

    for(int i = 0; i < n; i++){
        if(!strcmp(array[i], word)){
            printf("%d번째 원소입니다\n", i+1);
            founded = 1;
        }
    }

    if(!founded)
        printf("원소를 찾을 수 없습니다!\n");

    system("pause");
    return 0;

}




// Binary Search (이진 탐색) : 데이터가 이미 정렬되어 있는 상황에서 탐색 범위를 절반씩 좁혀가며 데이터 탐색

#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;



int search(int start, int end, int target){
    if(start > end) return -9999;
    int mid = (start + end) / 2;
    if(a[mid] == target)
        return mid;
    else if(a[mid] > target)
        return search(start, mid-1, target);
    else
        return search(mid+1, end, target);
}


int main(void){
    int n, target;
    scanf("%d %d", &n, &target);    //n개의 데이터 중, target 찾겠다
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);         //입력시 원소 크기 순서대로 입력
    }
    
    int result = search(0, n-1, target);
    
    if(result != -9999){
        printf("%d 번째 원소입니다\n", result + 1);
    }else
        printf("원소를 찾을 수 없습니다\n");
    
}
