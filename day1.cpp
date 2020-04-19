//code by Aying
/*
*题目描述：4人报数，如果数字是7的倍数或者含有7，跳过这个输字
*当4人报数的个数达到n个则停止，最后输出每个人跳过输字的个数
*输入20，输出2 1 1 0 
*分析：
*刚开始想多了，想找到规律
*最后还是直接模拟报数过程
*建立一个循环链表存报数，没用STL，好久不用，之前都忘了
*跳过的条件：7的倍数（mod即可），含有7（数转串用过的，模十再除十，依次获得个位数字）
*while(1)中的模拟过程，i是“无形中”的输字，id是用来确定当前甲乙丙丁中的一个人
*cnt是跳过的个数，cnt（报数中舍去的个数）+n（报数输出的个数）=i（总数）
*/

#include<cstdio>
#include<stdlib.h>
struct Cque{
    int cnt;
    struct Cque* next;
}CQ[4];//循环链表
//检测报数的输字是否含有7
int include7(int num){
    int a=0;
    while(num){//模十取余获得个位
        a = num % 10;
        if(a==7){
            return 1;
        }
        num/=10;
    }
    return 0;    
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<4;++i){
        CQ[i].cnt=0;
        if(i==3){
            CQ[i].next=&CQ[0];
            break;
        }
        CQ[i].next=&CQ[i+1];
    }
    int i=0,cnt=0,id=0;
    while(1){
        ++i;
        if(i%7==0||include7(i)){
            CQ[id].cnt++;
            ++cnt;//计数
        }
        ++id;
        id=id%4;
        if(cnt+n==i){
            break;
        }
    }
    for(int i=0;i<4;++i){
        printf("%d\n",CQ[i].cnt);
    }
    system("pause");
    return 0;
}