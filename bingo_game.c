//
//  bingo_game.c
//  c_study
//
//  Created by Seora Lee on 19/03/2021.
//  Copyright © 2021 Seora Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
        int r, cnt;
        int k = 0;
    
        int nums[25] = {0, };
        int maplist[25];
        int map[5][5];
    
        srand(time(NULL));
    
        for(cnt = 0; cnt < 25; ){
    
            r = rand()%25+1;
            if(nums[r] == 1)
                continue;
    
            nums[r] = 1;
            maplist[cnt] = r;
            cnt++;
        }
    
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                map[i][j] = maplist[k];
                k++;
                printf("%d \t", map[i][j]);
            }
            printf("\n");
        }
    
        int rowflag, colflag, crossleflag, crossriflag = 0;
        int check = -1;
    
        while(check){
            int input;
            printf("\n-------체크할 숫자를 선택해주세요-------\n");
            scanf("%d", &input);
            if(input > 25 || input <= 0){
                printf("잘못 입력하셨습니다\n");
            }else{
                printf("\n--------------------------    \n");
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < 5; j++){
                        if(input == map[i][j]){
                            printf("0 \t");
                            map[i][j] = 0;
                        }else{
                            printf("%d \t", map[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n--------------------------    \n");
            }
    
            //방고 논리
            int i, j = 0;
            for(i=0 ; i<5 ;i++){
                rowflag = 0;
                colflag = 0;
    
                for(j = 0; j < 5; j++){
                    if(map[i][j] == 0){
                        rowflag++;
                    }
    
                    if(map[j][i] == 0){
                        colflag++;
                    }
    
                }
                // 가로세로체크
                if(rowflag == 5 || colflag == 5){
                    check++;
                }
                // 대각선 왼쪽에서 오른쪽
                if(map[i][i] == 0){
                    crossleflag++;
                }
                // 대각선 오른쪽에서 왼쪽
                if(map[5-i][i] == 0){
                    crossriflag++;
                }
    
            }
            //대각선 체크
            if(crossleflag == 5){
                check++;
            }
            if(crossriflag == 5){
                check++;
            }
    
    
        }
    
        printf("\n 빙고!!!! \n");
    
    
    return 0;
}
