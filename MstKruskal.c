/*************************************************************************
        > File Name: MstKruskal.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Thu 26 Dec 2013 10:05:32 PM CST
        题目：Kruskal算法寻找最小生成树
　　Kruskal算法总共选择n-1条边，所使用的贪婪准则是：从剩
　　下的边中选择一条不会产生回路的具有最小耗费的边加入已
　　选择的边的集合中。所选择的边若产生回路则不可能形成一
　　棵生成树。Kruskal算法分为e步，其中，e是网络中边的数
　　目。按耗费递增的顺醋来考虑着e条边，每次考虑一条边。
　　当考虑某条边时，若将其加入到已选的边集中会出现环路，
　　则将其抛弃，否则将它选入。
 ************************************************************************/

#include<stdio.h>
#include"map.h"

void
getplace2(AdjMultipleList *G,char *ch)
{
    int i,j,
        k = 0;
    
    while(1){
        printf("Please input the core-place that you want to search:\n");
        scanf("%s",ch);
        for(i = 0;i < G->vexnum;i++)
            if((j = strcmp(ch,G->vertex[i].name)) == 0){
                G->vertex[i].mark = 1;
                k = 1;
                break;
            }
        if(k == 1)
            break;
    }
    return;
}

int 
check_circle(ArcNode *arcarray[],ArcNode *ar,int I)
{
    int p = ar->pvex,
        b = ar->bvex,
        key1 = 0,
        key2 = 0,
        i,sum;
    for(i = 0;i < I;i++){
        if(arcarray[i]->pvex == p || arcarray[i]->bvex == p)
            key1 = 1;
        if(arcarray[i]->pvex == b || arcarray[i]->bvex == b)
            key2 = 1;
    }
    sum = key1 + key2;
    if(sum == 2)
        return -1;
    else
        return 1;
}

void
mst_kruskal(AdjMultipleList *G,ArcNode *arcarray[])
{
    ArcNode *ar;
    int i,j,no,cmp;

    for(i = 0;i < G->vexnum-1; i++){ //I need find G->vexnum-1 arcs
        cmp = 32767;
        for(j = 0;j < G->vexnum;j++){
            ar = G->vertex[j].head;
            no = G->vertex[j].No;
            while(ar != NULL){
                if(ar->pvex == no){
                    if(ar->distence < cmp &&
                            ar->mark == 0 &&
                            check_circle(arcarray,ar,i)){
                        arcarray[i] = ar;
                        cmp = ar->distence;
                        ar->mark = 1;
                    }
                    ar = ar->pvex_next;
                }
                else if(ar->bvex == no){
                    if(ar->distence < cmp &&
                            ar->mark == 0 &&
                            check_circle(arcarray,ar,i)){
                        arcarray[i] = ar;
                        cmp = ar->distence;
                        ar->mark = 1;
                    }
                    ar = ar->bvex_next;
                }
            }
        }
    }
    return;
}

void
show_kruskal(AdjMultipleList *G,ArcNode *arcarray[])
{
    int i,j,k;
    for(i = 0;i < G->vexnum-1;i++){
        j = arcarray[i]->pvex;
        k = arcarray[i]->bvex;
        printf("%s <------> %s : %d km\n",G->vertex[j].name,G->vertex[k].name,arcarray[i]->distence);
    }
    printf("\n");

    return;
}

void
mstkruskal(AdjMultipleList *G)
{
    char ch[20];
    ArcNode *arcarray[G->vexnum-1];

    getplace2(G,ch);
    mst_kruskal(G,arcarray);
    show_kruskal(G,arcarray);

    return;
}
