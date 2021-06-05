//
//  practice_sorting2.c
//  c_study
//
//  Created by Seora Lee on 04/06/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//

// 1. 계수 정렬

#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];       // 배열의 메모리값을 크게 잡는 대신 빠르게 동작


int main(){

    printf("계수 정렬할 숫자 갯수 : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        a[m]++;
    }
    for(int i = 0; i < MAX_VALUE; i++){
        while(a[i] != 0){
            printf("%d  ", i);
            a[i]--;
        }
    }

    return 0;
}



// 2. 기수 정렬

#include <stdio.h>
#define MAX 10000

void radixSort(int *a, int n){
    int result[MAX], maxValue = 0;
    int exp = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > maxValue){
            maxValue = a[i];        //가장 큰 값의 자릿수를 구해야함
        }
    }
    
    while(maxValue / exp > 0){      //1의 자리부터 계산
        int bucket[10] = {0};
        for(int i= 0; i < n; i++){
            bucket[ a[i]/exp % 10 ]++;      //각 자릿수에 있는 숫자가 있으면 bucket 배열에 담기
        }
        for(int i = 1; i < 10; i++){
            bucket[i] += bucket[i-1];       //누적 계산
        }
        for(int i = n - 1; i >= 0; i--){  //같은 자릿수끼리 순서 유지
            int digit = a[i] / exp % 10;
            result[--bucket[digit]] = a[i];
        }
        for(int i = 0; i < n; i++){
            a[i] = result[i];      //배열 갱신
        }
        exp *= 10;
    }
}


int main(){
    
    int a[MAX];
    int n;
    printf("기수 정렬할 숫자 갯수 : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    radixSort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
}
