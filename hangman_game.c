//
//  hangman_game.c
//  c_study
//
//  Created by Seora Lee on 19/03/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
    
    char ch;
    char temp;
    
    srand(time(NULL));
    char dic[15][15] = { "world", "heroes", "voca", "source", "korea", "storm", "walk", "sound", "perfect", "school", "independent", "friendship", "master", "background", "generate" };
    
    int randNum = rand()%15;
    
    int len = strlen(dic[randNum]);     //단어의 길이
    
    char word[15] = "\0";           //랜덤으로 뽑힌 단어
    strcpy(word, dic[randNum]);     //word에 단어 할당
    
    char question[15] = "\0";
    for (int i = 0; i < len; i++){
        question[i] = 95;
    }
    
    printf("%s\n", word);
    printf("%d\n", len);
    
    printf("========== 행맨 게임 =========\n");
    printf("\t 맞출 단어는 %d 자리 입니다! \n", len);
    int cnt, check;
    cnt = len;
    
    //맞출 때까지 반복
    while(cnt){
        
        printf(" \n\n << 알파벳 하나를 입력해주세요 >>\n\n");
        
        //ch 하나만 입력받기 위해!
        ch = getchar();
        while(getchar() != '\n'){}
        check = 0;
        
        for(int j = 0; j <len; j++){
            if(ch!= word[j]){
                check++;
            }
        }
        
        for(int k = 0; k < len; k++){
            if(word[k] == ch && question[k] == 95){
                question[k] = ch;
                printf("%c ", question[k]);
                cnt--;
            }else{
                printf("%c ", question[k]);
            }
        }
        
        if(cnt == 0){
            printf("정답입니다!!\n");
            break;
        }
        
        if(check == len){
            printf("없는 알파벳입니다 :( \n");
        }
        
    }
    
    
    return 0;
}
