//
//  main.c
//  ProductMix
//
//  Created by iNextHikky on 2019/11/06.
//  Copyright © 2019 All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 16
#define BN 4
#define TIME_MAX 37

char chk_ABCD(unsigned int);

int main(int argc, const char * argv[]) {
    unsigned int *chk;
    unsigned int chk_flg;
    unsigned int mask;
    
    int benefitResult = 0;
    int timeResult = 0;
    unsigned char *chkResult;
    chkResult = malloc(sizeof(unsigned char) * BN);
    chk = malloc(sizeof(unsigned int) * BN);
    
    for(chk_flg = 0b0000; chk_flg < N; chk_flg++){
        int timeSum = 0;
        int benefitSum = 0;
        mask = 0b0001;
        for(int i = 0; i < BN; i++){
            chk[i] = chk_flg & mask;
            mask <<= 1;
        }
        for(int i = 0; i < BN; i++){
            printf("%c", chk_ABCD(chk[i]));
            switch (chk_ABCD(chk[i])) {
                case 'A':
                    timeSum += 5;
                    benefitSum += 3;
                    break;
                case 'B':
                    timeSum += 17;
                    benefitSum += 12;
                    break;
                case 'C':
                    timeSum += 20;
                    benefitSum += 20;
                    break;
                case 'D':
                    timeSum += 15;
                    benefitSum += 10;
                    break;
                default:
                    break;
            }
        }
        if (timeSum > TIME_MAX) {
            printf(":制限時間超過");
        }else{
            printf(":収益%2d（%2d時間）", benefitSum, timeSum);
            if(benefitResult < benefitSum){
                benefitResult = benefitSum;
                timeResult = timeSum;
                for (int i = 0; i < BN; i++) {
                    chkResult[i] = chk_ABCD(chk[i]);
                }
            }
        }
        printf("\n");
    }
    puts("↓");
    puts("結果---------------");
    printf("%s:最大収益 %d（%d時間）\n", chkResult, benefitResult, timeResult);
    return 0;
}

char chk_ABCD(unsigned int v){
    switch (v) {
        case 0b0001:
            return 'A';
        case 0b0010:
            return 'B';
        case 0b0100:
            return 'C';
        case 0b1000:
            return 'D';
        default:
            return ' ';
    }
}
