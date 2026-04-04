#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float array_average_max(int num[],int len,int no){
    if(len<=no){
        printf("数组数少于规定子数组数！！！\n");
        float sum = 0;
        for (int i = 0; i < len;i++){
            sum += num[i];
        }
        return (sum / len);
    }
    else{
        float temp = 0;
        float sum = 0;
        for (int i = 0; i < no; i++)
        {
            sum += num[i];
        }

        for (int flag = no; flag < len;flag++){
            if(temp<(sum/no)){
                temp = sum / no;
                printf("\n%d %d %d", num[flag - no], num[flag - no + 1], num[flag - no + 2]);
            }
            sum += num[flag];
            sum -= num[flag - no];
        }
        return temp;
    }
    return 0;
}

int main(){
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数
    
    srand(time(NULL));
    int num[10],no=3;
    int len = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < 10;i++){
        num[i] = rand() % 100;
        printf("%d\t", num[i]);
    }
    printf("\n长度为 %d 子数组最大均值：%.2f\n",no, array_average_max(num, len, no));

    clock_t end = clock();
    printf("算法运行了 %d ms", end - start);
    return 0;
}