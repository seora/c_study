//
//  practice_sorting.c
//  c_study
//
//  Created by Seora Lee on 04/06/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//


#include <stdio.h>
#include <limits.h>
#define SIZE 1000
#define MAX_VALUE 10001

int a[SIZE];
int num;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void quickSort(int start, int end){
    if(start >= end)    return;
    int key = start, i = start + 1, j = end, temp;      //start : 왼쪽부터, end : 오른쪽 끝부터
    while(i <= j){      // 작은값과 큰 값이 엇갈릴때까지 반복
        while(i <= end && a[i] <= a[key])   i++;
        while(j > start && a[j] >= a[key])  j--;
        if(i > j){
            swap(&a[key], &a[j]);
        }else
            swap(&a[i], &a[j]);

        // 퀵 정렬 과정 출력
        for(int i = 0; i < num; i++){
            printf("%d  ", a[i]);
        }
        printf("\n");
    }
    quickSort(start, j-1);
    quickSort(j+1, end);



}

int main(){


    // 1. 선택 정렬 (오름차순)
    int n, min, index;      //min : 한번 정렬할때마다 찾는 최소값
    printf("정렬할 숫자 갯수를 입력해주세요\n");
    scanf("%d", &n);
    printf("정렬할 숫자 배열을 입력해주세요\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        min = INT_MAX;
        for(int j = i; j < n; j++){
            if(min > a[j]){
                min = a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);
    }
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }



    // 2. 삽입 정렬 (오름차순)
    int n;
    printf("삽입 정렬할 숫자의 갯수를 입력 : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n - 1; i++){
        int key = i;        // 어디에 들어갈지
        while(key >= 0 && a[key] > a[key+1]){
            swap(&a[key], &a[key+1]);
            key--;
        }
    }

    for(int i = 0; i< n; i++){
        printf("%d  ", a[i]);
    }




    // 3. 퀵 정렬
    int n;
    printf("퀵 정렬할 숫자 갯수 입력 : ");
    scanf("%d", &n);
    printf("퀵 정렬할 숫자 배열을 입력해주세요\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    num = n;
    quickSort(0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }

    


    return 0;
}





