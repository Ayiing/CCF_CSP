/**
 * int 4字节32位范围 -2147483648~2147483647
 * 
 * 题目描述：给n个（x，y）坐标表示垃圾，x、y可以为正为负
 * 满足以下条件（x，y）可建立垃圾站：
 *      1.（x，y）处有垃圾
 *      2.（x，y）上下左右都有垃圾
 * （x，y）建立垃圾站之后，评价垃圾站的分数：
 * 分数=4个斜对角位置有垃圾的个数
 * 
 * 分析：
 * 晕了，想了十分钟之后就去看题解了，
 * 第一反应是这么想的：
 *      1.建立一个二维数组（或者两个，一个记录是否能成为垃圾站，一个记录对角线上垃圾的个数）
 *      2.输入（x，y）即对（x，y）进行分析，是否能成为垃圾站，以及做一些更新维护的操作
 *      3.循环跳到步骤2
 * 想岔了，本来是想一边输入一边更新表，
 * 但如果这么做的话，至少要解决输入坐标可正可负的问题，因为是未输入完，也不能根据最小的输入坐标值来偏移，
 * 然后越想越岔
 * 
 * 不如直接用结构体存坐标，也不需要做到图上和二维数组的对应，
 * 直接遍历验证条件即可（根据坐标的上下左右、斜对角的关系）
 * 难得一见的是，也不需要用long int，int的范围刚好cover住
 * 下面复杂度是n**2，
 * 
 * ps：下次要先想好 图坐标和二维数组对应起来有什么好处，实现的难度，
 * 像这次，如果能对应起来，就不需要内层循环的遍历，直接根据输入的（x，y）查看上下左右
 * 但往往实现起来，没那么直接，就像这道题，顺着这个思路反而变得复杂。
 * */



#include<cstdio>
#include<stdlib.h>
struct node{
    int x,y;
}a[1000];
int main()
{
    int n;
    scanf("%d",&n);
    int score[5]={0};
    for(int i=0;i<n;++i){
        scanf("%d%d",&(a[i].x),&(a[i].y));
    }
    for(int i=0;i<n;++i){
        int x=a[i].x,y=a[i].y;
        int t=0,t1=0;//下面该点搜索是否满足条件1-2
        for(int j=0;j<n;++j){
            if(i==j){
                continue;
            }
            int x1=a[j].x,y1=a[j].y;

            if(x-1==x1&&y==y1){
                ++t;
            }
            else if(x+1==x1&&y==y1){
                ++t;
            }
            else if(x==x1&&y-1==y1){
                ++t;
            }
            else if(x==x1&&y+1==y1){
                ++t;
            }

            if(x-1==x1&&y-1==y1){
                ++t1;
            }
            else if(x+1==x1&&y+1==y1){
                ++t1;
            }
            else if(x-1==x1&&y+1==y1){
                ++t1;
            }
            else if(x+1==x1&&y-1==y1){
                ++t1;
            }

        }
        if(t==4){
            score[t1]+=1;
        }
    }
    for(int i=0;i<5;++i){
        printf("%d\n",score[i]);
    }
    system("pause");
    return 0;
}