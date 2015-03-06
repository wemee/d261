#include "stdio.h"

int main(){
    int n;
    unsigned int ary[2][2], i, previous, current;
    while (scanf("%d", &n) != EOF){
        if (n<=-1) break;
        n = (unsigned int)n;
        
        current=0;
        ary[current][0] = 1; /* 初始母峰 1 */
        ary[current][1] = 0; /* 初始公峰 0 */
        for (i=0; i<n; i++) {
            previous=current;
            current++, current%=2;
            
            ary[current][0] = 1/* 初始母峰不死 */ + ary[previous][1]/* 所有公峰生1隻母蜂 */;
            ary[current][1] = ary[previous][0] + ary[previous][1];/* 所有蜜峰都生1隻公蜂 */
        }
        printf("%u %u\n", ary[current][1], ary[current][0]+ary[current][1]);
    }
    return 0;
}
