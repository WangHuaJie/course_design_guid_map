/*************************************************************************
        > File Name: Show.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Tue 10 Dec 2013 08:03:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include"map.h"


void
vexallarc(AdjMultipleList *G,int i)
{
    ArcNode *ar;
    VertexNode *vex;
    int no;

    vex = &G->vertex[i];
    ar = vex->head;
    no = vex->No;
    while(ar != NULL)
    {
        printf("2\n");
        if(ar->pvex == no)
        {
            printf("2.1\n");
            printf("%s<---->%s:",G->vertex[no].name,G->vertex[ar->bvex].name);
            ar = ar->pvex_next;
        }   
        else if(ar->bvex == no)
        {
            printf("2.2\n");
            printf("%s<---->%s:",G->vertex[no].name,G->vertex[ar->pvex].name);
            ar = ar->bvex_next;
        }
    }

    return;
}

void
Show(AdjMultipleList *G)
{
    int i;

    printf("1.1\n");
    for(i = 0;i < G->vexnum;i++)
    {
        printf("1\n");
        vexallarc(G,i);
    }
        
    return;
}
