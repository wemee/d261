#include "stdio.h"

#define _Female_ 0
#define _Male_ 1

int main(){
    int n;
    unsigned int ary[2][2], i, previous, current;
    while (scanf("%d", &n) != EOF){
        if (n<=-1) break;
        n = (unsigned int)n;
        
        current=0;
        ary[current][_Female_] = 1;/* 初始母蜂 1 */
        ary[current][_Male_] = 0;/* 初始公蜂 0 */
        
        for (i=0; i<n; i++) {
            previous=current;
            ++current, current%=2;
            
            /* 初始母蜂不死，並且所有公蜂都生1隻母蜂 */
            ary[current][_Female_] = 1 + ary[previous][_Male_];
            
            /* 所有蜜蜂都生1隻公蜂 */
            ary[current][_Male_] = ary[previous][_Female_] + ary[previous][_Male_];
        }
        
        printf("%u %u\n", ary[current][_Male_], ary[current][_Female_]+ary[current][_Male_]);
    }
    return 0;
}
